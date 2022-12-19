.cpu cortex-m4
.syntax unified
.thumb

.section .text

.thumb_func
.global enter_user_mode
enter_user_mode:
@bkpt
LDR r1, =__psp_stack_base
MSR psp, r1      
MOV r1, #3
MSR control, r1
@isb
bl launch_main


.thumb_func
.global default_idle
default_idle:
wfi
b default_idle

.thumb_func
.global thread_kill_working
thread_kill_working:
svc #11
bx lr
  
