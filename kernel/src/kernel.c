/** @file   kernel.c
 *
 *  @brief  starting point for kernel-space operations
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#include <arm.h>
#include<rtt.h>
#include<printk.h>
#include<mpu.h>
#include<gpio.h>
#include<adc.h>
#include<pix.h>
#include<i2c.h>
#include<timer.h>

/** here we have the different regions from the linker script
 * 
 * User code : 16kB - __user_text_start to __user_text_end
 * user read-only data : 2kB - __user_rodata_start to __user_rodata_end
 * User data : 1kB - __user_data_start to __user_data_end
 * User BSS : 1kB - __user_bss_start to __user_bss_end
 * User heap - 8kB - __heap_base to __heap_limit
 * Main thread user stack : 2kB - __psp_stack_limit to __psp_stack_base
 * 
 * */

extern void enter_user_mode();
extern char* __user_text_start;
extern char* __user_text_end;
extern char* __user_rodata_start;
extern char* __user_rodata_end;
extern char* __user_data_start;
extern char* __user_data_end;
extern char* __user_bss_start;
extern char* __user_bss_end;
extern char* __heap_base;
extern char* __heap_limit;
extern char* __psp_stack_limit;
extern char* __psp_stack_base;
extern char* __kernel_text_start;
extern char* __isr_vector_start;
extern char* __svc_stub_start;
extern char* __msp_stack_limit;


int kernel_main() {
    init_align_prio();          // <-- do not remove

    // enter_user_mode();
    pix_init();

    rtt_init(); // intitialise rtt

    // enable memory protection
    mpu_init();

    // enable user sw and reset

    enable_user_sw_and_reset();

    gpio_init(0,26,MODE_OUTPUT,OUTPUT_S0S1,PUPD_PULL_UP); //MD1, AIN1 - D9
    gpio_init(0,7,MODE_OUTPUT,OUTPUT_S0S1,PUPD_PULL_UP); //MD1, BIN2 - D6

    gpio_init(0,8,MODE_OUTPUT,OUTPUT_S0S1,PUPD_PULL_UP); //MD2, AIN1 - D12 connected to BIN1
    gpio_init(1,8,MODE_OUTPUT,OUTPUT_S0S1,PUPD_PULL_UP); //MD2, AIN2 - D5 connected to BIN2

    gpio_init(1, 15, MODE_OUTPUT, OUTPUT_S0S1, PUPD_NONE); //LED1
    gpio_init(1, 10, MODE_OUTPUT, OUTPUT_S0S1, PUPD_NONE); //LED2

    pwm_init();

    gpio_set(1,10);
    gpio_clr(1,15);

    // uint8_t pixel = 0;

    // Enable User code region
    breakpoint();
    
    if(mm_region_enable(0, (void*)&__svc_stub_start, mm_log2ceil_size(16384U) , 1, 1)) {
        printk("Error in enabling mem region %p\n", (void*)&__svc_stub_start);
    }

    if(mm_region_enable(1, (void*)&__user_rodata_start, mm_log2ceil_size(2048U) , 0, 1)) {
        printk("Error in enabling mem region %p\n", (void*)&__user_rodata_start);
    }

    if(mm_region_enable(2, (void*)&__user_data_start, mm_log2ceil_size(1024U) , 0, 1)) {
        printk("Error in enabling mem region %p\n", (void*)&__user_data_start);
    }

    if(mm_region_enable(3, (void*)&__user_bss_start, mm_log2ceil_size(1024U) , 0, 1)) {
        printk("Error in enabling the mem region %p\n", (void*)&__user_bss_start);
    }

    if(mm_region_enable(4, (void*)&__heap_base, mm_log2ceil_size(8192U) , 0, 1)) {
        printk("Error in enabling mem region %p\n", (void*)&__heap_base);
    }

    if(mm_region_enable(5, (void*)&__psp_stack_limit, mm_log2ceil_size(2048U) , 0, 1)){
        printk("Error in enabling mem region %p\n", (void*)&__psp_stack_limit);
    }
    
    if(mm_region_enable(7, (void*)&__msp_stack_limit, mm_log2ceil_size(2048U) , 0, 1)){
        printk("Error in enabling mem region %p\n", (void*)&__msp_stack_limit);
    }

    
    

    // enter user mode main function after handshake 
    enter_user_mode();
    
    BUSY_LOOP(1);
    return 0;
}


