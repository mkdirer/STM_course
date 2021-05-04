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

void delay(int time)
{
	int i;
	for(i = 0; i < time * 4000; i++){}
}

int main(void)
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_5;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &gpio);

	while (1) {
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		delay(2000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		delay(500);
	}
}
