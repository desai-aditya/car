/** @file   timer.c
 *
 *  @brief  timer implementations for systick timer
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#include <timer.h>
#include <unistd.h>
#include<arm.h>

#define PROC_FREQ 64000000

volatile systick_t* timer = (systick_t*)0xE000E010;

/**
 * 
 * @brief function is used to start the systick and allow it to generate interrupts at the 
 * frequency specified by the user.
 * 
 * @param[in] frequency at which the timer needs to generate interrupts
 * 
 * @return does not return
 * 
 **/

void systick_start(int frequency) {
    // breakpoint();
    (void)frequency;
    timer->SYST_CSR |= (CLKSRC | TICKINT);
    timer->SYST_CSR |= ENABLE;
    timer->SYST_RVR = PROC_FREQ / frequency;
    // timer->SYST_RVR = 0x00FFFFFF;
    timer->SYST_CVR = 0;
}

/**
 * 
 * @brief This function is used to stop the systick from triggering interrupts. It disables the systick.
 * This will be called right before the system terminates.
 * 
 * @param[in] none
 * 
 * @return no return values
 * 
 **/

void systick_stop() {
	timer->SYST_RVR = 0;
	timer->SYST_CSR &= (~ENABLE);
	timer->SYST_CVR = 0;
}