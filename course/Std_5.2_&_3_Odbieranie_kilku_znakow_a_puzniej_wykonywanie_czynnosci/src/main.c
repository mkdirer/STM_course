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
#include <string.h>
#include <stdlib.h>

char my_buffer[5] = "";

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

char *strnstr(const char *haystack, const char *needle, size_t len)
{
       int i;
       size_t needle_len;

       /* segfault here if needle is not NULL terminated */
       if (0 == (needle_len = strlen(needle)))
               return (char *)haystack;

       for (i=0; i<=(int)(len-needle_len); i++)
       {
               if ((haystack[0] == needle[0]) &&
                       (0 == strncmp(haystack, needle, needle_len)))
                       return (char *)haystack;

               haystack++;
       }
       return NULL;
}

int main(void)
{
 GPIO_InitTypeDef gpio;
 USART_InitTypeDef uart;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); //UART clock


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

 int my_buffer_size = 6; //size of my buffer
    //char *my_buffer; //dm alloc
    //my_buffer = malloc(sizeof(char) * my_buffer_size);
    //memset(my_buffer, 0, sizeof(char) * my_buffer_size);//fill with zeros
    int buffer_index = 0;


 while (1) {
	 if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE)){
		 char c = USART_ReceiveData(USART2);
		 my_buffer[buffer_index] = c;
		 buffer_index++;

		 if (buffer_index == my_buffer_size || c == '\r') {
		                if (strnstr(my_buffer, "on 1\r", 5)) {
		       			 send_string("Zapalam diode pierwsza!\r\n");
		       			 GPIO_SetBits(GPIOC, GPIO_Pin_0);
		                }
		                else if (strnstr(my_buffer, "off 1\r", 6)) {
		        		 	send_string("Gasze diode pierwsza!\r\n");
		        		 	GPIO_ResetBits(GPIOC, GPIO_Pin_0);
		                } else if (strnstr(my_buffer, "on 2\r", 5)) {
			       			 send_string("Zapalam diode druga!\r\n");
			       			 GPIO_SetBits(GPIOC, GPIO_Pin_1);
			                }
			                else if (strnstr(my_buffer, "off 2\r", 6)) {
			        		 	send_string("Gasze diode druga!\r\n");
			        		 	GPIO_ResetBits(GPIOC, GPIO_Pin_1);
			                }
		                else
		                {
		                    send_string("Not recognized command.\r\n");
		                }
		                memset(my_buffer, 0, my_buffer_size);
		                buffer_index = 0;
		            }

		 /*            switch (c) {
		            case 'b':
		                send_string("Odebrano komunikat B!\r\n");
		                GPIO_SetBits(GPIOA, GPIO_Pin_5); //set bit
		                break;
		            case 'a':
		                send_string("Odebrano komunikat A!\r\n");
		                GPIO_ResetBits(GPIOA, GPIO_Pin_5); //reset bit
		                break;
		            default:
		                send_string("Nieznany komunikat!\r\n");
		                break;
		            }*/
		        }
		    }
		 }
