#include "stm32f30x.h"
#include "io.h"
void OUT_DIG_Config(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);

	GPIO_InitTypeDef   GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //y1 |y2
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; //y3 |y4
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_15; //y5 |y6 | y7 | y8 | y9 | y10
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
void IN_DIG_Config(void)
{
	// IN0 PC0 X2
	// IN1 PC1 X1
	// IN2 PD2 X11
	// IN3 PB3 X10
	// IN4 PC4 X4
	// IN5 PC5 X5
	// IN6 PB6 X9
	// IN7 PB7 X8
	// IN8 PB8 X7
	// IN9 PB9 X6
	// IN10 PC10 X14
	// IN11 PC11 X13
	// IN12 PC12 X12
	// IN13 PC13 X3

	GPIO_InitTypeDef Gpio_InitStructure;
	//EXTI_InitTypeDef EXTI_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);

	GPIO_StructInit(&Gpio_InitStructure);
	Gpio_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	Gpio_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	Gpio_InitStructure.GPIO_OType = GPIO_OType_PP;
	Gpio_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	Gpio_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 ;
	GPIO_Init(GPIOC, &Gpio_InitStructure);

	Gpio_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOD, &Gpio_InitStructure);

	Gpio_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Init(GPIOB, &Gpio_InitStructure);
/*
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource1);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource2);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource4);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource5);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource6);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource7);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource8);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource9);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource10);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource11);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource12);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13);
*/
	//SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI12_PC;
	//SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

	//GPIO_PinAFConfig(GPIOC,GPIO_PinSource12,GPIO_AF_1);
	//GPIO_PinAFConfig(GPIOC,GPIO_PinSource13,GPIO_AF_1);
/*	EXTI_DeInit();

	EXTI_InitStructure.EXTI_Line =EXTI_Line0 | EXTI_Line1|EXTI_Line2|EXTI_Line3|EXTI_Line4|EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line8|EXTI_Line9|EXTI_Line10|EXTI_Line11|EXTI_Line12|EXTI_Line13;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);






	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI2_TS_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);
*/


}
void Set_Dout(uint8_t a)
{
	if(a == 1) GPIO_SetBits(GPIOC,GPIO_Pin_2);
	if(a == 2) GPIO_SetBits(GPIOC,GPIO_Pin_3);
	if(a == 3) GPIO_SetBits(GPIOA,GPIO_Pin_0);
	if(a == 4) GPIO_SetBits(GPIOA,GPIO_Pin_1);
	if(a == 5) GPIO_SetBits(GPIOB,GPIO_Pin_0);
	if(a == 6) GPIO_SetBits(GPIOB,GPIO_Pin_1);
	if(a == 7) GPIO_SetBits(GPIOB,GPIO_Pin_2);
	if(a == 8) GPIO_SetBits(GPIOB,GPIO_Pin_12);
	if(a == 9) GPIO_SetBits(GPIOB,GPIO_Pin_13);
	if(a == 10) GPIO_SetBits(GPIOB,GPIO_Pin_15);

}
void Reset_Dout(uint8_t a)
{
	if(a == 1) GPIO_ResetBits(GPIOC,GPIO_Pin_2);
	if(a == 2) GPIO_ResetBits(GPIOC,GPIO_Pin_3);
	if(a == 3) GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	if(a == 4) GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	if(a == 5) GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	if(a == 6) GPIO_ResetBits(GPIOB,GPIO_Pin_1);
	if(a == 7) GPIO_ResetBits(GPIOB,GPIO_Pin_2);
	if(a == 8) GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	if(a == 9) GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	if(a == 10) GPIO_ResetBits(GPIOB,GPIO_Pin_15);

}

