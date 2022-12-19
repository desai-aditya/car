/*
 * @file: rtt.c -- real-time transfer for debugging
 *
 * @date: last updated 23 February 2021
 * 
 * @desc: this is the RTT client to run on the "device" side to interact with "host"
 *        -- RTT operates over a debug channel using a "control block" data structure
 *        -- multiple channels of input and output can be supported (up to 16) for multiplexing
 *        -- control block contains:
 *             ---- an array of "up" buffers for writing data to the host (buffer 0 ==> "terminal")
 *             ---- an array of "down" buffers for reading input from the host (buffer 0 ==> "terminal")
 *             ---- size of each up and down buffer array
 *             ---- an id that allows the RTT tool on "host" to identify the control block
 *        -- each up/down buffer is a ring buffer or circular array, meaning reads and writes wrap back to index 0
 *        -- each ring buffer maintains two indices for last written and last read entry
**/

#include <rtt.h>
#include <printk.h>

extern rtt_control_t __rtt_start;

static char up_buffer[BUFFER_SIZE_UP];
static char down_buffer[BUFFER_SIZE_DOWN];

/*
 * @brief: initialize control blocks, must be called before any other rtt ops
 * 
 * @note: this is provided for you and should not be changed in any way
 */
void rtt_init() {
  rtt_control_t* p;
  p = &__rtt_start;
  p->num_up_buffers = RTT_MAX_UP_BUFFERS;
  p->num_down_buffers = RTT_MAX_DOWN_BUFFERS;

  p->up_buffers[0].name = "Terminal";
  p->up_buffers[0].p_buffer = up_buffer;
  p->up_buffers[0].buffer_size = BUFFER_SIZE_UP;
  p->up_buffers[0].pos_rd = 0;
  p->up_buffers[0].pos_wr = 0;
  p->up_buffers[0].flags = 2;

  p->down_buffers[0].name = "Terminal";
  p->down_buffers[0].p_buffer = down_buffer;
  p->down_buffers[0].buffer_size = BUFFER_SIZE_DOWN;
  p->down_buffers[0].pos_rd = 0;
  p->down_buffers[0].pos_wr = 0;
  p->down_buffers[0].flags = 2;

  p->id[7] = 'R'; p->id[8] = 'T'; p->id[9] = 'T';
  RTT__DMB();
  p->id[0] = 'S'; p->id[1] = 'E'; p->id[2] = 'G'; p->id[3] = 'G'; p->id[4] = 'E'; p->id[5] = 'R';
  RTT__DMB();
  p->id[6] = ' ';
  RTT__DMB();
  p->id[10] = '\0'; p->id[11] = '\0'; p->id[12] = '\0'; p->id[13] = '\0'; p->id[14] = '\0'; p->id[15] = '\0';
  RTT__DMB();
}

/**
 * @brief pushes an array of unformatted characters into the 0th RTT up buffer, which the host will print to the console
 * any write operation will spin within a while loop any time the buffer is full, waiting until the host consumes the corresponding characters
 * to free up space
 *
 * @params[in]  index of up buffer used for writing
 * @params[in]  p_buffer Buffer that holds the input data
 * @params[in]  num_bytes number of bytes to write
 *
 * @return number of written bytes
 */
uint32_t rtt_write(uint32_t buffer_index, const void* p_buffer, uint32_t num_bytes) {
  (void)buffer_index;
  uint32_t count = 0;
  rtt_buffer_up_t* p;
  p = &__rtt_start.up_buffers[0];
  for (uint32_t i=0; i < num_bytes; i++){
    while ((p->pos_rd - p->pos_wr) == 1 || ((p->pos_wr == (p->buffer_size -1)) && (p->pos_rd == 0))) {
        // spinning for reader to move forward
    }
    p->p_buffer[p->pos_wr] = ((char*)p_buffer)[i];
    p->pos_wr = (p->pos_wr + 1) % p->buffer_size;
   
    count++;
  } 
  return count;
}

/**
 * @brief function that grabs characters from the host out of the 0th down buffer, for consumption by the device
 * read operation will spin any time the buffer is empty
 *
 * @params[in]  index of down buffer used for reading
 * @params[out]  p_buffer Buffer that stores the data read from rtt
 * @params[in]  num_bytes number of bytes in buffer
 *
 * @return number of read bytes
 */
uint32_t rtt_read(uint32_t buffer_index, void* p_buffer, uint32_t buffer_size) {
  (void)buffer_index;
  uint32_t count = 0;
  rtt_buffer_down_t* p;
  p = &__rtt_start.down_buffers[0];
  for (uint32_t i=0; i < buffer_size; i++){
    while ((p->pos_rd - p->pos_wr) == 1 || ((p->pos_wr == (p->buffer_size -1)) && (p->pos_rd == 0))) {
        // spinning for writer to move forward
    }
    ((char*)p_buffer)[i] = p->p_buffer[p->pos_rd];
    count++;
    p->pos_rd = (p->pos_rd + 1) % p->buffer_size;
  } 
  return count;
}

/**
 * @brief check if there is data currently in the down buffer (and how much)
 *
 * @params[in] index of down buffer used for reading
 * 
 * @return Number of bytes available to read
 */
uint32_t rtt_has_data(uint32_t buffer_index) {
  (void)buffer_index;
  uint32_t count = 0;
  rtt_buffer_down_t* p;
  p = &__rtt_start.down_buffers[0];
  if (p->pos_rd > p->pos_wr) {
    count = p->buffer_size - p->pos_rd + p->pos_wr;
  }
  else {
    count = p->pos_wr - p->pos_rd;
  }
  return count;
}