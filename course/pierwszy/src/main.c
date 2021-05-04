/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f1xx.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // zmieñ stan diody
}

int main(void)
{
 SystemCoreClock = 8000000; // taktowanie 8Mhz

 HAL_Init();

 __HAL_RCC_GPIOA_CLK_ENABLE();
 __HAL_RCC_GPIOC_CLK_ENABLE();

 GPIO_InitTypeDef gpio;
 gpio.Mode = GPIO_MODE_OUTPUT_PP;
 gpio.Pull = GPIO_NOPULL;
 gpio.Pin = GPIO_PIN_5;
 gpio.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(GPIOA, &gpio);

 gpio.Mode = GPIO_MODE_IT_RISING;
 gpio.Pull = GPIO_PULLUP;
 gpio.Pin = GPIO_PIN_13;
 HAL_GPIO_Init(GPIOC, &gpio);

 HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

 while (1)
 {
	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // zapalenie diody
	 HAL_Delay(1000);
	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // zgaszenie diody
	 HAL_Delay(500);
 }
}
