/** @file   mpu.c
 *
 *  @brief  implementation of memory protection for lab 4
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#include <arm.h>
#include <mpu.h>
#include <printk.h>
#include <syscall.h>
#include <syscall_thread.h>
#include <unistd.h>
#include<timer.h>

/** @brief mpu control register */
#define MPU_CTRL *((uint32_t*)0xE000ED94)

uint32_t* mpu_control_register; 
/** @brief mpu region number register */
#define MPU_RNR *((uint32_t*)0xE000ED98) // this indicates the region accessed by MPU_RBAR and MPU_RASR
// RNR is an 8 bit space

//Normally, software must write the required region number to MPU_RNR to select the required memory region,
//before accessing MPU_RBAR or MPU_RASR. However, the MPU_RBAR.VALID bit gives an alternative way of
// writing to MPU_RBAR to update a region base address without first writing the region number to MPU_RNR
// void MemoryManagement_Handler();

/** @brief mpu region base address register */
#define MPU_RBAR *((uint32_t*)0xE000ED9C)
/** @brief mpu region attribute and size register */
#define MPU_RASR *((uint32_t*)0xE000EDA0)

/** @brief MPU CTRL register flags */
//@{
#define MPU_CTRL_ENABLE_BG  (1 << 2)
#define MPU_CTRL_ENABLE     (1 << 0)
//@}

/** @brief MPU RNR register flags */
//@{
#define MPU_RNR_REGION      (0xFF)
#define MPU_RNR_REGION_MAX  (7)
//@}

/** @brief MPU RASR register masks */
//@{
#define MPU_RASR_XN         (1 << 28)
#define MPU_RASR_SIZE       (0x3E)
#define MPU_RASR_ENABLE     (1 << 0)
#define MPU_RASR_USER_RO    (2 << 24)
#define MPU_RASR_USER_RW    (3 << 24)
//@}

/** @brief system handler control and state register */
#define SCB_SHCRS *((uint32_t*)0xE000ED24)
/** @brief configurable fault status register */
#define SCB_CFSR *((uint32_t*)0xE000ED28)
/** @brief mem mgmt fault address register */
#define SCB_MMFAR *((uint32_t*)0xE000ED34)

/** @brief SCB_SHCRS mem mgmt fault enable bit */
#define SHCRS_MEMFAULTENA   (1 << 16)

/** @brief stacking error */
#define SCB_CFSR_STKERR     (1 << 4)
/** @brief unstacking error */
#define SCB_CFSR_UNSTKERR   (1 << 3)
/** @brief data access error */
#define SCB_CFSR_DACCVIOL   (1 << 1)
/** @brief instruction access error */
#define SCB_CFSR_IACCVIOL   (1 << 0)
/** @brief indicates the MMFAR is valid */
#define SCB_CFSR_MMFARVALID (1 << 7)

extern void* thread_kill;
extern void thread_kill_working();
extern void sys_thread_kill();
extern void default_idle();
void default_idle_helper();

extern tcb_t TCB[16];
extern volatile uint32_t currentRunningThreadID;

/**
 * 
 * @brief This function is the memory management handler which handles any memory faults in the system. It 
 * takes in a pointer to the psp or the interrupt stack frame where the fault occured.
 * 
 * @param pointer to the process stack pointer
 * 
 * @return does not return
 * 
 **/

