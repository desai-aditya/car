/** @file   timer.h
 *
 *  @brief  function prototypes for systick timer
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 14 October 2022
 *  @author CMU 14-642
**/

#ifndef _TIMER_H_
#define _TIMER_H_

#include<arm.h>

#define CLKSRC 4 /** bit 2 set to enable system clock - 64MHz */
#define TICKINT 2 /** bit 1 set to enable SysTick interrupts */
#define ENABLE 1 /** bit 0 set to enable the SysTick Timer */
#define COUNTFLAG (1 << 16) /** bit 16 to check if the counter value has reached 0 */
#define COUNTFLAGMASK (1 << 16) /** mask to check if the counter had reached 0 */
#define MAXCNTVAL 0x00FFFFFF
/**
 * 
 * @brief This structure indicates the memory map of the region which will store the necessary
 * registers to manipulate the behavior of the systick timer.
 * 
 * It has the control status register, reload value register, current values register and the 
 * calibration value register for the systick
 * 
 **/


typedef struct sysTick {
    volatile uint32_t SYST_CSR; /** SysTick Control Status Register */
    volatile uint32_t SYST_RVR; /** SysTick Reload Value Register */
    volatile uint32_t SYST_CVR; /** SysTick Current Value Register */
    volatile uint32_t SYST_CALIB; /** SysTick Calibration Value Register */
} systick_t;

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



void systick_start();

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



void systick_stop();

void systick_delay(uint32_t ms);

#endif /* _TIMER_H_ */