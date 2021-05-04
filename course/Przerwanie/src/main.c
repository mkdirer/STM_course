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

 gpio.Mode = GPIO_MODE_IT_RISING_FALLING; //lub samo RISING albo FALLING
 gpio.Pull = GPIO_PULLUP;
 gpio.Pin = GPIO_PIN_13;
 HAL_GPIO_Init(GPIOC, &gpio);

 HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
 //Nale¿y dopisaæ funkcjê do pliku stm32f1xx_it.c , która po³¹czy
 //przerwanie sprzêtowe EXTI15_10_IRQn z HAL.
 //Kod takiej funkcji wygl¹da nastêpuj¹co:
 //void EXTI15_10_IRQHandler(void)
 //{
  //HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
 //}
 while (1)
 {
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // zapalenie diody
 HAL_Delay(2000);
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // zgaszenie diody
 HAL_Delay(500);
 }
}
