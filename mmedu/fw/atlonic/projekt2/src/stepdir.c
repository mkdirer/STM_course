/*
 * stepdir.c
 *
 *  Created on: 27 cze 2016
 *      Author: £ukasz Krzyœciak
 */
#include "stm32f30x.h"
#include "stepdir.h"

void STEPDIR_Config(void){
	GPIO_InitTypeDef   GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOD, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);//step3 PC8
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16,ENABLE);//step2 PB4
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17,ENABLE);//step1 PB5

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);//counter step1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM15,ENABLE);//counter step2
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM20,ENABLE);//counter step3

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_Init(GPIOB,&GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5,GPIO_AF_10);//tim17 ch1
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource4,GPIO_AF_1);//tim16 ch1

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOC,&GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOC,GPIO_PinSource8,GPIO_AF_4);//tim8 ch3

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_15;//dir1 PA8 //dir2 PA15
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//dir3 PC9
    GPIO_Init(GPIOC,&GPIO_InitStructure);


    //--------------------------------------------------------------------------------------------------------
    //step1 TIM17
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = 1000;
    TIM_TimeBaseStructure.TIM_Prescaler = 250;
    TIM_TimeBaseInit(TIM17,&TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 500;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OC1Init(TIM17, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM17, TIM_OCPreload_Enable);
    SYSCFG->CFGR1 |= SYSCFG_CFGR1_TIM1_ITR3_RMP;//remap

    //licznik1 TIM1
    TIM_TimeBaseStructure.TIM_Period = 1000;
    //TIM_TimeBaseStructure.TIM_Period = 1;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);

    TIM_SelectSlaveMode(TIM1,TIM_SlaveMode_External1);
    TIM_SelectInputTrigger(TIM1,TIM_TS_ITR3);

    //TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);

   TIM_CtrlPWMOutputs(TIM17,ENABLE);
   //TIM_Cmd(TIM17,ENABLE);  //uncomment to run

   TIM_Cmd(TIM1,ENABLE);
   //--------------------------------------------------------------------------------------------------------

   //step2 TIM16
       TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
       TIM_TimeBaseStructure.TIM_Period = 1000;
       TIM_TimeBaseStructure.TIM_Prescaler = 250;
       TIM_TimeBaseInit(TIM16,&TIM_TimeBaseStructure);

       TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
       TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
       TIM_OCInitStructure.TIM_Pulse = 500;
       TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
       TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
       TIM_OC1Init(TIM16, &TIM_OCInitStructure);
       TIM_OC1PreloadConfig(TIM16, TIM_OCPreload_Enable);

       //licznik2 TIM15
       TIM_TimeBaseStructure.TIM_Period = 65535;
       TIM_TimeBaseStructure.TIM_Prescaler = 0;
       TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
       TIM_TimeBaseInit(TIM15,&TIM_TimeBaseStructure);

       TIM_SelectSlaveMode(TIM15,TIM_SlaveMode_External1);
       TIM_SelectInputTrigger(TIM15,TIM_TS_ITR2);

      TIM_CtrlPWMOutputs(TIM16,ENABLE);
      //TIM_Cmd(TIM16,ENABLE);

      TIM_Cmd(TIM15,ENABLE);
      //--------------------------------------------------------------------------------------------------------


      //step3 TIM8
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
          TIM_TimeBaseStructure.TIM_Period = 1000;
          TIM_TimeBaseStructure.TIM_Prescaler = 250;
          TIM_TimeBaseInit(TIM8,&TIM_TimeBaseStructure);

          TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
          TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
          TIM_OCInitStructure.TIM_Pulse = 500;
          TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
          TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
          TIM_OC3Init(TIM8, &TIM_OCInitStructure);
          TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);
          TIM_SelectOutputTrigger(TIM8,TIM_TRGOSource_OC3Ref);

          //licznik3 TIM20
          TIM_TimeBaseStructure.TIM_Period = 65535;
          TIM_TimeBaseStructure.TIM_Prescaler = 0;
          TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
          TIM_TimeBaseInit(TIM20,&TIM_TimeBaseStructure);

          TIM_SelectSlaveMode(TIM20,TIM_SlaveMode_External1);
          TIM_SelectInputTrigger(TIM20,TIM_TS_ITR1);


         TIM_CtrlPWMOutputs(TIM8,ENABLE);
         //TIM_Cmd(TIM8,ENABLE);

         TIM_Cmd(TIM20,ENABLE);
         //--------------------------------------------------------------------------------------------------------


}
void STEPDIR_Control()
{
	//testing of stepdir1
	if((uint16_t)TIM1->CNT>1000)
	{
		TIM1->CR1 |= TIM_CR1_DIR;//counter down
		GPIO_SetBits(DIR1_PORT,DIR1_PIN);
	}
	if((uint16_t)TIM1->CNT<10)
	{
		TIM1->CR1 &=~ TIM_CR1_DIR;//counter up
		GPIO_ResetBits(DIR1_PORT,DIR1_PIN);
	}

}
