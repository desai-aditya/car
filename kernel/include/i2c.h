/** @file   i2c.h
 *
 *  @brief  Prototypes for I2C setup, read, and write
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 05 September 2022
 *  @author CMU 14-642
**/
#ifndef _I2C_H_
#define _I2C_H_

#include <unistd.h>

#define TWIM0 (uint32_t*)0x40003000
#define TWIM1 (uint32_t*)0x40004000
#define READ (uint8_t)0x21
#define WRITE (uint8_t)0x20

typedef struct twim {
    volatile uint32_t tasks_startrx; /** to start leader receive function */
    char pad0[4]; /** additional padding between registers */
    volatile uint32_t tasks_starttx; /** start leaderer transmit function */
    char pad1[8]; /** additional padding between registers */
    volatile uint32_t tasks_stop; /** stop i2c */
    char pad2[4]; /** additional padding between registers */
    uint32_t tasks_suspend; /** suspend i2c temporarily */
    uint32_t tasks_resume; /** resume i2c */
    char pad3[224]; /** additional padding between registers */
    volatile uint32_t events_stopped; /** to indicate stop event */
    char pad4[28]; /** additional padding between registers */
    volatile uint32_t events_error; /** to indicate error in events */
    char pad5[32]; /** additional padding between registers */
    volatile uint32_t events_suspended; /** to indicate suspending of twim */
    volatile uint32_t events_rxstarted; /** to indicate start of leader receive sequence */
    volatile uint32_t events_txstarted; /** to indicate start of leader transmit sequence */
    char pad6[8]; /** additional padding between registers */
    volatile uint32_t events_lastrx; /** event to indicate last byte reception */
    volatile uint32_t events_lasttx; /** event to indictate last byte transmission */
    char pad7[156]; /** additional padding between registers */
    volatile uint32_t shorts; /** short circuit lasttx and rx with stop event */
    char pad8[252]; /** additional padding between registers */
    uint32_t inten; /** enable or disable interrupts */
    uint32_t intenset; /** Enable Interrupts */
    uint32_t intenclr; /** Disable Interrupts*/
    char pad9[440]; /** additional padding between registers */
    volatile uint32_t errorsrc; /** source of error */
    char pad10[56]; /** additional padding between registers */
    uint32_t enable; /** enable twim */
    char pad11[4]; /** additional padding between registers */
    uint32_t psel_scl; /** select SCL pin */
    uint32_t psel_sda; /** select SDA */
    char pad12[36]; /** additional padding between registers */
    volatile uint8_t* rxd_ptr; /** pointer to the receive buffer */
    volatile uint32_t rxd_maxcnt; /** max count of elements in the buffer */
    volatile uint32_t rxd_amount; /** number of elements in rx buffer */
    volatile uint32_t rxd_list; /**EasyDMA list type*/
    volatile uint8_t* txd_ptr; /** pointer to tx buffer */
    volatile uint32_t txd_maxcnt; /** max elements in tx buffer */
    volatile uint32_t txd_amount; /** count of elements transmitted */
    volatile uint32_t txd_list; /**EasyDMA list type*/
    char pad14[52]; /** additional padding between registers */
    uint8_t address; /** follower address */
} twim_t;

void i2c_leader_init(); /** function to initialse leader */
int i2c_leader_write(uint8_t *tx_buf, uint8_t tx_len, uint8_t follower_addr);
int i2c_leader_read(uint8_t *rx_buf, uint8_t rx_len, uint8_t follower_addr);
void i2c_leader_stop();

#endif /* _I2C_H_ */