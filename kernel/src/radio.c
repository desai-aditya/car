#include<radio.h>
#include<arm.h>
#include<clock.h>
#include<printk.h>
#include<syscall_thread.h>

/* These are set to zero as ShockBurst packets don't have corresponding fields. */
#define PACKET_S1_FIELD_SIZE      (0UL)  /**< Packet S1 field size in bits. */
#define PACKET_S0_FIELD_SIZE      (0UL)  /**< Packet S0 field size in bits. */
#define PACKET_LENGTH_FIELD_SIZE  (0UL)  /**< Packet length field size in bits. */

static uint32_t packet[3];

static uint32_t swap_bits(uint32_t inp);

static uint32_t bytewise_bitswap(uint32_t inp);

/**
 * @brief Function for swapping/mirroring bits in a byte.
 *
 *@verbatim
 * output_bit_7 = input_bit_0
 * output_bit_6 = input_bit_1
 *           :
 * output_bit_0 = input_bit_7
 *@endverbatim
 *
 * @param[in] inp is the input byte to be swapped.
 *
 * @return
 * Returns the swapped/mirrored input byte.
 */
static uint32_t swap_bits(uint32_t inp)
{
    uint32_t i;
    uint32_t retval = 0;

    inp = (inp & 0x000000FFUL);

    for (i = 0; i < 8; i++)
    {
        retval |= ((inp >> i) & 0x01) << (7 - i);
    }

    return retval;
}


/**
 * @brief Function for swapping bits in a 32 bit word for each byte individually.
 *
 * The bits are swapped as follows:
 * @verbatim
 * output[31:24] = input[24:31]
 * output[23:16] = input[16:23]
 * output[15:8]  = input[8:15]
 * output[7:0]   = input[0:7]
 * @endverbatim
 * @param[in] input is the input word to be swapped.
 *
 * @return
 * Returns the swapped input byte.
 */
static uint32_t bytewise_bitswap(uint32_t inp)
{
      return (swap_bits(inp >> 24) << 24)
           | (swap_bits(inp >> 16) << 16)
           | (swap_bits(inp >> 8) << 8)
           | (swap_bits(inp));
}

void send_packet()
{
    RADIO_MMIO_t *radio = (RADIO_MMIO_t *)RADIO_BASE;
    radio->events_disabled= 0U;
    // Disable radio
    radio->tasks_disable = 1U;

    while (radio->events_disabled== 0U)
    {
        // wait
    }
    // send the packet:
    radio->events_ready= 0U;
    radio->tasks_txen   = 1;

    while (radio->events_ready == 0U)
    {
        // wait
    }
    radio->events_end= 0U;
    radio->tasks_start = 1U;

    while (radio->events_end== 0U)
    {
        // wait
    }

    radio->events_disabled= 0U;
    // Disable radio
    radio->tasks_disable = 1U;

    while (radio->events_disabled== 0U)
    {
        // wait
    }
}

void sys_send_rgb_packet(int32_t r,int32_t g, int32_t b)
{
    packet[0] = r;
    packet[1] = g;
    packet[2] = b;
    send_packet();
}

void sys_send_packet(int32_t data)
{
    packet[0] = data;
    send_packet();
}

// make sure data has at max length of 3 int32_t
int32_t sys_recv_packet(int32_t* data, int32_t timeout)
{
    RADIO_MMIO_t *radio = (RADIO_MMIO_t *)RADIO_BASE;
    // uint32_t result = 0;
    radio->events_disabled= 0U;
    // Disable radio
    radio->tasks_disable = 1U;

    while (radio->events_disabled== 0U)
    {
        // wait
    }

    radio->events_ready = 0U;
    // Enable radio and wait for ready
    radio->tasks_rxen= 1U;

    while (radio->events_ready == 0U)
    {
        // wait
    }
    radio->events_end = 0U;
    // Start listening and wait for address received event
    radio->tasks_start = 1U;

    // Wait for end of packet or buttons state changed
    uint32_t now = sys_get_time();
    int is_timeout = 0;
    if(timeout == -1)
    {
        while (radio->events_end == 0U)
        {
            // wait
        }
    }
    else
    {
        while (radio->events_end == 0U && sys_get_time() <= (now + timeout) )
        {
            // wait
        }
        if(radio->events_end == 0){
            is_timeout = 1;
        }
        else{
            radio->events_end = 0;
        }
    }

    if (radio->crcstatus == 1U)
    {
        // result = packet;
        data[0] = packet[0];
        data[1] = packet[1];
        data[2] = packet[2];
    }
    radio->events_disabled = 0U;
    // Disable radio
    radio->tasks_disable= 1U;

    while (radio->events_disabled == 0U)
    {
        // wait
    }

    if(is_timeout)return -1;
    return 4;
}

