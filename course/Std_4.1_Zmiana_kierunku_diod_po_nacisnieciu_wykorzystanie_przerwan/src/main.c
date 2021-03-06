/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f10x.h"

volatile uint32_t timer_ms = 0;
volatile int8_t kierunek = 1;

void EXTI15_10_IRQHandler()
{
	if (EXTI_GetITStatus(EXTI_Line13)) {
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0) {
		  kierunek = -kierunek;
		}

		EXTI_ClearITPendingBit(EXTI_Line13);
	}
}

void SysTick_Handler()
{
	if (timer_ms) {
		timer_ms--;
	}
}

void delay_ms(int time)
{
	timer_ms = time;
	while (timer_ms) {};
}

int main(void)
{
	GPIO_InitTypeDef gpio;
	EXTI_InitTypeDef exti;
	NVIC_InitTypeDef nvic;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
					GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &gpio);

	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &gpio);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);

	EXTI_StructInit(&exti);
	exti.EXTI_Line = EXTI_Line13;
	exti.EXTI_Mode = EXTI_Mode_Interrupt;
	exti.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	exti.EXTI_LineCmd = ENABLE;
	EXTI_Init(&exti);

	nvic.NVIC_IRQChannel = EXTI15_10_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0x00;
	nvic.NVIC_IRQChannelSubPriority = 0x00;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);

	SysTick_Config(SystemCoreClock / 1000);

	int8_t led = 0;
	while (1) {
		GPIO_SetBits(GPIOC, 1 << led); // zapal diode
		delay_ms(150); // poczekaj
		GPIO_ResetBits(GPIOC, 1 << led); // zgas diode
		led += kierunek; //to to samo co led = led + kierunek
		if (led >= 10) { // przejdz do nastepnej
			led = 0;
		} else if (led < 0) {
			led = 9;
		}
	}
}
