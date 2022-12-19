/** @file   svc_handler.c
 *
 *  @brief  implementation of basic and custom SVC calls
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#include <arm.h>
#include <printk.h>
#include <svc_num.h>
#include <unistd.h>
#include <syscall.h>
#include <mpu.h>
#include<pix.h>
#include <syscall_thread.h>
#include <syscall_mutex.h>
#include<visualiser.h>
#include<radio.h>

void svc_c_handler(void* stk_ptr) {
    //breakpoint();

    uint8_t svc_num = -1;
    uint32_t* pc_ptr; 

    interrupt_stack_frame* stack;

    stack = (interrupt_stack_frame*)stk_ptr;
    uint32_t* pc = (uint32_t*)stack->pc;
    pc_ptr = (uint32_t*)((char*)pc - 2);
    svc_num = (uint8_t)((*pc_ptr) & ((uint32_t)0xff));

    int len;
    int file;
    char* str;
    int incr;
    void* new_progbrk;


    switch(svc_num) {

        case SVC_EXIT:
        sys_exit(stack->r0);
        break;

        case SVC_READ:
        file = (int)stack->r0;
        str = (char*)stack->r1;
        len = (int)stack->r2;

        len = sys_read(file, str, len); 
        stack->r0 = len;
        break;

        case SVC_WRITE:

        file = (int)stack->r0;
        str = (char*)stack->r1;
        len = (int)stack->r2;

        len = sys_write(file, str, len);
        stack->r0 = (uint32_t)len;
        break;

        case SVC_SBRK:

        incr = (int)stack->r0;

        new_progbrk = sys_sbrk(incr);

        stack->r0 = (uint32_t)new_progbrk;
        break;

        case SVC_FSTAT:

        stack->r0 = -1;
        break;

        case SVC_ISATTY:
        stack->r0 = 1;
        break;

        case SVC_LSEEK:
        stack->r0 = -1;
        break;

        case SVC_THR_INIT :
        {
        // breakpoint();
        uint32_t max_threads = stack->r0;
        uint32_t stack_size = stack->r1;
        void* idle_fn = (void*)stack->r2;
        mpu_mode memory_protection = (mpu_mode)stack->r3;
        uint32_t max_mutexes = (uint32_t)(*((char*)stk_ptr + 0x20));

        stack->r0 = sys_thread_init(max_threads, stack_size, idle_fn, memory_protection, max_mutexes);

        break;
        }

        case SVC_THR_CREATE: 
        {
            
            // SVC interrupt generated
            // in system mode
            // sp = msp

            void* fn = (void*)stack->r0;
            uint32_t prio = stack->r1;
            uint32_t C = stack->r2;
            uint32_t T = stack->r3;
            void* vargp = (void*)(*(uint32_t*)((char*)stk_ptr + 0x20));
            // printk("Argument in thread create is %p\n", vargp);
            // breakpoint();
            stack->r0 = sys_thread_create(fn, prio, C, T, vargp);

            break;
        }

        case SVC_SCHD_START:
        {
            // breakpoint();
            
            // start systick with input frequency
            stack->r0 = sys_scheduler_start(stack->r0);
            break;
        }
        
        case SVC_PRIORITY:
        {
            stack->r0 = sys_get_priority();
            break;
        }
        case SVC_WAIT:
            sys_wait_until_next_period();
            break;
        case SVC_TIME:
        // breakpoint();
            stack->r0 = sys_get_time();
            break;
        
        case SVC_THR_TIME:
            stack->r0 = sys_thread_time();
            break;

        case SVC_THR_KILL:
            sys_thread_kill();
            break;
        case SVC_MUT_INIT:
            stack->r0 = (uint32_t)sys_mutex_init((uint32_t)stack->r0);
            break;
        case SVC_MUT_LOK:
            sys_mutex_lock((kmutex_t*)stack->r0);
            break;
        case SVC_MUT_ULK:
            sys_mutex_unlock((kmutex_t*)stack->r0);
            break; 

        case READ_LUX:
            sys_read_lux();
            break;

        case READ_MIC:
            sys_read_mic();
            break;

        case SVC_PIX:
            // pix_color_set(stack->r0, stack->r1, stack->r2);
            visualizer_color_info(stack->r0);
            break;

        case GLOW_LED:
            sys_glow_led(stack->r0);
            break;

        case MOVE_FORWARD:
            sys_move_forward();
            break;

        case MOVE_BACKWARD:
            sys_move_backward();
            break;

        case TURN_LEFT:
            sys_turn_left();
            break;

        case TURN_RIGHT:
            sys_turn_right();
            break;

        case STOP_CAR:
            sys_stop_car();
            break;
        
        case COLOR_SET:
            pix_color_set(stack->r0, stack->r1, stack->r2);
            break;
        
        case SEND_PKT:
            sys_send_packet(stack->r0);
            break;
        
        case RECV_PKT:
            stack->r0 = sys_recv_packet((int32_t*)stack->r0,stack->r1);
            break;

        default:
            //printk("Not implemented, svc num %d\n", svc_num);
            //breakpoint();
            break;
    }
}
