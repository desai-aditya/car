/** @file   gpio.h
 *
 *  @brief  Prototypes for GPIO configuration, set, clear, and read
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 05 September 2022
 *  @author CMU 14-642
**/
#ifndef _GPIO_H_
#define _GPIO_H_
#include <unistd.h>

/* GPIO Port Mode */
#define MODE_INPUT      (0)
#define MODE_OUTPUT     (1)

/* GPIO Output Types -- S "standard", H "high", D "drain" */
#define OUTPUT_S0S1     (0)
#define OUTPUT_H0S1     (1)
#define OUTPUT_S0H1     (2)
#define OUTPUT_H0H1     (3)
#define OUTPUT_D0S1     (4)
#define OUTPUT_D0H1     (5)
#define OUTPUT_S0D1     (6)
#define OUTPUT_H0D1     (7)

/* GPIO Pull-Up or Pull-Down */
#define PUPD_NONE       (0)
#define PUPD_PULL_DOWN  (1)
#define PUPD_PULL_UP    (3)

/*
 *
 * Definition of the structures 
 *
 */

#define GPIO0 (uint32_t*)0x50000000
#define GPIO1 (uint32_t*)0x50000300

#define SET 1
#define RESET 0
#define INPUT_MASK 0x00000002

#define WORD_SIZE 4
#define GPIOTE_BASE_REGISTER 0x40006000
#define AIRCR (uint32_t*)0xE000ED0C
#define ICTR (uint32_t*)0xE000E004
#define RESET_EXCEPTION_NUMBER 1
#define GPIOTE_EXCEPTION_NUMBER 6
#define ICSR (uint32_t*)0xE000ED04
#define VTOR (uint32_t*)0xE000ED08
#define NVIC_ISER (uint32_t*)0xE000E100
#define NVIC_ICER (uint32_t*)0xE000E180
#define NVIC_ISPR (uint32_t*)0xE000E200
#define NVIC_ICPR (uint32_t*)0xE000E280
#define NVIC_IABR (uint32_t*)0xE000E300
#define NVIC_IPR (uint32_t*)0xE000E400
#define VECTRESET 1
#define VECTCLRACTIVE 2
#define SYSTRESETQ 4

#define NVIC_ICTR (uint32_t)*0xE000E004 /** Interrupt Control Type Register */

typedef struct nvic_iser {
    uint32_t iser0;
    uint32_t iser1;
    uint32_t iser2;
    uint32_t iser3;
    uint32_t iser4;
    uint32_t iser5;
    uint32_t iser6;
    uint32_t iser7;
} nvic_iser_t; /** Interrupt Set Enable Register */

typedef struct tasks_out {
    uint32_t out[8];
} tasks_out_t; /** task for writing to pin specified in CONFIG[n].PSEL */

typedef struct tasks_set {
    uint32_t set[8];
} tasks_set_t; /** task for writing to pin specified in CONFIG[n].PSEL */

typedef struct tasks_clr {
    uint32_t clr[8];
} tasks_clr_t; /** task for writing to pin specified in CONFIG[n].PSEL */

typedef struct events_in {
    volatile uint32_t event[8];
} events_in_t; /** task for writing to pin specified in CONFIG[n].PSEL */

typedef struct configuration {
    uint32_t config[8];
} config_t; /** task for writing to pin specified in CONFIG[n].PSEL */

typedef struct gpiote {
    tasks_out_t gpiote_tasks_out;
    char pad0[16];
    tasks_set_t gpiote_tasks_set;
    char pad1[16];
    tasks_clr_t gpiote_tasks_clr;
    char pad2[128];
    volatile events_in_t gpiote_events_in;
    char pad3[92];
    uint32_t events_port;
    char pad4[388];
    volatile uint32_t intenset;
    volatile uint32_t intenclr;
    char pad5[516];
    config_t gpiote_config;
} gpiote_t;


typedef struct pin_conf {
    uint32_t configuration; /** configuration register */
} conf_t;

typedef struct gpio {
    char pad0[1284]; /** additional padding between registers */
    uint32_t out; /** write to GPIO */
    uint32_t outset; /** set output of GPIO */
    uint32_t outclr; /** clear output */
    uint32_t in; /** configure pin as input */
    uint32_t dir; /** direction of the GPIO */
    uint32_t dirset; /** set direction of pin */
    uint32_t dirclr; /** DIR clear register */
    uint32_t latch; /** r indicating what GPIO pins that have met the criteria set in the PIN_CNF[n].SENSE */
    uint32_t detect_mode; /** Select between default DETECT signal behavior and LDETECT mode */
    char pad1[476]; /** additional padding between registers */
    conf_t conf[31]; /** configuration register for the GPIO pins */
} gpio_t;


