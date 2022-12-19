/*
 * LED Test
 */
#include <stdint.h>
/* AHB for GPIO reg addresses*/

#define PERIF_BASE      (0x40000000UL)              // PERIFERAL BASE ADDRESS

#define AHB1_OFFSET     (0x00020000UL)              //AHB1 BUS OFFSET ADDRESS
#define AHB1_BASE       (PERIF_BASE + AHB1_OFFSET)  //0x40000000UL + 0x00020000UL = 0x40020000UL

#define GPIOA_OFFSET    (0x0000U)                   //GPIO_A OFFSET ADDRESS
#define GPIOA_BASE      (AHB1_BASE + GPIOA_OFFSET)  //0x40020000UL + 0x0000U = 0x40020000UL

/* Reset Clk Control reg addresses*/

#define RCC_OFFSET        	    (0x00003800)
#define RCC_BASE           	    (AHB1_BASE + RCC_OFFSET)    // 0x40020000UL + (0x00003800) = (0x4002 3800)

//#define RCC_AHB1ENR_OFFSET      (0x30UL)
//#define RCC_AHB1ENR_R           (*(volatile unsigned int*)(RCC_BASE + RCC_AHB1ENR_OFFSET)) // (0x4002 3800) + (0x30)

#define GPIOEN             		(1U<<0)   // ENABLE RCC CLK TO GPIO-A

/* GPIO registers and  address  */

//#define MODER_OFFSET        (0x00UL)
//#define GPIOA_MODER_R       (*(volatile unsigned int*)(MODER_OFFSET + GPIOA_BASE))
//
//#define GPIOA_ODR_OFFSET    (0x14UL)
//#define GPIOA_OD_R          (*(volatile unsigned int*)(GPIOA_ODR_OFFSET + GPIOA_BASE))

#define PIN                 (1UL<<6)    // Port-A and Pin-6 (PA-6)
#define LED_PIN              PIN


typedef struct

{
	volatile uint32_t MODER;      //Address offset ------ 0x00
	volatile uint32_t DUMMY[4];   // Address offset dummy reg
	volatile uint32_t ODR;        //Address offset ------ 0x14

} GPIOA_TypeDef;

typedef struct

{
	volatile uint32_t DUMMY[12];   // Address offset dummy reg
	volatile uint32_t AHB1ENR;        //Address offset ------ 0x14

} RCC_TypeDef;


#define GPIO_A           ((GPIOA_TypeDef*)GPIOA_BASE)
#define RCC              ((RCC_TypeDef*)RCC_BASE)

/*
 * (1U<<12)   SET BIT 12 TO 1
 * &= ~(1U<<13)  SET BIT 13 TO 0
 */

int main(void)
{
	/* 1.enable clk access to gpio-A
	 * 2. set PA6 to O/P
	 * */

//	RCC_AHB1ENR_R |= GPIOEN ;
//	GPIOA_MODER_R |= (1U<<12);
//	GPIOA_MODER_R &= ~(1U<<13);

	RCC->AHB1ENR  |= GPIOEN;
	GPIO_A->MODER |= (1U<<12);
	GPIO_A->MODER &= ~(1U<<13);

	while(1)
	{
		/* 3.set PA6 HIGH*/
		//GPIOA_OD_R ^= LED_PIN;

		GPIO_A->ODR ^= LED_PIN;
		for(int i=0;i<1000000;i++){}

	}

}
