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

volatile uint32_t timer_ms = 0;
volatile int8_t kierunek = 1;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0) {
			  kierunek = -kierunek;}

}

int main(void)
{
SystemCoreClock = 8000000;
HAL_Init();

__HAL_RCC_GPIOA_CLK_ENABLE();
__HAL_RCC_GPIOC_CLK_ENABLE();

GPIO_InitTypeDef gpio; // obiekt gpio b?d?cy konfiguracj? port?w GPIO
   gpio.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|
   GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
   gpio.Mode = GPIO_MODE_OUTPUT_PP; // jako wyj?cie
   gpio.Pull = GPIO_NOPULL; // rezystory podci?gaj?ce s? wy??czone
   gpio.Speed = GPIO_SPEED_FREQ_LOW; // wystarcz? nieskie cz?stotliwo?ci prze??czania
   HAL_GPIO_Init(GPIOC, &gpio); // inicjalizacja modu?u GPIOC

gpio.Mode = GPIO_MODE_IT_RISING_FALLING;
gpio.Pull = GPIO_PULLUP;
gpio.Pin = GPIO_PIN_13;
HAL_GPIO_Init(GPIOC, &gpio);
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

int8_t led = 0;
   while (1) {
      HAL_GPIO_WritePin(GPIOC, 1 << led, GPIO_PIN_SET); //w??cz diode
      HAL_Delay(500);
      HAL_GPIO_WritePin(GPIOC, 1 << led, GPIO_PIN_RESET); //wy??cz diode
      led += kierunek; //to to samo co led = led + kierunek
      		if (led >= 10) { // przejdz do nastepnej
      			led = 0;
      		} else if (led < 0) {
      			led = 9;
      		}
   }
}
