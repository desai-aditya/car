/** @file   svc_stubs.S
 *
 *  @brief  Stub functions for 14642 syscalls
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 14 October 2022
 *  @author CMU 14-642
**/

.cpu cortex-m4
.syntax unified
.section .svc_stub
.thumb

#include "../../kernel/include/svc_num.h"

.global _sbrk
_sbrk:
  svc #0x00
  bx lr

.global _write
_write:
  svc #0x01
  bx lr

.global _fstat
_fstat:
  svc #3
  bx lr

.global _isatty
_isatty:
  svc #4
  bx lr

.global _lseek
_lseek:
  svc #5
  bx lr

.global _read
_read:
  svc #0x06
  bx lr

.global _getpid
_getpid:
  mov r0, #1
  bx lr
  
.global _exit
_exit:
  @bkpt
  svc #0x07
  bx lr

.global thread_init
thread_init:
  @bkpt
  svc #9
  bx lr

.global thread_create
thread_create:
  @bkpt
  svc #10
  bx lr

.global thread_kill
thread_kill:
  bkpt
  @svc #11

.global scheduler_start
scheduler_start:
  @bkpt
  svc #18
  bx lr

.global mutex_init
mutex_init:
  svc #13
  bx lr

.global mutex_lock
mutex_lock:
  svc #14
  bx lr

.global mutex_unlock
mutex_unlock:
  svc #15
  bx lr

.global wait_until_next_period
wait_until_next_period:
  svc #16
  @bx lr

.global get_time
get_time:

  svc #17
  bx lr

.global get_priority
get_priority:
  svc #19
  bx lr

.global thread_time
thread_time:
  svc #20
  bx lr
  bkpt

.global delay_ms
delay_ms:
  bkpt
  
.global lux_read
lux_read:
  bkpt

.global pix_set
pix_set:
  svc #24
  bx lr
  

.global read_lux
read_lux:
  svc #26
  bx lr

.global read_mic
read_mic:
  svc #25
  bx lr

.global led_glow
led_glow:
  svc #27
  bx lr

.global forward
forward:
  svc #32
  bx lr

.global backward
backward:
  svc #33
  bx lr

.global left
left:
  svc #34
  bx lr

.global right
right:
  svc #35
  bx lr

.global stop
stop:
  svc #36
  bx lr

/* the following stubs do not need to be implemented */

.global _start
_start:
  bkpt

.global _close
_close:
  bkpt
  
.global _kill
_kill:
  bkpt
  
.global _gettimeofday
_gettimeofday:
  bkpt

.global _times
_times:
  bkpt

.global color_set
color_set:
  svc #50
  bx lr


.global send_radio_packet 
send_radio_packet:
  svc #51
  bx lr

.global recv_radio_packet 
recv_radio_packet:
  svc #52
  bx lr
