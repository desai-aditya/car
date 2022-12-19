/** @file   visualizer.h
 *
 *  @brief  function prototypes for audio-to-LED visualizer
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 20 September 2022
 *  @author CMU 14-642
**/
#include <unistd.h>

#ifndef _VISUALIZER_H_
#define _VISUALIZER_H_

/**
 * 
 * This function is responsible for visualising color on the Neopixel. This makes
 * use of FFT algorithms to fine tune the brightness of the LED.
 * 
 * @params[in] on to indicate whether to change the brightness of the pixel or
 * turn it off
 * 
 * @return none
 * 
 */


int visualizer_color_info(int on);

#endif /* _VISUALIZER_H_ */