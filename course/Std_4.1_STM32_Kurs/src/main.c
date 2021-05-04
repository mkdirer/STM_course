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

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);

 GPIO_StructInit(&gpio);
 gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
 GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
 gpio.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOC, &gpio);

 gpio.GPIO_Pin = GPIO_Pin_13; // konfigurujemy pin 13
 gpio.GPIO_Mode = GPIO_Mode_IPU; // jako wejscie z rezystorem pull-up
 GPIO_Init(GPIOC, &gpio); // port GPIOC


 SysTick_Config(SystemCoreClock / 1000);

 uint32_t led = 0;
 while (1) {
	 if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0) {
 GPIO_SetBits(GPIOC, 1 << led); // zapal diode
 delay_ms(150); // poczekaj
 GPIO_ResetBits(GPIOC, 1 << led); // zgas diode
 if (++led >= 10) { // przejdz do nastepnej
 led = 0;
 }
	 }else {
	 GPIO_SetBits(GPIOC, 1 << led); // zapal diode
	  delay_ms(150); // poczekaj
	  GPIO_ResetBits(GPIOC, 1 << led); // zgas diode
	  if (--led <= 0) { // przejdz do nastepnej
	  led = 10;}
	 }
 }
}
