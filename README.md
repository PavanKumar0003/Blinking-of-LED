# Project-1 Blinking-of-LED
// Program is written in Embedded-C using STM32 IDE
Target MicroController --> STM32F407VET6
D2 Onboard LED --> (PA6) 
![STM32F407VET6_STM32_F4VE_V2 0-1](https://user-images.githubusercontent.com/107934117/208341683-b5d432e0-44c0-485c-aebb-9b5fe58eb4c4.jpg)
Task: Blinking of LED using GPIO-A registers and RCC registers. The D2 onboard LED is connected to GPIO-A, Pin-6. RCC provied clock source to all the peripherals in the chip.

Step-1: define all the register OFFSET and BASE addresses of RCC and GPIO-A
Step-2: define GPIO-A pin 6 address
Step-3: In main function, enable the clock source to GPIO-A and Provied the Pin number to Mode-R register of GPIO-A
Step-4: In while loop, Turn-ON The LED and Turn-OFF the LED.
Step-5: Creat a for loop insted of using Delay function. This for loop acts as Delay because of the number of loop iterations.
Step-6: Build the Project.
Step-7: Run the Project.


# More Details about the Board
https://stm32-base.org/boards/STM32F407VET6-STM32-F4VE-V2.0.html#USB-connector
