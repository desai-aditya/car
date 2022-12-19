## Lab 5: Choose your Own Adventure
### Path I: Create Your Own Application 

## Design Plan

We are trying to create a toy car that can do the following
- Take user input to start one of the following tasks
- Move the car forward, backward, left and right
- Blink red and blue parking lights 
- Host a dance party
- If a new task is started the previous running task is paused
- User can exit/turn off the car

## Demo video
[Here is our demo video](https://drive.google.com/file/d/1ZYJbOfevjzFRe6DD2uvJBtv1h_RAqzDl/view?usp=share_link)

## Hardware prerequisites
- Adafruit nrf54280 - x1
- MAX9814 Audio amplifier + microphone by Adafruit - x1
- DC motors - x2
- DRV8833 motor driver - x1

## Setting up the device and peripherals
![Circuit Diagram](https://github.com/cmu14642/f22-lab5-nerds/blob/peripherals/CircuitDiagram.jpg)

## How to run the application
```bash
git clone git@github.com:cmu14642/f22-lab5-nerds.git
git checkout peripherals
sudo picocom -c --imap lfcrlf /dev/ttyBmpCon
cd f22-lab5-nerds
make run
```
User can interact with the car interface using picocom terminal and provide inputs as shown in the instructions

## Implementation Details

The services are running in 4 threads that implement the following functions
- user_input() : This thread is always running and looking for user input and performs state management. 
The method assumes that user is done giving input when enter is pressed. Once user presses enter this thread 
will perform application state management and update the global variable user_in[] to ensure the updated 
state/input is shared with all the threads.

- move_car() : If user provides inputs like 'forward', 'backward', 'left' or 'right', this thread will automatically unblock and 
execute the requested operation. The connected DC motor will perform the rotation accordingly.

- glow_onboard_leds() : When user gives input like 'glow' the on board LEDs will start blinking. These are our parking lights.

- neo_dance() : When user gives input like 'dance' a dance party will be started. This means neo pixel
will flash different colors based on the frequency of music being played.

Other features:
- If user gives input like 'pause' the currently running operation will stop and the car will just wait for new
instructions.
- If user gives input like 'exit' the car will free up all its resources, clean up its threads and stop.

## Hardware interfacing details and references
- [Link to DRV8833 datasheet](https://www.ti.com/lit/ds/symlink/drv8833.pdf?ts=1670851510530)
- [Link to Neopixel Datasheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf)
- [Link to DC motor datasheet](https://www.adafruit.com/product/3777)
- [Link to MAX9814 datasheet](https://cdn-shop.adafruit.com/datasheets/MAX9814.pdf)
- [Link to microphone spec](https://cdn-shop.adafruit.com/datasheets/CMA-4544PF-W.pdf)

## Suggested grading rubric
- Hardware configuration for 2 DC motors and a microphone + circuit 40
- Custom system calls 20
- Thread implementation 20
- Idle thread and main thread 10
- Profiling and Cis 15
- Periods Ti and Priorities 15
