/** @file   radio.h
 *
 *  @brief  Prototypes for radio configuration
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 24 November 2022
 *  @author CMU 14-642
**/
#ifndef _RADIO_H_
#define _RADIO_H_

#include<stdint.h>
#include<radio_bitfields.h>

#define RADIO_MODE_IEEE802154_250Kbit (15)



#define PACKET_BASE_ADDRESS_LENGTH  (4UL)                   //!< Packet base address length field size in bytes
#define PACKET_STATIC_LENGTH        (12UL)                   //!< Packet static length in bytes
#define PACKET_PAYLOAD_MAXSIZE      (PACKET_STATIC_LENGTH)  //!< Packet payload maximum size in bytes

typedef struct RADIO_MMIO{
    volatile uint32_t tasks_txen;           // 0x00
    volatile uint32_t tasks_rxen; 
    volatile uint32_t tasks_start; 
    volatile uint32_t tasks_stop; 
    volatile uint32_t tasks_disable; 
    volatile uint32_t tasks_rssistart; 
    volatile uint32_t tasks_rssistop; 
    volatile uint32_t tasks_bcstart; 
    volatile uint32_t tasks_bcstop; 
    volatile uint32_t tasks_edstart; 
    volatile uint32_t tasks_edstop; 
    volatile uint32_t tasks_ccastart; 
    volatile uint32_t tasks_ccastop; 
    volatile uint32_t nothing1[51];  // [0x34 to 0x100) -> (0x100 - 0x34)/4 = 51
    volatile uint32_t events_ready; 
    volatile uint32_t events_address; 
    volatile uint32_t events_payload; 
    volatile uint32_t events_end; 
    volatile uint32_t events_disabled; 
    volatile uint32_t events_devmatch; 
    volatile uint32_t events_devmiss; 
    volatile uint32_t events_rssiend; 
    volatile uint32_t nothing2[2]; // [0x120 to 0x128) -> (0x128 - 0x120)/4 = 
    volatile uint32_t events_bcmatch; 
    volatile uint32_t nothing3[1]; // [0x12c to 0x130) -> (0x130 - 0x12c)/4 = 
    volatile uint32_t events_crcok; 
    volatile uint32_t events_crcerror; 
    volatile uint32_t events_framestart; 
    volatile uint32_t events_edend; 
    volatile uint32_t events_edstopped; 
    volatile uint32_t events_ccaidle; 
    volatile uint32_t events_ccabusy; 
    volatile uint32_t events_ccastopped; 
    volatile uint32_t events_rateboost; 
    volatile uint32_t events_txready; 
    volatile uint32_t events_rxready; 
    volatile uint32_t events_mhrmatch;          // 0x15c
    volatile uint32_t nothing4[2]; // [0x160 to 0x168) -> (0x168 - 0x160)/4 = 
    volatile uint32_t events_sync; 
    volatile uint32_t events_phyend;  // 0x16c
    volatile uint32_t nothing5[36]; // [0x170 to 0x200) -> (0x200 - 0x170)/4 = 
    volatile uint32_t shorts;               // 0x200
    volatile uint32_t nothing6[64]; // [0x204 to 0x304) -> (0x304 - 0x204)/4 = 
    volatile uint32_t intenset; 
    volatile uint32_t intenclr;             // 0x308
    volatile uint32_t nothing7[61]; // [0x30c to 0x400) -> (0x400 - 0x30c)/4 = 
    volatile uint32_t crcstatus; 
    volatile uint32_t nothing8[1]; // [0x404 to 0x408) -> (0x408 - 0x404)/4 = 
    volatile uint32_t rxmatch; 
    volatile uint32_t rxcrc; 
    volatile uint32_t dai; 
    volatile uint32_t pdustat;              // 0x414
    volatile uint32_t nothing9[59]; // [0x418 to 0x504) -> (0x504 - 0x418)/4 = 
    volatile uint32_t packetptr; 
    volatile uint32_t frequency; 
    volatile uint32_t txpower; 
    volatile uint32_t mode; 
    volatile uint32_t pcnf[2]; 
    volatile uint32_t base[2]; 
    volatile uint32_t prefix[2]; 
    volatile uint32_t txaddress; 
    volatile uint32_t rxaddresses; 
    volatile uint32_t crccnf; 
    volatile uint32_t crcpoly; 
    volatile uint32_t crcinit;          // 0x53c
    volatile uint32_t nothing10[1]; // [0x540 to 0x544) -> (0x544 - 0x540)/4 = 
    volatile uint32_t tifs; 
    volatile uint32_t rssisample;       // 0x548
    volatile uint32_t nothing11[1]; // [0x54c to 0x550) -> (0x550 - 0x54c)/4 = 
    volatile uint32_t state; 
    volatile uint32_t datawhiteiv;  // 0x554
    volatile uint32_t nothing12[2]; // [0x558 to 0x560) -> (0x560 - 0x558)/4 = 
    volatile uint32_t bcc;          // 0x560
    volatile uint32_t nothing13[39]; // [0x564 to 0x600) -> (0x600 - 0x564)/4 = 
    volatile uint32_t dab[8]; 
    volatile uint32_t dap[8]; 
    volatile uint32_t dacnf;
    volatile uint32_t mhrmatchconf;
    volatile uint32_t mhrmatchmas;      // 0x648
    volatile uint32_t nothing14[1]; // [0x64c to 0x650) -> (0x650 - 0x64c)/4 = 
    volatile uint32_t modecnf0;         // 0x650
    volatile uint32_t nothing15[3]; // [0x654 to 0x660) -> (0x660 - 0x654)/4 = 
    volatile uint32_t sfd;
    volatile uint32_t edcnt;
    volatile uint32_t edsample;
    volatile uint32_t ccactrl;             // 0x66c
    volatile uint32_t nothing16[611]; // [0x670 to 0xffc) -> (0xffc - 0x670)/4 = 
    volatile uint32_t power;
} RADIO_MMIO_t;

/**
 * @brief 
 * radio_init: initialize radio
 * 
 * @return void
 */
void radio_init();

/**
 * @brief 
 * sys_send_packet: send data over radio
 * Data MUST be 3 integers
 * 
 * @param data 
 * @return void
 */
void sys_send_packet(int32_t data);

/**
 * @brief 
 * sys_send_rgb_packet: send color data over radio
 * 
 * @param r red
 * @param g green
 * @param b blue
 * @return void
 */
void sys_send_rgb_packet(int32_t r,int32_t g, int32_t b);

/**
 * @brief 
 * sys_recv_packet: receive data over radio
 * 
 * @param data 
 * @param timeout 
 * @return int32_t number of bytes received
 */
int32_t sys_recv_packet(int32_t* data, int32_t timeout);

#endif /* _GPIO_H_ */

