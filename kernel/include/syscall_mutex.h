/** @file   syscall.h
 *
 *  @brief  prototypes for system calls to support mutexes for lab 4
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 25 October 2022
 *  @author CMU 14-642
**/

#ifndef _SYSCALL_MUTEX_H_
#define _SYSCALL_MUTEX_H_

#include <unistd.h>
#include <stdint.h>
#include <syscall_thread.h>
#define UNLOCKED ((uint32_t)-1)

/**
 * 
 * This is the definition of the mutex structure. We store the ID of the thread that is currently 
 * locking the mutex, followed by the priority ceiling which indicate the highest priority thread's priority 
 * that can lock the mutex. We also maintain a linked list of mutexes to store which mutex is held by
 * which thread. We also maintain a linked list of the TCBs which are waiting for the mutex.
 * The structure also contains the current value of the highest priority.
 */

/**
 * @brief      The struct for a mutex.
 */
typedef struct kmutex_t {
  volatile uint32_t locked_by; // ID of the thread that is currently holding the mutex /
  volatile uint32_t prio_ceil; // this is passed by the thread, indicating the max static prio of a task that will use this shared resource /
  // tcb_t* owner; // current owner of the mutex /
  struct tcb* owner; // current owner of the mutex /
  struct kmutex_t* next; // pointer to the next mutex in the linked list /
  // tcb_t* waiting_threads; // list of the threads which are waiting to be scheduled /
  struct tcb_t* waiting_threads; // list of the threads which are waiting to be scheduled /
  volatile uint32_t current_max_priority; // maximum priority of the thread /
} kmutex_t;

/**
 * @brief      Used to create a mutex object. The mutex resides in kernel
 *             space. The user receives a handle to it. With memory
 *             protection, the user cannot modify it. However,
 *             tt can still be passed around and used with
 *             lock, unlock.
 *
 * @param      max_prio  The maximum priority of a thread which could use
 *                       this mutex.
 *
 * @return     A pointer to the mutex. NULL if max_mutexes would be exceeded.
 */
kmutex_t* sys_mutex_init(uint32_t max_prio);

/**
 * @brief      Lock a mutex
 *
 *             This function will not return until the current thread has
 *             obtained the mutex.
 *
 * @param[in]  mutex  The mutex to act on.
 */
void sys_mutex_lock(kmutex_t* mutex);

/**
 * @brief      Unlock a mutex
 *
 * @param[in]  mutex  The mutex to act on.
 */
void sys_mutex_unlock(kmutex_t* mutex);

#endif /* _SYSCALL_MUTEX_H_ */
