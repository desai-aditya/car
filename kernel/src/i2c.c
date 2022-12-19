/** @file   i2c.c
 *
 *  @brief  I2C driver implementation
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 1 November 2022
 *  @authors Alisha Joshi <alishaj@andrew.cmu.edu>
 *  	     Shreya Deepak <sdeepak@andrew.cmu.edu>
 *
**/

#include <i2c.h>
#include<gpio.h>
#include<printk.h>
#include<arm.h>

volatile twim_t* twim0;

/**
 *
 * @brief This function initialises the twim0 module. The instance is 
 * defined in the form of a structure in the header file. We are using twim0.
 *
 * SCL - Port 0, pin 11
 * SDA - Port 0, pin 12
 * 
 * @params[in] none
 * @return val none
 *
 */

void i2c_leader_init(){
    // initialise i2c
    twim0 = (twim_t*)0x40003000;
    // initialise the GPIO pins for SCL and SDA
    gpio_init(0, 11, 0, OUTPUT_S0D1, PUPD_PULL_UP); // port 0, pin 11 => SCL
    gpio_init(0, 12, 0, OUTPUT_S0D1, PUPD_PULL_UP); // port 0, pin 12 => SDA
    
    twim0->psel_scl = 0x7fffffcb; 
    twim0->psel_sda = 0x7fffffcc;
    twim0->enable = 6;

    return;
}

/**
 *
 * This function is used to stop the i2c leader. It clears the events and also
 * stops the leader.
 *
 * @params[in] none
 *
 * @return val non
 *
 */


void i2c_leader_stop() {
    // twim0->tasks_stop = 1;
    // while(!twim0->events_stopped);
    // twim0->events_stopped = 0;

    disable_interrupts();
    twim0->events_error = 0;
    twim0->events_suspended = 0;
    twim0->events_rxstarted = 0;
    twim0->events_txstarted = 0;
    twim0->events_lasttx = 0;
    twim0->events_lastrx = 0;

    enable_interrupts();
    
    return;
}

/**
 *
 * This function is mainly for the leader to write into the peripheral device. Our
 * board which is the leader issues a command to the peripheral device which is
 * the lux sensor. The command code to be issued is placed in the tx_buffer in
 * RAM and the address is configured in the instance. 
 *
 * @params[in] tx_buf - Pointer to the tx buffer
 * @params[in] tx_len - Number of elements in the buffer to be transmitted
 * @params[in] follower_addr - The address of the peripheral device to be commanded (0x10)
 *
 * @return value -1 on error 0 on success
 *
 */

int i2c_leader_write(uint8_t *tx_buf, uint8_t tx_len, uint8_t follower_addr) {
    
    // printk("Inside i2c leader write\n");

    disable_interrupts();
    
    twim0->address = follower_addr; // address of the follower
    twim0->txd_ptr = tx_buf;
    twim0->txd_maxcnt = (uint32_t)tx_len;

    twim0->tasks_starttx = 1;

    while(!twim0->events_txstarted);

    twim0->events_txstarted = 0;

    if(twim0->events_error) {
        printk("ERROR %u\n",twim0->errorsrc);
        return -1;
    }

    // while(!twim0->events_lasttx);

    twim0->events_lasttx = 0;

    twim0->tasks_stop = 1;
    while(!twim0->events_stopped);
    twim0->events_stopped = 0;

    enable_interrupts();

    return 0;
}

/**
 *
 * This function is used by the peripheral to communicate with the leader (follower 
 * communicates with the leader). In our case the follower is the lux sensor. The values
 * received are stored in an rx_buffer which is in the RAM and the address is stored in
 * the instance.
 *
 * @params[in] rx_buf - pointer to the buffer
 * @params[in] rx_len - length of the elements in the buffer
 * @params[in] follower_addr - Address of the follower (0x10)
 *
 * @return val - 0 on success and 1 on error
 *
 */

int i2c_leader_read(uint8_t *rx_buf, uint8_t rx_len, uint8_t follower_addr) {
    // printk("Inside i2c leader read\n");
    disable_interrupts();

    twim0->address = follower_addr;
    twim0->rxd_ptr = rx_buf;
    twim0->rxd_maxcnt = (uint32_t)rx_len;
    twim0->tasks_startrx = 1;

    while(!twim0->events_rxstarted);

    twim0->events_rxstarted = 0;

    if(twim0->events_error) {
        printk("ERROR %u\n",twim0->errorsrc);
        return -1;
    }
    
    while(!twim0->events_lastrx);

    twim0->events_lastrx = 0;

    twim0->tasks_stop = 1;
    while(!twim0->events_stopped);
    twim0->events_stopped = 0;
    
    enable_interrupts();

    return 0;
}