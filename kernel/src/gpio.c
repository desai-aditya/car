/** @file   gpio.c
 *
 *  @brief  GPIO interface implementation
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 12 October 2022
 *  @authors Alisha Joshi <alishaj@andrew.cmu.edu>
 *  	     Shreya Deepak <sdeepak@andrew.cmu.edu>
 *
**/

#include <gpio.h>
#include<printk.h>
#include<pix.h>

gpio_t* led; // global GPIO instance
pwm_t* onboard_led;
pwm_t* motor1;
pwm_t* motor2;

uint16_t pwm_sequence[200];
uint16_t value = 0;
uint16_t step = 100;
volatile nvic_iser_t* iser = (nvic_iser_t*)NVIC_ISER;
gpiote_t* user_sw = (gpiote_t*)GPIOTE_BASE_REGISTER;

/**
 *
 * This function initialises the GPIO instance. The instance is created in the form of a
 * struct in the file gpio.h. We are using GPIO 0. 
 *
 * @params[in] port - Port 1 or port 0
 * @params[in] pin - The pin number on the port
 * @params[in] mode - Input or output pin
 * @params[in] otype - Drive type of the pin - Values are defined in header file
 * @params[in] pupd - Pull up and pull down configuration - Values defined in header file
 *
 * @return val none
 *
 */

void gpio_init(uint8_t port, uint8_t pin, uint8_t mode, uint8_t otype, uint8_t pupd) {
  
    // port is 1, pin is 15
    if(port) {
        led = (gpio_t*)0x50000300UL;
    }
    else {
        led = (gpio_t*)0x50000000UL;
    }

	
    led->dir |= mode; // set pin as output/input
    led->dirset |= mode; // set the pin as output/input 
    conf_t* conf_reg;

    conf_reg = (conf_t*)((char*)led + 0x700 + (pin * 0x04)); // configuration register

    if(mode) {
        conf_reg->configuration |= SET; // pin is output
    }
    else {
        // reset bit 1
        conf_reg->configuration &= ~(INPUT_MASK);
    }
    conf_reg->configuration |= (pupd << 2); // pull up or pull down
    conf_reg->configuration |= (otype << 8); // output type    

} 

/**
 *
 * @brief This function is used to set the GPIO pin to high. 
 *
 * @params[in] port - The port on the board
 * @params[in] The pin on the corresponding port
 *
 * @return val none
 *
 */


void gpio_set(uint8_t port, uint8_t pin) {
    if(port) {
        led = (gpio_t*)GPIO1;
    }
    else {
        led = (gpio_t*)GPIO0;
    }

    led->out |= (1 << pin); 
}

/**
 *
 * This function is used to clear the gpio pin, meaning set it to 0.
 *
 * @params[in] port - The port on the board
 * @params[in] pin - The pin on the corresponding port
 *
 * @return val none
 *
 */

void gpio_clr(uint8_t port, uint8_t pin) {
    if(port) {
        led = (gpio_t*)GPIO1;
    }
    else {
        led = (gpio_t*)GPIO0;
    }

    led->out &= ~(1 << pin);

}

// example

void gpio_toggle(uint8_t port, uint8_t pin) {
    if(port) {
        led = (gpio_t*)GPIO1;
    }
    else {
        led = (gpio_t*)GPIO0;
    }
    led->out ^= (1 << pin);
}

/**
 *
 * @brief This function is used to read the contents of the entire port. The
 * values of the individual pins can be read using this function.
 *
 * @params[in] port - Port number to be read
 * 
 * @return val 32-bit value of the port contents
 */

uint32_t gpio_read_all(uint8_t port) {
    if(port) {
        led = (gpio_t*)GPIO1;
    }
    else {
        led = (gpio_t*)GPIO0;
    }

    return led->in;
}

/**
 *
 * @brief This function is used to read the value of the GPIO pin.
 *
 * @params[in] port - The port on which the pin is present
 * @params[in] pin - The pin number to be read
 *
 * @return val the value of the pin
 *
 */

