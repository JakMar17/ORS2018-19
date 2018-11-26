/* Includes ------------------------------------------------------------------*/
#include "stm32f4_discovery.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int main(void)
{
	// init CLOCKS
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// init SYSCFG
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
        SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource2);

	// init NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
        
        NVIC_InitTypeDef NVIC_InitStructure1;
	NVIC_InitStructure1.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure1.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure1.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure1.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure1);

	// init EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
        
        EXTI_InitTypeDef EXTI_InitStructure1;
	EXTI_InitStructure1.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure1.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure1.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure1.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure1);

	// init LED
	GPIO_InitTypeDef led;
	led.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	led.GPIO_Mode = GPIO_Mode_OUT;
	led.GPIO_Speed = GPIO_Speed_2MHz;
	led.GPIO_OType = GPIO_OType_PP;
	led.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &led);

	// init BTN
	GPIO_InitTypeDef btn;
	btn.GPIO_Pin = GPIO_Pin_0;
	btn.GPIO_Mode = GPIO_Mode_IN;
	btn.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA, &btn);
        
        // init BTN
	GPIO_InitTypeDef btn1;
	btn.GPIO_Pin = GPIO_Pin_2;
	btn.GPIO_Mode = GPIO_Mode_IN;
	btn.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOB, &btn1);
	
	while (1)
	{
	}
}