void radio_init()
{
    clock_init();
    RADIO_MMIO_t *radio = (RADIO_MMIO_t *)RADIO_BASE;
    // Radio config
    radio->txpower = (RADIO_TXPOWER_TXPOWER_0dBm << RADIO_TXPOWER_TXPOWER_SHIFT);
    radio->frequency = 7UL;  // Frequency bin 7, 2407MHz
    radio->mode      = (RADIO_MODE_MODE_Nrf_1Mbit << RADIO_MODE_MODE_SHIFT);

    // Radio address config
    radio->prefix[0] =
        ((uint32_t)swap_bits(0xC3) << 24) // Prefix byte of address 3 converted to nRF24L series format
      | ((uint32_t)swap_bits(0xC2) << 16) // Prefix byte of address 2 converted to nRF24L series format
      | ((uint32_t)swap_bits(0xC1) << 8)  // Prefix byte of address 1 converted to nRF24L series format
      | ((uint32_t)swap_bits(0xC0) << 0); // Prefix byte of address 0 converted to nRF24L series format

    radio->prefix[1] =
        ((uint32_t)swap_bits(0xC7) << 24) // Prefix byte of address 7 converted to nRF24L series format
      | ((uint32_t)swap_bits(0xC6) << 16) // Prefix byte of address 6 converted to nRF24L series format
      | ((uint32_t)swap_bits(0xC4) << 0); // Prefix byte of address 4 converted to nRF24L series format

    radio->base[0] = bytewise_bitswap(0x01234567UL);  // Base address for prefix 0 converted to nRF24L series format
    radio->base[1] = bytewise_bitswap(0x89ABCDEFUL);  // Base address for prefix 1-7 converted to nRF24L series format

    radio->txaddress   = 0x00UL;  // Set device address 0 to use when transmitting
    radio->rxaddresses = 0x01UL;  // Enable device address 0 to use to select which addresses to receive

    // Packet configuration
    radio->pcnf[0] = (PACKET_S1_FIELD_SIZE     << RADIO_PCNF0_S1LEN_SHIFT) |
                       (PACKET_S0_FIELD_SIZE     << RADIO_PCNF0_S0LEN_SHIFT) |
                       (PACKET_LENGTH_FIELD_SIZE << RADIO_PCNF0_LFLEN_SHIFT); //lint !e845 "The right argument to operator '|' is certain to be 0"

    // Packet configuration
    radio->pcnf[1] = (RADIO_PCNF1_WHITEEN_Disabled << RADIO_PCNF1_WHITEEN_SHIFT) |
                       (RADIO_PCNF1_ENDIAN_Big       << RADIO_PCNF1_ENDIAN_SHIFT)  |
                       (PACKET_BASE_ADDRESS_LENGTH   << RADIO_PCNF1_BALEN_SHIFT)   |
                       (PACKET_STATIC_LENGTH         << RADIO_PCNF1_STATLEN_SHIFT) |
                       (PACKET_PAYLOAD_MAXSIZE       << RADIO_PCNF1_MAXLEN_SHIFT); //lint !e845 "The right argument to operator '|' is certain to be 0"

    // CRC Config
    radio->crccnf = (RADIO_CRCCNF_LEN_Two << RADIO_CRCCNF_LEN_SHIFT); // Number of checksum bits
    if ((radio->crccnf & RADIO_CRCCNF_LEN_Msk) == (RADIO_CRCCNF_LEN_Two << RADIO_CRCCNF_LEN_SHIFT))
    {
        radio->crcinit = 0xFFFFUL;   // Initial value
        radio->crcpoly = 0x11021UL;  // CRC poly: x^16 + x^12^x^5 + 1
    }
    else if ((radio->crccnf& RADIO_CRCCNF_LEN_Msk) == (RADIO_CRCCNF_LEN_One << RADIO_CRCCNF_LEN_SHIFT))
    {
        radio->crcinit = 0xFFUL;   // Initial value
        radio->crcpoly = 0x107UL;  // CRC poly: x^8 + x^2^x^1 + 1
    }
    radio->packetptr= (uint32_t)&packet; 
}