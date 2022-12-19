/** @file   adc.c
 *
 *  @brief  ADC driver implementation
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 12 October 2022
 *  @authors Alisha Joshi <alishaj@andrew.cmu.edu>
 *  	     Shreya Deepak <sdeepak@andrew.cmu.edu>
**/

#include <adc.h>
#include<printk.h>
#include<gpio.h>
#include<arm.h>
#include<rfft.h>

volatile int16_t result;

adc_t* adc;
extern volatile nvic_iser_t* iser;
extern int16_t input[FFT_SIZE];

/**
 *
 * This function initialise the ADC. The instance of the ADC is defined as a struct in
 * the file <adc.h>. We are using the 12-bit ADC. The channel used is 0, input 0,
 * Pin on the Adafruit board is A4.
 * We are taking a maximum of 1 sample from the microphone, hence maxcnt = 1.
 *
 */

void adc_init() {
    adc = (adc_t*)ADC;
    
    adc->channel_configuration[0].pselp |= AIN0;
    iser->iser0 |= (1 << ADC_EXCEPTION_NUMBER);
    adc->channel_configuration[0].config |= 0x00000002;
    adc->resolution = 0;
    adc->intenset |= 0x02; // interrupt enabled
    adc->resolution = RESOLUTION;
    adc->result_maxcnt = FFT_SIZE;
    adc->enable = 1;
}

/**
 *
 * This function reads an analog input from the microphone. The events are cleared prior
 * to taking samples. Tasks are issued and events are monitored before doing any processing
 * on the data.
 * 
 * @params[in] non
 * @return val Value read from the ADC
 */

int16_t adc_read_pin() {
    adc->events_started = 0;
    adc->events_end = 0;
    adc->events_done = 0;
    adc->events_resultdone = 0;
    adc->events_calibrateddone = 0;
    adc->events_stopped = 0;
    
    adc->resultptr = input;
    adc->tasks_start = 1;
    while(!adc->events_started);
    adc->events_started = 0;

    

    while(!adc->events_resultdone) {
        adc->tasks_sample = 1;
    }

    // printk("Now stopping adc\n");

    adc->tasks_stop = 1;

    return result; 
}

void SAADC_IRQHandler() {

    //printk("Read %d samples\n",adc->result_amount);
    for(int i = 0; i < FFT_SIZE; i++) {
        //printk("%d\t", input[i]);
    }

    adc->events_started = 0;
    adc->events_end = 0;
    adc->events_done = 0;
    adc->events_resultdone = 0;
    adc->events_calibrateddone = 0;
    adc->events_stopped = 0;
}
