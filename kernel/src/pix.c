/** @file   pix.c
 *
 *  @brief  pwm driver for ws2812b "neopixel"
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 20 September 2022
 *  @author CMU 14-642
**/

#include <arm.h>
#include <pix.h>
#include <gpio.h>
#include<printk.h>

gpio_t* neo;
pwm_t* neo_pulse;
uint16_t sequence[24];

/** 
 * 
 * @brief This function is used to initialise the neopixel module. It uses the 
 * PWM peripheral present on our board.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */


void pix_init() {
    /*
     * the neopixel needs to have input voltage of 3.3V
     * UICR and NVMC details are set here based on values in pix.h
     */
    if(UICR_REG0 != 5UL) {
        NVMC_CONFIG = 1UL;
        BUSY_LOOP(!NVMC_READY);
        UICR_REG0 = 5UL;
        NVMC_CONFIG = 0UL;
        BUSY_LOOP(!NVMC_READY);
    }
    neo = (gpio_t*)GPIO1;

    gpio_init(0, 16, MODE_OUTPUT, OUTPUT_S0H1, PUPD_NONE); // gpio init for neopixel

    neo_pulse = (pwm_t*)PWM1;    // use PWM channel 0

    neo_pulse->mode = 0; // Use UP counter
    neo_pulse->countertop = 20; // For now, using 16MHz clock so, count upto 20 ticks
    neo_pulse->prescaler = 0; // Use 16MHz clock
    neo_pulse->decoder = 0; // use the individual mode, since we have only 1 24-bit sequence
    neo_pulse->loop = 0;  // loop is disabled, one sequence played
    neo_pulse->seq0.cnt = 24; // 24 duty cycles to be generated
    neo_pulse->seq0.refresh = 0; // new PWM perioud every duty cycle
    neo_pulse->seq0.enddelay = 960; // add 60us delay after every PWM sequence 
    neo_pulse->pselout[0] = 0x10; // Port 0, pin 16, alternate value = 0x7fffffd0
    neo_pulse->enable = 1; // enable the PWM module
}

/**
 * 
 * @brief This function is used to set a colour for the neopixel. It takes in the 
 * pixel values of the three primary colours and sets the colour of the neopixel
 * accordingly.
 * 
 * @params[in] r value for red
 * @params[in] g value for green
 * @params[in] b value for blue
 * 
 * @return none
 * 
 */


void pix_color_set(uint8_t r, uint8_t g, uint8_t b) {
    // clear events 
    neo_pulse->events_stopped = 0;
    neo_pulse->events_seqstarted[0] = 0;
    neo_pulse->events_seqstarted[1] = 0;
    neo_pulse->events_seqend[0] = 0;
    neo_pulse->events_seqend[1] = 0;
    neo_pulse->events_pwmperiodend = 0;
    neo_pulse->events_loopsdone = 0;


    for(int i = 0; i < 24; i++) {
        sequence[i] = 0;
    }

    int i = 0;
    int p = 0;

    for(i = 0; i < 8; i++) {
        if(b & 0x01) {
            sequence[p] = 14;
        }
        else {
            sequence[p] = 7;
        }
        sequence[p] |= (1<<15);
        p++;
        b >>= 1;
    }

    for(i = 0; i < 8; i++) {             
        if(r & 0x01) {
            sequence[p] = 14;
        }
        else {
            sequence[p] = 7;
        }
        sequence[p] |= (1<<15);
        p++;
        r >>= 1;
    }

    for(i = 0; i < 8; i++) {             
        if(g & 0x01) {
            sequence[p] = 14;
        }
        else {
            sequence[p] = 7;
        }
        sequence[p] |= (1<<15);
        p++;
        g >>= 1;
    }

    neo_pulse->seq0.ptr = sequence; // Address in RAM

    neo_pulse->tasks_seqstart[0] = 1; // start the PWM sequence

    while(!neo_pulse->events_seqstarted); // wait for the start event 

    neo_pulse->tasks_seqstart[0] = 0; 
    
    while(!neo_pulse->events_seqend[0]);

    neo_pulse->tasks_stop = 1;

    while(!neo_pulse->events_stopped); // wait for stopped event 

    neo_pulse->tasks_stop = 0;

    // clear events 
    neo_pulse->events_stopped = 0;
    neo_pulse->events_seqstarted[0] = 0;
    neo_pulse->events_seqstarted[1] = 0;
    neo_pulse->events_seqend[0] = 0;
    neo_pulse->events_seqend[1] = 0;
    neo_pulse->events_pwmperiodend = 0;
    neo_pulse->events_loopsdone = 0;
}