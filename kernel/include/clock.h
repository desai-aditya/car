#ifndef _CLOCK_H_ 
#define _CLOCK_H_ 

#include<stdint.h>

#define CLOCK_BASE              0x40000000UL

/* Bits 1..0 : Clock source */
#define CLOCK_LFCLKSRC_SRC_SHIFT (0UL) /*!< Position of SRC field. */
#define CLOCK_LFCLKSRC_SRC_Msk (0x3UL << CLOCK_LFCLKSRC_SRC_SHIFT) /*!< Bit mask of SRC field. */
#define CLOCK_LFCLKSRC_SRC_RC (0UL) /*!< 32.768 kHz RC oscillator (LFRC) */
#define CLOCK_LFCLKSRC_SRC_Xtal (1UL) /*!< 32.768 kHz crystal oscillator (LFXO) */
#define CLOCK_LFCLKSRC_SRC_Synth (2UL) /*!< 32.768 kHz synthesized from HFCLK (LFSYNT) */

typedef struct {
    volatile uint32_t tasks_hfclkstart;
    volatile uint32_t tasks_hfclkstop;
    volatile uint32_t tasks_lfclkstart;
    volatile uint32_t tasks_lfclkstop;
    volatile uint32_t tasks_cal;
    volatile uint32_t tasks_ctstart;
    volatile uint32_t tasks_ctstop;     // 0x18
    volatile uint32_t nothing1[57];     // [0x1c - > 0x100) = (0x100 - 0x1c)/4 = 57
    volatile uint32_t events_hfclkstarted;
    volatile uint32_t events_lfclkstarted;
    volatile uint32_t events_done;
    volatile uint32_t events_ctto;      // 0x110
    volatile uint32_t nothing2[5];      // [0x114 - > 0x128) = (0x128 - 0x114)/4 = 5
    volatile uint32_t events_ctstarted; // 0x128
    volatile uint32_t events_ctstopped; // 0x12c
    volatile uint32_t nothing3[117];    // [0x130 - > 0x304) = (0x304 - 0x130)/4 = 117
    volatile uint32_t intenset;         // 0x304
    volatile uint32_t intenclr;         // 0x308
    volatile uint32_t nothing4[63];     // [0x30c - > 0x408) = (0x408 - 0x30c)/4 = 63
    volatile uint32_t hfclkrun;         // 0x408
    volatile uint32_t hfclkstat;        // 0x40c
    volatile uint32_t nothing5[1];      // [0x410 - > 0x414) = (0x414 - 0x410)/4 = 1
    volatile uint32_t lfclkrun;         // 0x414
    volatile uint32_t lfclkstat;        // 0x418
    volatile uint32_t lfclksrccopy;     // 0x41c
    volatile uint32_t nothing6[62];     // [0x420 - > 0x518) = (0x518 - 0x420)/4 = 62
    volatile uint32_t lfclksrc;         // 0x518
    volatile uint32_t nothing7[3];      // [0x51c - > 0x528) = (0x528 - 0x51c)/4 = 3
    volatile uint32_t hfxodebounce;     // 0x528
    volatile uint32_t nothing8[3];      // [0x52c - > 0x538) = (0x538 - 0x52c)/4 = 3
    volatile uint32_t ctiv;             // 0x538
    volatile uint32_t nothing9[8];      // [0x53c - > 0x55c) = (0x55c - 0x53c)/4 = 8
    volatile uint32_t traceconfig;      // 0x55c
    volatile uint32_t nothing10[21];    // [0x560 - > 0x5b4) = (0x5b4 - 0x560)/4 = 21
    volatile uint32_t lfrcmode;         // 0x5b4
}CLOCK_MMIO_t;

/**
 * @brief 
 * clock_init: initialize clock
 * 
 * @return void
 */
void clock_init();

#endif 