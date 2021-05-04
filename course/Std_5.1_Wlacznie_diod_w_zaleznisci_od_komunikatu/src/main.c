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

void send_char(char c)
{
 while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
 USART_SendData(USART2, c);
}

void send_string(const char* s)
{
 while (*s)
 send_char(*s++);
}

int main(void)
{
 GPIO_InitTypeDef gpio;
 USART_InitTypeDef uart;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

 GPIO_StructInit(&gpio);
 gpio.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
 					GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
 gpio.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOC, &gpio);

 gpio.GPIO_Pin = GPIO_Pin_2;
 gpio.GPIO_Mode = GPIO_Mode_AF_PP;
 GPIO_Init(GPIOA, &gpio);

 gpio.GPIO_Pin = GPIO_Pin_3;
 gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 GPIO_Init(GPIOA, &gpio);

 USART_StructInit(&uart);
 uart.USART_BaudRate = 115200;
 USART_Init(USART2, &uart);

 USART_Cmd(USART2, ENABLE);

 while (1) {
	 if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE)){
		 char c = USART_ReceiveData(USART2);
		 switch (c){
		 case'a':
			 send_string("Zapalam diode pierwsza!\r\n");
			 GPIO_SetBits(GPIOC, GPIO_Pin_0);
			 break;
		 case'A':
		 	send_string("Gasze diode pierwsza!\r\n");
		 	GPIO_ResetBits(GPIOC, GPIO_Pin_0);
		 	break;
		 case'b':
			send_string("Zapalam diode druga!\r\n");
			GPIO_SetBits(GPIOC, GPIO_Pin_1);
		    break;
		 case'B':
		   send_string("Gasze diode druga!\r\n");
		   GPIO_ResetBits(GPIOC, GPIO_Pin_1);
		   break;
		 case'c':
			send_string("Zapalam diode trzecia!\r\n");
			GPIO_SetBits(GPIOC, GPIO_Pin_2);
		    break;
		 case'C':
		   send_string("Gasze diode trzecia!\r\n");
		   GPIO_ResetBits(GPIOC, GPIO_Pin_2);
		   break;
		 case'd':
			send_string("Zapalam diode czwarta!\r\n");
			GPIO_SetBits(GPIOC, GPIO_Pin_3);
		    break;
		 case'D':
		   send_string("Gasze diode czwarta!\r\n");
		   GPIO_ResetBits(GPIOC, GPIO_Pin_3);
		   break;
		 case'e':
			send_string("Zapalam diode piata!\r\n");
			GPIO_SetBits(GPIOC, GPIO_Pin_4);
		    break;
		 case'E':
		   send_string("Gasze diode piata!\r\n");
		   GPIO_ResetBits(GPIOC, GPIO_Pin_4);
		   break;
		 default:
		 	send_string("Zly komunikacik: \r\n");
		 	break;

		 }
	 }
 }
}
