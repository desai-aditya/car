/** @file   clock.c
 *
 *  @brief  Functions to initialize the clocks on board. Needed for radio drivers.
 *
 *  @date   Last modified 12 Dec 2022
 *
 *  @author CMU 14-642, Aditya Desai(adityade), Sindri Andrason(sandraso)
**/

#include<clock.h>

/**@brief Function for initialization oscillators.
 */
void clock_init()
{
    CLOCK_MMIO_t* clock = (CLOCK_MMIO_t*)CLOCK_BASE;
    
    /* Start 16 MHz crystal oscillator */
    clock->events_hfclkstarted= 0;
    clock->tasks_hfclkstart= 1;

    /* Wait for the external oscillator to start up */
    while (clock->events_hfclkstarted== 0)
    {
        // Do nothing.
    }

    /* Start low frequency crystal oscillator for app_timer(used by bsp)*/
    clock->lfclksrc= (CLOCK_LFCLKSRC_SRC_Xtal << CLOCK_LFCLKSRC_SRC_SHIFT);
    clock->events_lfclkstarted= 0;
    clock->tasks_lfclkstart= 1;

    while (clock->events_lfclkstarted== 0)
    {
        // Do nothing.
    }
}