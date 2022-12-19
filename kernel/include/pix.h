/** @file   pix.h
 *
 *  @brief  constants and prototypes for ws2812b "Neopixel" PWM driver
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 05 September 2022
 *  @author CMU 14-642
 *
 *  @note   UICR and NVMC are used to drive 3.3V GPIO output voltage (default is 1.8V)
**/

#ifndef _PIX_H_
#define _PIX_H_

#include <unistd.h>

#define UICR_REG0   (*((uint32_t*) 0x10001304))
#define NVMC_CONFIG (*((uint32_t*) 0x4001E504))
#define NVMC_READY  (*((uint32_t*) 0x4001E400))
#define PWM0 (uint32_t*)0x4001C000
#define PWM1 (uint32_t*)0x40021000
#define PWM2 (uint32_t*)0x40022000
#define PWM3 (uint32_t*)0x4002D000

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

void pix_init(); // initialise pwm

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

void pix_color_set(uint8_t r, uint8_t g, uint8_t b); // set the Neopixel to the color

#endif // _PIX_H_