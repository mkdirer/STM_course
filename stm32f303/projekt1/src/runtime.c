#include "stm32f30x.h"
#include "runtime.h"


void RUNTIME_Config()
{
	//Przerwanie od Systicka inkrementuje licznik TIM2->CNT
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	//TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	//TIM2->CNT=0;
	//TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	//TIM_TimeBaseStructure.TIM_Period = 100000;
	//TIM_TimeBaseStructure.TIM_Prescaler = 36000;
	//TIM_TimeBaseStructure.TIM_ClockDivision = 36000;
	//TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

	//TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	//TIM_Cmd(TIM2,ENABLE);

}