void mm_c_handler(void *psp) {
    // Control register's bit 0 and bit 1 to be enabled, enable MPU and mem faults

    int status = SCB_CFSR & 0xFF; // the CFSR contains individual bits which indicate errors

    interrupt_stack_frame* ptr = (interrupt_stack_frame*)psp;

    if((currentRunningThreadID != 15) && (status & SCB_CFSR_DACCVIOL)) {
        // printk("Data access violation\n");
        sys_thread_kill();
        return;
    }
    
    // unrecoverable stack overflow

    if (currentRunningThreadID == 15) {
        ptr->pc = &default_idle_helper;
        return;
    }

    if (status & SCB_CFSR_MMFARVALID) {
        if(((void*)SCB_MMFAR >= TCB[currentRunningThreadID].user_stack_end) 
        || ((void*)SCB_MMFAR < TCB[currentRunningThreadID].user_stack_start)
            || ((void*)SCB_MMFAR >= TCB[currentRunningThreadID].kernel_stack_end)
            || ((void*)SCB_MMFAR < TCB[currentRunningThreadID].kernel_stack_start)) {
            printk("stack overflow --> aborting\n");
            printk("Current running thread is %lu\n", currentRunningThreadID);
            printk("Faulting Address = %x\n", SCB_MMFAR);
            systick_stop();
            sys_exit(-1);
        }
    }

    // Other errors can be recovered from by killing the offending thread.
    // Standard thread killing rules apply. You should halt if the thread
    // is the main or idle thread, but otherwise up to you. Manually set
    // the pc? Call a function? Context swap? TODO

    if((currentRunningThreadID == 0) || (currentRunningThreadID == 15)) {
        // this means that it is the main thread or the idle thread
        //printk("Main thread or idle thread is misbehaving %d, ptr->pc = %x\n", currentRunningThreadID, ptr->pc);
        // halt
        // if (currentRunningThreadID == 15) ptr->pc = &default_idle_helper;
        return;
    }
    else {
        // anything other than main or idle, kill it
        sys_thread_kill();
        return;
    }

    if(status & SCB_CFSR_STKERR) printk("Stacking Error\n");
    if(status & SCB_CFSR_UNSTKERR) printk("Unstacking Error\n");
    if(status & SCB_CFSR_DACCVIOL) printk("Data access violation\n");
    if(status & SCB_CFSR_IACCVIOL) printk("Instruction access violation\n");
    if(status & SCB_CFSR_MMFARVALID) printk("Faulting Address = %x\n", SCB_MMFAR);

    // (void)psp;
}



/** @brief  enables an aligned memory protection region
 *
 *  @param  region_number       region number to enable
 *  @param  base_address        region's base address
 *  @param  size_log2           log[2] of the region's size
 *  @param  exec_never          indicator if region is NOT user-executable
 *  @param  user_write_access   indicator if region is user-writable
 *
 *  @return 0 if successful, -1 on failure
 */
int mm_region_enable(uint32_t region_number, void* base_address, uint8_t size_log2, int execute, int user_write_access) {
    //printk("Entered region enable with base address %x and region number %lu and log %u\n", base_address, region_number, size_log2);
    if(region_number > MPU_RNR_REGION_MAX) {
        printk("Invalid region number\n");
        return -1;
    }

    if((uint32_t)base_address & ((1 << size_log2) - 1)) {
        printk("Misaligned region\n");
        return -1;
    }

    if(size_log2 < 5) {
        printk("Region too small %d\n", region_number);
        return -1;
    }

    MPU_RNR = region_number & MPU_RNR_REGION;
    MPU_RBAR = (uint32_t)base_address;

    uint32_t size = ((size_log2 - 1) << 1) & MPU_RASR_SIZE;
    uint32_t ap = user_write_access ? MPU_RASR_USER_RW : MPU_RASR_USER_RO;
    uint32_t xn = execute ? 0 : MPU_RASR_XN;

    MPU_RASR = size | ap | xn | MPU_RASR_ENABLE;

    // printk("Enabled %x\n", MPU_RASR);

    return 0;
}

/**
 * @brief  Disables a memory protection region.
 *
 * @param  region_number      The region number to disable.
 */
void mm_region_disable(uint32_t region_number) {
    //printk("disabling region %d\n", region_number);
    MPU_RNR = region_number & MPU_RNR_REGION;
    MPU_RASR &= ~MPU_RASR_ENABLE;
}

/**
 * @brief  Returns ceiling (log_2 n).
 */
uint32_t mm_log2ceil_size(uint32_t n) {
    uint32_t ret = 0;
    while(n > (1U << ret)) {
        ret++;
    }
    return ret;
}

/**
 * 
 * @brief This function performs the necessary handshaking which is needed to initialse and enable
 * the MPU in the system. It is defined in kernel main.
 * 
 * @param[in] no input paramters
 * 
 * @return does not return 
 * 
 **/

void mpu_init() {
    // enable mem protection in SCB
    set_enable_memfault();
    MPU_CTRL |= (MPU_CTRL_ENABLE | MPU_CTRL_ENABLE_BG);
}
