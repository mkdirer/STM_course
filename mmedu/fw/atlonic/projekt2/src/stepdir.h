/*
 * stepdir.h
 *
 *  Created on: 27 cze 2016
 *      Author: £ukasz Krzyœciak
 */

#ifndef STEPDIR_H_
#define STEPDIR_H_

#define STEP1_PORT GPIOB
#define STEP1_PIN GPIO_Pin_5
#define STEP2_PORT GPIOB
#define STEP2_PIN GPIO_Pin_4
#define STEP3_PORT GPIOC
#define STEP3_PIN GPIO_Pin_8

#define DIR1_PORT GPIOA
#define DIR1_PIN GPIO_Pin_8
#define DIR2_PORT GPIOA
#define DIR2_PIN GPIO_Pin_15
#define DIR3_PORT GPIOC
#define DIR3_PIN GPIO_Pin_9

#define STEP1_Value TIM1->CNT
#define STEP2_Value TIM15->CNT
#define STEP3_Value TIM20->CNT


void STEPDIR_Config(void);
void STEPDIR_Control();


#endif /* STEPDIR_H_ */
