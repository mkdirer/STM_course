/*
 * DOUT.cpp
 *
 *  Created on: 03.06.2019
 *      Author: Ja
 */

#include "DOUT.h"
#include "stm32f30x.h"


DOUT::DOUT() {
	// TODO Auto-generated constructor stub

}

DOUT::~DOUT() {
	// TODO Auto-generated destructor stub
}

void DOUT::INIT(void) {
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