uint8_t gpio_read(uint8_t port, uint8_t pin) {
    if(port) {
        led = (gpio_t*)GPIO1;
    }
    else {
        led = (gpio_t*)GPIO0;
    }
    
    if(led->in & (1 << pin)) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * 
 * @brief This function is used to initialise the pwm module. We use the 
 * on board LEDs and the neopixel.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

// void pwm_init(void) {
//     onboard_led = (pwm_t*)0x4001C000;
//     onboard_led->mode = 0; // use the UP counter
//     onboard_led->countertop = 10000; // count upto 10000
//     onboard_led->prescaler = 4; // divide by 16, so 1MHz clock
//     onboard_led->decoder = 0; // use COMMON mode
    
//     onboard_led->seq0.cnt = 100;
//     onboard_led->seq0.refresh = 0;
//     onboard_led->seq0.enddelay = 0;
//     onboard_led->loop= 0;

//     // port 1 pin 10 and port 1 pin 15 are onboard LEDs
//     onboard_led->pselout[0] = 0x2a; // led1
//     onboard_led->pselout[1] = 0x2f; //led2

//     onboard_led->seq0.ptr = pwm_sequence;

//     onboard_led->enable = 1;
// }

/**
 * 
 * @brief This function is used to glow the onboard leds. It takes an input 
 * which determines whether we want to exit the application or we want the LEDs
 * to glow and dance.
 * 
 * @params[in] on - takes a 0 or a 1 
 * 
 * @return none
 * 
 */


void glow_led(int on) {

    if(!on) {
        gpio_clr(1,10);
        gpio_clr(1,15);
        return;
    }

    // for(int i = 0; i < 10; i++) {
    //     value += 100;
    //     pwm_sequence[i] = value;
    //     pwm_sequence[100-i] = step-value;
    // }

    // onboard_led->tasks_seqstart[0] = 1;

    // while(!onboard_led->events_seqstarted[0]);

    // onboard_led->events_seqstarted[0] = 0;

    // while(!onboard_led->events_seqend[0]);

    // onboard_led->events_seqend[0] = 0;

    // onboard_led->tasks_stop = 1;

    // while(!onboard_led->events_stopped);

    // onboard_led->events_stopped = 0;

    // onboard_led->events_loopsdone = 0;
    // onboard_led->events_pwmperiodend = 0;
    // onboard_led->events_seqend[0] = 0;
    // onboard_led->events_seqend[1] = 0;
    // onboard_led->events_seqstarted[0] = 0;
    // onboard_led->events_seqstarted[1] = 0;
    // onboard_led->events_stopped = 0;

    

    gpio_toggle(1,10);
    gpio_toggle(1,15);
}

/**
 * 
 * @brief This function is used to enable the user sw and the reset button. 
 * We use the gpiote module to enable the inputs events on the buttons.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */


void enable_user_sw_and_reset() {
    

    user_sw->gpiote_config.config[0] = 0x00012201; // enable the user SW button
    user_sw->gpiote_config.config[1] = 0x00011201; // enable the reset button
    
    // user_sw->intenset |= 0x01; // enable interrupt for channel 0
    user_sw->intenset |= 0x03; // enable interrupt for channel 0 and channel 1

    iser->iser0 |= (1 << GPIOTE_EXCEPTION_NUMBER); // enable interrupt

    return;
}

/**
 * 
 * This is the interrupt handler of the GPIOTE module. This is used to take action
 * when either the reset or the user sw button is pressed.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */


void GPIOTE_IRQHandler() {
    volatile uint32_t* aircr_register = (volatile uint32_t*)AIRCR;

    if(user_sw->gpiote_events_in.event[0]){
        user_sw->gpiote_events_in.event[0] = 0;

        printk("Are you ready?\n");
    }
    else if(user_sw->gpiote_events_in.event[1]){
        user_sw->gpiote_events_in.event[1] = 0;

        printk("Reset button pressed!\n");

        *aircr_register = 0x5FA0004 | (*aircr_register & 0x700); // Referred to this from the textbook by Joseph Yiu

        
    }
    
}
/**
 * 
 * This function is used to initialise the pwm module.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void pwm_init(void) {
    motor1 = (pwm_t*)PWM0;
    motor2 = (pwm_t*)PWM1;

    motor1->mode = 0; // use the UP counter
    motor1->countertop = 10000; // count upto 10000
    motor1->prescaler = 4; // divide by 16, so 1MHz clock
    motor1->decoder = 0; // use COMMON mode
    
    motor1->seq0.cnt = 200;
    motor1->seq0.refresh = 0;
    motor1->seq0.enddelay = 0;
    motor1->seq0.refresh = 0;
    motor1->seq0.enddelay = 0;
    motor1->loop= 0;


    // motor1->pselout[0] = 0x1a; // port 0 pin 26, 
    // motor1->pselout[1] = 0x06; // port 0 pin 6, 
    // motor1->pselout[2] = 0x08; // port 0 pin 8
    // motor1->pselout[3] = 0x29; // port 1 pin 9, 

    for(int i = 0; i < 200; i++) {
        value =+ 100;
        pwm_sequence[i] = value;
        // pwm_sequence[100-i] = step-value;
    }

    motor1->seq0.ptr = pwm_sequence;

    // motor1->enable = 1;
}

/**
 * 
 * @brief This function is used to move the car forward. This is the function call that does
 * the propulsion.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void pwm_actuate_forward(void) {
    printk("Moving front\n");
    motor1->pselout[0] = 0x1a; // port 0 pin 26, 
    motor1->pselout[2] = 0x08; // port 0 pin 8
    motor1->enable = 1;
    gpio_clr(0,7);
    gpio_clr(1,8);
    // play pwm

    motor1->tasks_seqstart[0] = 1; // start the PWM sequence

    while(!motor1->events_seqstarted);

    motor1->tasks_seqstart[0] = 0; 
    
    while(!motor1->events_seqend[0]);

    motor1->tasks_stop = 1;

    while(!motor1->events_stopped);

    motor1->tasks_stop = 0;

    // clear events 
    motor1->events_stopped = 0;
    motor1->events_seqstarted[0] = 0;
    motor1->events_seqstarted[1] = 0;
    motor1->events_seqend[0] = 0;
    motor1->events_seqend[1] = 0;
    motor1->events_pwmperiodend = 0;
    motor1->events_loopsdone = 0;

}

/**
 * 
 * @brief This function is used to move the car backward. This is the function call that does
 * the propulsion.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void pwm_actuate_backward(void) {
    printk("Moving back\n");

    // motor1->pselout[0] = 0x1b; // port 0 pin 27, 
    motor1->pselout[0] = 0x07; // port 0 pin 7, 
    motor1->pselout[2] = 0x28; // port 1 pin 8
    // motor1->pselout[3] = 0x04; // port 0 pin 4,

    motor1->enable = 1;

    gpio_clr(0,26);
    // gpio_clr(0,6);
    gpio_clr(0,8);
    // gpio_clr(1,9);

    // old code below
    // gpio_clr(0,27);
    // gpio_clr(0,7);
    // gpio_clr(1,8);
    // gpio_clr(0,11);
    // // gpio_clr(0,30);

    // // play pwm

    motor1->tasks_seqstart[0] = 1; // start the PWM sequence

    while(!motor1->events_seqstarted);

    motor1->tasks_seqstart[0] = 0; 
    
    while(!motor1->events_seqend[0]);

    motor1->tasks_stop = 1;

    while(!motor1->events_stopped);

    motor1->tasks_stop = 0;

    // clear events 
    motor1->events_stopped = 0;
    motor1->events_seqstarted[0] = 0;
    motor1->events_seqstarted[1] = 0;
    motor1->events_seqend[0] = 0;
    motor1->events_seqend[1] = 0;
    motor1->events_pwmperiodend = 0;
    motor1->events_loopsdone = 0;
}

void pwm_stop() {
    motor1->enable = 0;
    motor1->events_stopped = 0;
    motor1->events_seqstarted[0] = 0;
    motor1->events_seqstarted[1] = 0;
    motor1->events_seqend[0] = 0;
    motor1->events_seqend[1] = 0;
    motor1->events_pwmperiodend = 0;
    motor1->events_loopsdone = 0;
    motor1->pselout[0] = 0xffffffff;
    motor1->pselout[1] = 0xffffffff;
    motor1->pselout[2] = 0xffffffff;
    motor1->pselout[3] = 0xffffffff;
    // printk("Stopping car!\n");
    gpio_clr(0,8);
    gpio_clr(1,8);
    gpio_clr(0,26);
    gpio_clr(0,7);
}
/**
 * 
 * @brief This function is used to move the car right. This is the function call that does
 * the propulsion.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void pwm_actuate_right(void) {
    printk("Moving right\n");
    motor1->pselout[2] = 0x08; // port 0, pin 8
    motor1->enable = 1;
    gpio_clr(0,7);
    gpio_clr(0,26);
    gpio_clr(1,8);
    // play pwm

    motor1->tasks_seqstart[0] = 1; // start the PWM sequence

    while(!motor1->events_seqstarted);

    motor1->tasks_seqstart[0] = 0; 
    
    while(!motor1->events_seqend[0]);

    motor1->tasks_stop = 1;

    while(!motor1->events_stopped);

    motor1->tasks_stop = 0;

    // clear events 
    motor1->events_stopped = 0;
    motor1->events_seqstarted[0] = 0;
    motor1->events_seqstarted[1] = 0;
    motor1->events_seqend[0] = 0;
    motor1->events_seqend[1] = 0;
    motor1->events_pwmperiodend = 0;
    motor1->events_loopsdone = 0;


}

/**
 * 
 * @brief This function is used to move the car left. This is the function call that does
 * the propulsion.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void pwm_actuate_left(void) {
    printk("Moving left!\n");
    motor1->pselout[2] = 0x1a; // port 0, pin 26
    motor1->enable = 1;
    gpio_clr(0,7);
    gpio_clr(0,8);
    gpio_clr(1,8);
    // play pwm

    motor1->tasks_seqstart[0] = 1; // start the PWM sequence

    while(!motor1->events_seqstarted);

    motor1->tasks_seqstart[0] = 0; 
    
    while(!motor1->events_seqend[0]);

    motor1->tasks_stop = 1;

    while(!motor1->events_stopped);

    motor1->tasks_stop = 0;

    // clear events 
    motor1->events_stopped = 0;
    motor1->events_seqstarted[0] = 0;
    motor1->events_seqstarted[1] = 0;
    motor1->events_seqend[0] = 0;
    motor1->events_seqend[1] = 0;
    motor1->events_pwmperiodend = 0;
    motor1->events_loopsdone = 0;
}

// void pwm_stop(void) {

//     motor1->events_loopsdone = 0;
//     motor1->events_pwmperiodend = 0;
//     motor1->events_seqend[0] = 0;
//     motor1->events_seqend[1] = 0;
//     motor1->events_seqstarted[0] = 0;
//     motor1->events_seqstarted[1] = 0;
//     motor1->events_stopped = 0;

//     gpio_clr(0,26);
//     gpio_clr(0,27);
//     gpio_clr(0,6);
//     gpio_clr(0,7);
// }