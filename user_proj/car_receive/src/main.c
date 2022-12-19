/** @file   default/main.c
 *
 *  @brief  user-space project "default", demonstrates system call use
 *  @note   Not for public release, do not share
 *
 *  @date   last modified 11 October 2022
 *  @author CMU 14-642
 *
 *  @output repeatedly prints provided argument to console
**/

#include <stdio.h>
#include<lib642.h>
#include<stdlib.h>
#include <unistd.h>

#define USR_STACK_WORDS 256
#define NUM_THREADS 4
#define NUM_MUTEXES 1
#define CLOCK_FREQUENCY 1000

char user_in[16];
mutex_t* mutex_0;

/**
 * 
 * @brief This is the function that takes input from the user via RTT. Based on the commands given by the user
 * this function will take the necessary actions and execute those commands.
 * 
 * @params[in] unused void pointer
 * 
 * @return none
 * 
 */

void user_input(UNUSED void* vargp) {
        int cnt = 0;
        char input[16];
        char data[16];
        int di = 0;

        while (1) {
                while ((cnt = read(0, input, 16)) > 0) {
                       //printf("read the data = %s read bytes = %d\n", input, cnt);
                       for (int i = 0; i < cnt; i++) {
                           if (input[i] != '\r') {
                               data[di] = input[i];
                               di++;
                           }
                       }
                       if ((input[cnt-1] == '\r') && (di != 0)) {
                                mutex_lock(mutex_0);
                                for (int i = 0; i < di; i++) {
                                        user_in[i] = data[i];                                        
                                }
                                user_in[di] = '\0';
                                printf("User Action: %s\n", user_in);
                                // release lock here
                                di = 0;
                                mutex_unlock(mutex_0);
                                if (user_in[0] == 'e') {
                                    return;
                                }

                       }
                }
        }
}

/**
 * 
 * @brief This thread is used to move the car based on the user input. It is schedule periodically
 * by the RMS scheduler and the car is moved accordingly.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */


void move_car() {
    while(1){
        recv_radio_packet(user_in,-1);
        if(user_in[0] == 'f') {
            forward();
            stop();
        }
        else if(user_in[0] == 'b') {
            backward();
            stop();
        }
        else if(user_in[0] == 'l') {
            left();
            stop();
        }
        else if(user_in[0] == 'r') {
            right();
            stop();
        }
        else if(user_in[0] == 'e') {
            //stop spinning and return
            stop();
            return;
        }
        else {
            //stop spinning
            stop();
        }
    }
}

/**
 * 
 * @brief This function is a thread that runs periodically and keeps printing escape sequences
 * on the console output. This is used so that the user gets to enter at the beginning index
 * of the console output.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void keep_printing() {
        //char backspace = 0x8;
        while (1)
        {
                printf("|\r\f");
                printf("\b\b\b \b");
                //printf("|");
                if (user_in[0] == 'e') {
                    return;
                }
                wait_until_next_period();
        }
        
}

/**
 * 
 * @brief This is a thread that runs periodically in order to be able to glow the 
 * on board LEDs. The red and green LEDs are toggles based on the user input.
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void glow_onboard_leds() {
        while (1) {
            if (user_in[0] == 'g') {
                led_glow(1);
            }
            else if (user_in[0] == 'e') {
                // turn off led
                led_glow(0);
                return;
            }
            else {
                // turn off led
                led_glow(0);
            }
            wait_until_next_period();
        }
}

/**
 * 
 * @brief This function is used to make the neopixel dance. This function is used to take an input
 * from the user asking whether to start or stop a dance party. Based on the input, the party starts!
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */


void neo_dance() {
        while(1) {
            if (user_in[0] == 'd') {
                pix_set(1);
            }
            else if (user_in[0] == 'e') {
                // turn off neo dance
                pix_set(0);
                return;
	    }
            else {
                // turn off the neo pix
                pix_set(0);
            }
            wait_until_next_period();
        }
}

/**
 * 
 * @brief This is the user space idle thread 
 * 
 * @params[in] none
 * 
 * @return none
 * 
 */

void idle() {
	while(1);
}

#define UNUSED __attribute__((unused))

/**
 * 
 * @brief This is our main function which schedules the threads. The scheduler is 
 * based on RMS and PCP and will schedule the threads periodically after initialising 
 * and checking if the given set of threads are schedulable.
 * 
 */

int main(UNUSED int argc, UNUSED char* const argv[]) {

	// uint8_t pixel = 0;

        ABORT_ON_ERROR(thread_init(NUM_THREADS, USR_STACK_WORDS, NULL, KERNEL_ONLY, NUM_MUTEXES));

        printf("Successfully initialized threads...\n");

        mutex_0 = mutex_init(0);

	if(mutex_0 == NULL) {
		printf("Failed to create mutex\n");
		return -1;
	}


        // ABORT_ON_ERROR(thread_create(&user_input, 2, 75, 500, NULL));
        // //ABORT_ON_ERROR(thread_create(&keep_printing, 3, 50, 500, NULL));
        // ABORT_ON_ERROR(thread_create(&glow_onboard_leds, 1, 20, 250, NULL));
        // ABORT_ON_ERROR(thread_create(&neo_dance, 0, 100, 500, NULL));
        ABORT_ON_ERROR(thread_create(&move_car, 3, 100, 500, NULL));

        printf("Successfully created threads! Starting scheduler...\n");
        
        printf("Type the following instructions to see the working:\n 1. 'dance' to start dance party\n 2. 'glow' to light up leds\n 3. 'pause' to pause the running function \n 4. 'forward' to move car forward \n 5. 'back' to move car backward \n 6. 'left' to move car to left \n 7. 'right' to move car to right \n 8. 'exit' to exit application\n");
        
	ABORT_ON_ERROR(scheduler_start(CLOCK_FREQUENCY), "Threads are unschedulable!\n");

	return 0;
}