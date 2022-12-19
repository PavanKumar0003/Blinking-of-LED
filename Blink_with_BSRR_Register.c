#include "stm32f407xx.h"

#define GPIOEN  (1U<<0)
#define PIN2    (1U<<6)
#define LED_PIN  PIN2

int main()
{
	RCC->AHB1ENR |= GPIOEN;
	GPIOA->MODER |= (1U<<12);
	GPIOA->MODER &= ~(1U<<13);



	while(1)
	{
		GPIOA->BSRR = LED_PIN;
		for(int i=0;i<=100000;i++){}

		GPIOA->BSRR = (1U<<22);
		for(int i=0;i<=100000;i++){}
	}
}
