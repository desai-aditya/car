/** @file   mpu.h
 *
 *  @brief  prototypes for memory protection
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#ifndef _MPU_H_
#define _MPU_H_

#define KERNEL_REGION 6
#define USER_REGION 7

/** @enum   mpu_mode
 *  @brief  memory protection mode is PER_THREAD or KERNEL_ONLY
 */
typedef enum { PER_THREAD = 1, KERNEL_ONLY = 0 } mpu_mode;

/**
 * 
 * @brief This is used to round up the memory size that the user gives to a power of 2.
 * 
 * @param[in] the size in bytes
 * 
 * @return the ceiling of the log of the size in bytes (base 2)
 * 
 **/

uint32_t mm_log2ceil_size(uint32_t n);

/**
 * 
 * @brief is used to disable the memory region specified as an argument 
 * 
 * @param[in] number of the region to be disabled 
 * 
 * @return does not return
 * 
 **/

void mm_region_disable(uint32_t region_number);

/**
 * 
 * @brief This function is used to enable the memory region specified in thr argument. Once the MPU region
 * is enabled, then unauthorised threads cannot access it.
 * 
 * @param[in] number of the region to be enabled
 * @param[in] pointer to the base address of the region
 * @param[in] log (base 2) of the size of that region 
 * @param[in] execute bit to indicate if the region is executable or not
 * @param[in] indication if the region is writeable by the user or not
 * 
 * @return 0 on success and -1 on failure
 * 
 **/

int mm_region_enable(uint32_t region_number, void *base_address, uint8_t size_log2, int execute, int user_write_access);

/**
 * 
 * @brief This function performs the necessary handshaking which is needed to initialse and enable
 * the MPU in the system. It is defined in kernel main.
 * 
 * @param[in] no input paramters
 * 
 * @return does not return 
 * 
 **/


void mpu_init();

#endif /* _MPU_H_ */
