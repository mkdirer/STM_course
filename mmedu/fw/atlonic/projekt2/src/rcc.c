/*
 * rcc.c
 *
 *  Created on: 19 lip 2016
 *      Author: £ukasz Krzyœciak
 */
#include "stm32f30x.h"
#include "rcc.h"

void RCC_Config()
{
	RCC_DeInit();

	 	ErrorStatus HSEStartUpStatus;
	 	RCC_HSEConfig(RCC_HSE_ON);
	 	HSEStartUpStatus = RCC_WaitForHSEStartUp();

	 	if (HSEStartUpStatus == SUCCESS)
	 		{
			FLASH_SetLatency(FLASH_Latency_2);
			FLASH_PrefetchBufferCmd(ENABLE);
			RCC_HCLKConfig(RCC_SYSCLK_Div1);
			RCC_PCLK2Config(RCC_HCLK_Div1);
			RCC_PCLK1Config(RCC_HCLK_Div2);
			RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_9);//72MHZ
			RCC_PLLCmd(ENABLE);
			while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {
			}
	 	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	 	while (RCC_GetSYSCLKSource() != 0x08) {
	 	}
	 		}
}
