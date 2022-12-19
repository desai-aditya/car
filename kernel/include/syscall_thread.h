/** @file   syscall_thread.h
 *
 *  @brief  system calls to support thread library for lab 4
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#ifndef _SYSCALL_THREAD_H_
#define _SYSCALL_THREAD_H_

#include <unistd.h>
#include<syscall_mutex.h>
#include<mpu.h>

/** @struct interrupt_stack_frame
 *  @brief stack frame upon interrupt/exception
 */
typedef struct {
    uint32_t r0;   /** @brief reg r0 value */
    uint32_t r1;   /** @brief reg r1 value */
    uint32_t r2;   /** @brief reg r2 value */
    uint32_t r3;   /** @brief reg r3 value */
    uint32_t r12;  /** @brief reg r12 value */
    void* lr;   /** @brief reg lr value */
    void* pc;   /** @brief reg pc value */
    uint32_t xPSR; /** @brief reg xPSR value */
} interrupt_stack_frame;

/**
 * 
 * structure to store the global TCB
 * 
 **/

typedef enum {
    STOPPED = 0, /** task is in STOPPED state */
    WAITING = 1, /** task is in WAITING state */
    RUNNABLE = 2, /** task is in RUNNABLE state */
    RUNNING = 3, /** task is in RUNNING state */
    BLOCKED = 4 /** task is in BLOCKED state */
} state_t;

/**
 * 
 * this indicates a structure which stores all the necessary contents on the psp register.
 * Helpful in saving context 
 * 
 **/

typedef struct msp_stack_frame {
    interrupt_stack_frame* psp; /** interrupt stack frame of the psp */
    uint32_t r4; /** r4 register on interrupt stack frame */
    uint32_t r5; /** r5 register on interrupt stack frame */
    uint32_t r6; /** r6 register on interrupt stack frame */
    uint32_t r7; /** r7 register on interrupt stack frame */
    uint32_t r8; /** r8 register on interrupt stack frame */
    uint32_t r9; /** r9 register on interrupt stack frame */
    uint32_t r10; /** r10 register on interrupt stack frame */
    uint32_t r11; /** r11 register on interrupt stack frame */
    void* lr; /** lr register on interrupt stack frame */
} msp_stack_frame_t;

/**
 * 
 * this indicates a structure which is used to store the context of the TCB for each thread
 * that is run on the system
 * 
 **/


typedef struct tcb {
    msp_stack_frame_t* msp; /** pointer to the msp stack frame */
    uint32_t C; /** WCET of the the task */
    uint32_t T; /** period of the task */
    uint32_t prio; /** priority of the task */
    void* fn; /** pointer to the function */
    void* vargp; /** arguments to the thread */
    uint32_t svc_status; /** svc status of the thread */
    uint32_t running_time; /** current running time of the task */
    state_t state; /** state of the task */
    void* kernel_stack_start; /** starting of the kernel stack */
    void* kernel_stack_end; /** ending of the kernel stack */
    void* user_stack_start; /** starting of the user stack */
    void* user_stack_end; /** ending of the kernel stack */
    uint32_t execution_time; /** current execution time of the task */
    uint8_t static_priority; /** static priority of the task */
    uint8_t dynamic_priority; /** dynamic priority of the task */
    uint32_t time_since_scheduler_start; /** cumulative time since the scheduler started */
    struct tcb*  next; /** pointer to the nest tcb in the linked list */
    struct kmutex_t* acquired_mutexes; /** linked list of acquired mutexes */
} tcb_t;


/** @brief initialize thread switching
 *  @note  must be called before creating threads or scheduling
 *
 *  @param max_threads      max number of threads to be created
 *  @param stack_size       stack size in words of all created stacks
 *  @param idle_fn          function pointer for idle thread, NULL for default
 *  @param mem_protect      mpu mode, either PER_THREAD or KERNEL_ONLY
 *  @param max_mutexes      max number of mutexes supported
 *
 *  @return     0 for success, -1 for failure
 */
int sys_thread_init(uint32_t max_threads, uint32_t stack_sizes, void* idle_fn, mpu_mode mem_protect, uint32_t max_mutexes);

/** @brief create a new thread as specified, if UB allows
 *
 *  @param fn       thread function pointer
 *  @param prio     thread priority, with 0 being highest
 *  @param C        execution time (scheduler ticks)
 *  @param T        task period (scheduler ticks)
 *  @param vargp    thread function argument
 *
 *  @return     0 for success, -1 for failure
 */
int sys_thread_create(void* fn, uint32_t prio, uint32_t C, uint32_t T, void* vargp);

/** @brief tell the kernel to start running threads using Systick
 *  @note  returns only after all threads complete or are killed
 *
 *  @param frequency  frequncy of context switches in Hz
 *
 *  @return     0 for success, -1 for failure
 */
int sys_scheduler_start(uint32_t frequency);

/** @brief get the current time in ticks */
uint32_t sys_get_time();

/** @brief get the dynamic priority of the running thread */
uint32_t sys_get_priority();

/** @brief get the total elapsed time for the running thread */
uint32_t sys_thread_time();

/** @brief deschedule thread and wait until next turn */
void sys_wait_until_next_period();

/** @brief kill the running thread
 *
 *  @note  locks if main or idle thread is running or thread holds a mutex
 *
 *  @return does not return
 */
void sys_thread_kill();

/**
 * 
 * @brief RMS scheduler which is used to find the highest priority task based on the time period
 * of each task.
 * 
 * @param[in] none
 * 
 * @return returns the ID of the thread 
 * 
 **/

uint32_t RMS();

/**
 * 
 * @brief Used to perform the UB test and outputs whether the task set is schedulable or not
 * 
 * @param[in] Number of threads in the system currently (includes the new thread to be scheduled)
 * @param[in] WCET of the task
 * @param[in] Time period of the task 
 * 
 * */


int UB_test_RMS(uint32_t no_threads, uint32_t C, uint32_t T);

/**
 * 
 * @brief This function is used to read the lux sensor. This is a system call which gets
 * called when the stub for the specific user function is pressed. 
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_read_lux();

/**
 * 
 * @brief This function is used to read the microphone. This is a system call which gets
 * called when the stub for the specific user function is pressed. 
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_read_mic();

/**
 * 
 * @brief This function is system call which is used to glow the led. This is called
 * via a stub from the user space function.
 * 
 * @param[in] If the user gives 0 then the leds turn off. Else, then remain on.
 * 
 * @return none
 * 
 */

void sys_glow_led(int on);

/**
 * 
 * @brief This function is used to move the car forward. This is the system call that does
 * the propulsion. It calls another pwm helper function to actuate the motors.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_move_forward(void);

/**
 * 
 * @brief This function is used to move the car backward. This is the system call that does
 * the propulsion. It calls another pwm helper function to actuate the motors.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_move_backward(void);

/**
 * 
 * @brief This function is used to move the car left. This is the system call that does
 * the propulsion. It calls another pwm helper function to actuate the motors.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_turn_left(void);

/**
 * 
 * @brief This function is used to move the car right. This is the system call that does
 * the propulsion. It calls another pwm helper function to actuate the motors.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_turn_right(void);

/**
 * 
 * @brief This function is used to stop the car. It calls another pwm helper function to stop the motors.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void sys_stop_car(void);

#endif /* _SYSCALL_THREAD_H_ */
