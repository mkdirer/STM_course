/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f30x.h"
//#include "rcc.h"
//#include "nvic.h"
//#include "runtime.h"
//#include "usb.h"
//#include "io.h"
//#include "stepdir.h"
//#include "aio.h"
//#include "rs232.h"
//#include "encoder.h"
//USB functions

void RCC_Conf(void)
{
	ErrorStatus HSEStartUpStatus;
	//Reset ustawien RCC
	RCC_DeInit();

	//Wlacz HSE
	RCC_HSEConfig(RCC_HSE_ON);

	//Czekaj az HRS bedzie gotowy
	HSEStartUpStatus == RCC_WaitForHSEStartUp();
	if(HSEStartUpStatus == SUCCESS){
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK2Config(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_SYSCLK_Div2);
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
		RCC_PLLCmd(ENABLE);
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08);

	}
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_SPI1, ENABLE);
}

void GPIO_Conf(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}





