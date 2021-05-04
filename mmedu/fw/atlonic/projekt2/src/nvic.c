/*
 * nvic.c
 *
 *  Created on: 19 lip 2016
 *      Author: £ukasz Krzyœciak
 */

#include "stm32f30x.h"
#include "nvic.h"
#include "io.h"

uint8_t interruptNr;
void NVIC_Config()
{
	#ifdef  VECT_TAB_RAM
	NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
	#else  /* VECT_TAB_FLASH  */
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	#endif

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	NVIC_InitTypeDef NVIC_InitStructure;

	SysTick_Config(9000000);

			//Runtime
	        NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	        NVIC_Init(&NVIC_InitStructure);

	        NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	        NVIC_Init(&NVIC_InitStructure);

	        NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	        NVIC_Init(&NVIC_InitStructure);


}
void SysTick_Handler()
{
	static uint8_t exceed;
	static uint32_t a;
	if(a==7){ a=0;  TIM2->CNT++;}
	else
		a++;

	if(a == 0xFFFFFFFF){ exceed++; a=0;}
	//exceed*0xFFFFFFFF + a; //runtime(sec)
}

void TIM3_IRQHandler(void)//enc1
{
	if(TIM_GetITStatus(TIM3, TIM_IT_CC3) == SET)
	    {
	        TIM_ClearITPendingBit(TIM4, TIM_IT_CC3);

	    }

}
void TIM4_IRQHandler(void)//enc2
{
	if(TIM_GetITStatus(TIM4, TIM_IT_CC4) == SET)
	    {
	        TIM_ClearITPendingBit(TIM4, TIM_IT_CC4);

	    }
}