#define UICR_REG0   (*((uint32_t*) 0x10001304))
#define NVMC_CONFIG (*((uint32_t*) 0x4001E504))
#define NVMC_READY  (*((uint32_t*) 0x4001E400))
#define PWM0 (uint32_t*)0x4001C000
#define PWM1 (uint32_t*)0x40021000
#define PWM2 (uint32_t*)0x40022000
#define PWM3 (uint32_t*)0x4002D000

typedef struct seq {
	uint16_t* ptr; /** address of the sequence in the RAM */
	uint32_t cnt; /** count of elements in the sequence */
	uint32_t refresh; /** Number of additional PWM periods between samples loaded into compare register*/
	uint32_t enddelay; /** delay between sequences */
} seq_t;

typedef struct pwm {
	char pad0[4]; /** additional padding between registers */
	uint32_t tasks_stop; /** to trigger stop of PWM */
	uint32_t tasks_seqstart[2]; /** start the pwm sequencing */
	uint32_t tasks_nextstep; /** Steps by one value in the current sequence on all enabled channels*/
	char pad[240]; /** additional padding between registers */
	volatile uint32_t events_stopped; /** indicate stop event */
	volatile uint32_t events_seqstarted[2]; /** indicate start of sequencing */
	volatile uint32_t events_seqend[2]; /** indicate end of sequencing */
	volatile uint32_t events_pwmperiodend; /** indicate end of pwm period */
	volatile uint32_t events_loopsdone; /** indicate completion of loops */
	char pad_extra[224]; /** additional padding between registers */
	uint32_t shorts; /** shortcuts between local events and tasks */
	char pad1[252]; /** additional padding between registers */
	uint32_t inten; /** Enable or disable interrupts */
	uint32_t intenset; /** enable interrupts */
	uint32_t intenclr; /** disable interrupts */
	char pad2[500]; /** additional padding between registers */
	uint32_t enable; /** enable pwm */
	uint32_t mode; /** mode of counting */
	uint32_t countertop; /** reload value for counter */
	uint32_t prescaler; /** pre scale factor for counter */
	uint32_t decoder; /** configure the decode */
	uint32_t loop; /** Number of playbacks of a loop
 */
	char pad3[8]; /** additional padding between registers */
	seq_t seq0; /** for sequence 0 */
	char pad4[16]; /** additional padding between registers */
	seq_t seq1; /** for sequence 1*/
	char padExtra1[20]; /** additional padding between registers */
	uint32_t pselout[4]; /** select the pwm channel */
} pwm_t;

/*
 * GPIO initialization function
 *
 * @param port   - 0 or 1
 * @param pin    - 0 to 31 for port 0, 0 to 15 for port 1
 * @param mode   - GPIO port mode (input or output)
 * @param otype  - GPIO output types (standard, high, open-drain)
 * @param pupd   - GPIO pull up, down, or neither
 */
void gpio_init(uint8_t port, uint8_t pin, uint8_t mode, uint8_t otype, uint8_t pupd);

/*
 * gpio_set: Set specified GPIO port/pin to high
 */
void gpio_set(uint8_t port, uint8_t pin);

// example
void gpio_toggle(uint8_t port, uint8_t pin);

/*
 * gpio_clr: Clear specified GPIO port/pin to low
 */
void gpio_clr(uint8_t port, uint8_t pin);

/*
 * gpio_read_all: Read all the gpio IN pins from selected port.
 * Each bit corresponds to its GPIO pin.
 */
uint32_t gpio_read_all(uint8_t port);

/*
 * gpio_read: return only a single logic value for the given port/pin
 */
uint8_t gpio_read(uint8_t port, uint8_t pin);

/**
 * 
 * This function is used to initialse the PWM module
 * 
 */

void pwm_init(void);

/**
 * 
 * enable_user_sw_and_reset: This function is used to enable the user sw button and the reset button.
 * We use gpiote to enable events that occur on the pin
 * 
 */

void enable_user_sw_and_reset();

/**
 * 
 * glow_led: This function is used to glow the LEDs. We glow the onboard LEDs - 
 * the red one and the blue one in a separate thread.
 * 
 */

void glow_led(int on);

void pwm_actuate_forward(void);
void pwm_actuate_backward(void);
void pwm_actuate_left(void);
void pwm_actuate_right(void);
void pwm_stop(void);

#endif /* _GPIO_H_ */