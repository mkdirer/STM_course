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

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
					GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &gpio);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);

	SysTick_Config(SystemCoreClock / 1000);

	uint8_t led = 0;
	uint8_t stan = 0;
	uint8_t stan9 = 0;
	GPIO_SetBits(GPIOC, 358);
	delay_ms(1000);
	while (1) {
		stan9 = GPIO_ReadOutputDataBit(GPIOC, 1 << 9);
		for (led = 9; led > 0; led--) {
		  stan = GPIO_ReadOutputDataBit(GPIOC, 1 << (led - 1));
		  if (stan == 1) {
		    GPIO_SetBits(GPIOC, 1 << led);
		  } else {
			GPIO_ResetBits(GPIOC, 1 << led);
		  }
		}
		if (stan9 == 1) {
		  GPIO_SetBits(GPIOC, 1);
        } else {
		  GPIO_ResetBits(GPIOC, 1);
	    }
		delay_ms(1000);
	}
}
