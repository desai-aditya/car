/** @file   syscall.c
 *
 *  @brief  base syscall implementations for Lab 4 tasks
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#include <syscall.h>
#include <unistd.h>
#include<rtt.h>
#include<printk.h>
#include<arm.h>

extern uint32_t* __heap_base;
extern uint32_t* __heap_limit;

uint32_t offset_from_heap_base = 0;

uint32_t* program_brk;

/**
 * 
 * @brief This function is the syscall implementation of sysbrk. This is used to expand
 * the heap memory of the system to allocate more space that the user demands.
 * 
 * @params[in] size in bytes, represents the amount in bytes by which the heap should be eexpanded
 * @params[out] none
 * 
 * @return val void pointer to the location of the system break
 * 
 **/

void* sys_sbrk(int incr) {
    void* result = NULL;
    program_brk = (uint32_t*) ((char*)(&(__heap_base)) + offset_from_heap_base); // initialse program break

    if (((uint32_t*)((char*)program_brk + incr)) > (uint32_t*)(&(__heap_limit))) {
        return (void*)-1;
    }
    
    result = (void*)program_brk;
    offset_from_heap_base += incr;

    return result;
}

/**
 * 
 * @brief This function is the syscall implementation of the read function. This returns the
 * number of bytes it read from the console. This uses rtt to read data from the console.
 * 
 * @params[in] file - file descriptor from which data is read
 * @params[in] ptr - pointer to the buffer into which data has to be read
 * @params[in] - len is the number of bytes to be read
 * 
 * @params[out] returns the number of bytes it read from the input. Returns -1 on error
 * 
 * 
 **/

int sys_read(int file, char* ptr, int len) {
    (void)file;
    int available_bytes = rtt_has_data(0);

    if(available_bytes != 0 && available_bytes < len) {
        available_bytes = rtt_read(0, ptr, available_bytes);
    }
    return available_bytes;
}

/**
 * 
 * @brief This function is the syscall implementation of the write function. This returns the 
 * number of bytes it wrote to the file or console. This uses rtt to write data into the file
 * or console.
 * 
 * @params[in] file - file descriptor to which data is written
 * @params[in] ptr - pointer to the buffer into which data has to be written 
 * @params[in] - len is the number of bytes to be written
 * 
 * @params[out] returns the number of bytes it wrote to the output. Returns -1 on error
 * 
 **/

int sys_write(int file, char* ptr, int len) {
    (void)file;
    int written_bytes = rtt_write(0, ptr, len);

    if(written_bytes != len) {
        return -1;
    }
    return written_bytes;
}

/**
 * 
 * @brief This is the system call implementation of the function exit. It takes in the error code
 * status of exit. If the error code is 0, it means the program returned successfully and hence no erros
 * occurred. If there was a non-zero status code, then it sets the on-board led to red and exits printing
 * a message about the error code.
 * Later, it disables the interrupts and sleeps. It does not return to the program.
 * 
 * @params[in] status - status code of the error message
 * @params[out] non
 * 
 **/

void sys_exit(int status) {
    if (status == 0) {
        printk("Exiting with status code %d\n", status);
        disable_interrupts();
        wait_for_interrupt();
    }
    else {
        printk("Exiting program with status %d\n", status);
        // disable interrupts and then sleep
        disable_interrupts();
        while(1) {
            wait_for_interrupt();
        }
    }
}


/* syscalls for custom user projects */

void sys_delay_ms(uint32_t ms) {
    (void)ms;
}

uint16_t sys_lux_read() {
    return 0;
}

void sys_pix_set(uint8_t red, uint8_t green, uint8_t blue) {
    (void)red;
    (void)green;
    (void)blue;
}
