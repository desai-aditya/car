#include <visualiser.h>
#include <unistd.h>
#include <rfft.h>
#include <printk.h>
#include<adc.h>
#include<pix.h>

#define R_LIM   (85)
#define G_LIM   (170)
#define RGB_MAX (255)
#define SCALE_FACT (4)

int16_t input[FFT_SIZE];     // FFT_SIZE real values
int16_t output[FFT_SIZE*2];  // FFT_SIZE complex (real,imag) values
static int16_t mags[FFT_SIZE];      // fft output magnitudes
uint8_t r, g, b;
// static int ind = 0;

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

int visualizer_color_info(int on) {

    if(!on) {
        pix_color_set(0,0,0);
        return 0;
    }
    adc_read_pin();
    
    uint32_t r_avg = 0, g_avg = 0, b_avg = 0;
    uint16_t i;    
    rfft(input, output);
    rfft_abs(output, mags, FFT_SIZE);
    
    r_avg = g_avg = b_avg = 0;
    for(i = 2; i < R_LIM; i++)
        r_avg += mags[i];
    for(; i < G_LIM; i++)
        g_avg += mags[i];
    for(; i < FFT_SIZE; i++)
        b_avg += mags[i];

    r_avg >>= SCALE_FACT;
    g_avg >>= SCALE_FACT;
    b_avg >>= SCALE_FACT;
    r = r_avg > RGB_MAX ? RGB_MAX : r_avg;
    g = g_avg > RGB_MAX ? RGB_MAX : g_avg;
    b = b_avg > RGB_MAX ? RGB_MAX : b_avg;
    
    pix_color_set(r,g,b); // set the neopixel
    //printk("r = %u g = %u b = %u\n",r,g,b);
    return 0;
}
