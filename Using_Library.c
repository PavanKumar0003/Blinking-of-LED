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
		GPIOA->ODR ^= LED_PIN;
		for(int i=0;i<=70000;i++){}
	}
}
