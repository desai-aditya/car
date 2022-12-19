/** @file   adc.h
 *
 *  @brief  Prototypes for ADC initialization and read
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 05 September 2022
 *  @author CMU 14-642
**/
#ifndef _ADC_H_
#define _ADC_H_

#include <unistd.h>

#define ADC (uint32_t*)0x40007000
#define AIN0 1
#define RESOLUTION (uint32_t)0x02
#define ADC_EXCEPTION_NUMBER 7

typedef struct ch_config {
    uint32_t pselp; /** Positive channel selection */
    uint32_t pseln; /** Negative channel selection */
    uint32_t config; /** configuration register */
    uint32_t limit; /** limits set on the channel */
} channel_config_t;

typedef struct event_lim {
    volatile uint32_t limh; /** event to check for limit high */
    volatile uint32_t liml; /** event to check for limit low */
} event_limits_t;

typedef struct adc_config {
    uint32_t tasks_start; /** to trigger start task */
    uint32_t tasks_sample; /** to trigger sampling */
    uint32_t tasks_stop; /** to trigger stop task */
    uint32_t calibrate_offset; /** calibrate the offset of the ADC */
    char pad0[240]; /** additional padding between registers */
    volatile uint32_t events_started; /** event to indicate start */
    volatile uint32_t events_end; /** event to indicate end */
    volatile uint32_t events_done; /** event to indicate done status */
    volatile uint32_t events_resultdone; /* event to indicate result in RAM */
    volatile uint32_t events_calibrateddone; /** event to indicate ADC calibration done status */
    volatile uint32_t events_stopped; /** event to indicate that SAADC stopped */
    event_limits_t limits[8]; /** Array of limits struct for the 8 channels */
    char pad1[424]; /** additional padding between registers */
    uint32_t inten; /** register to enable interrupts */
    uint32_t intenset; /** enable interrupts for events */
    uint32_t intenclr; /** clear interrupts */
    char pad2[244]; /** additional padding between registers */
    uint32_t status; /** status of SAADC */
    char pad3[252]; /** additional padding between registers */
    uint32_t enable; /** enable SAADC */
    char pad4[12]; /** additional padding between registers */
    channel_config_t channel_configuration[8]; /** configuration for each channel */
    char pad5[96]; /** additional padding between registers */
    uint32_t resolution; /** resolution of the ADC */
    uint32_t oversample; /** take average of x samples */
    uint32_t samplerate; /** sampling rate of the ADC */
    char pad6[48]; /** additional padding between registers */
    volatile int16_t* resultptr; /** pointer to the result in RAM */
    volatile uint32_t result_maxcnt; /** max count of samples to be taken */
    volatile uint32_t result_amount; /** count of the samples taken */
} adc_t;

/**
 *
 * This function initialise the ADC. The instance of the ADC is defined as a struct in
 * the file <adc.h>. We are using the 12-bit ADC. The channel used is 0, input 0,
 * Pin on the Adafruit board is A4.
 * We are taking a maximum of 1 sample from the microphone, hence maxcnt = 1.
 *
 */

void adc_init(); /** function used to initialise the ADC */

/**
 *
 * This function reads an analog input from the microphone. The events are cleared prior
 * to taking samples. Tasks are issued and events are monitored before doing any processing
 * on the data.
 * 
 * @params[in] non
 * @return val Value read from the ADC
 */

int16_t adc_read_pin(); /** function to read ADC input */

#endif /* _ADC_H_ */