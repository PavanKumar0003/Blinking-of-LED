//if the Button is pushed then Turn ON the LED else Turn OFF the LED

#include "stm32f407xx.h"

#define GPIOAEN  (1U<<0)
#define GPIOEEN  (1U<<4)
#define PIN2    (1U<<6)
#define PIN3    (1U<<3)

#define LED_PIN  PIN2
#define BTN_PIN  PIN3

int main()
{
	/*Clock Supply to output led and Input button*/

	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOEEN;

	GPIOA->MODER |= (1U<<12);
	GPIOA->MODER &= ~(1U<<13);

	GPIOE->MODER &= ~(1U<<6);
	GPIOE->MODER &= ~(1U<<7);



	while(1)
	{
		if(GPIOE->IDR & BTN_PIN)
		{
			GPIOA->BSRR = LED_PIN;
		}
		else if(!(GPIOE->IDR & BTN_PIN))
		{
			GPIOA->BSRR = (1U<<22);
		}
	}
}
