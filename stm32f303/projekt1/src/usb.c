#include "usb.h"
#include "stm32f30x.h"
#define bufferSize 512
uint32_t BuforRX[bufferSize];
void usbInit()
{

		 GPIO_InitTypeDef       GPIO_InitStructure;
		 USART_InitTypeDef     USART_InitStructure;
		 DMA_InitTypeDef    DMA_InitStructure;

		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  //usb
		 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

		 GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_7); //tx
		 GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_7);//rx

		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		 GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
		 GPIO_Init(GPIOA, &GPIO_InitStructure);

		 USART_InitStructure.USART_BaudRate = 115200; // 460800 ;//230400;//921600;//115200; //9600
		 USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		 USART_InitStructure.USART_StopBits = USART_StopBits_1;
		 USART_InitStructure.USART_Parity = USART_Parity_No;
		 USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		 USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		 USART_Init(USART2, &USART_InitStructure);


		 	 DMA_StructInit(&DMA_InitStructure);//rx

		     DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART2->RDR;//UART8_BASE + 4;//Adres docelowy transferu
		     DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)BuforRX;

		     DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
		     DMA_InitStructure.DMA_BufferSize =bufferSize; //Liczba elementow do przeslania (dlugosc bufora)
		     DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//Wylaczenie automatycznego zwiekszania adresu po stronie ADC
		     DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//Wlaczenie automatycznego zwiekszania adresu po stronie pamieci (bufora)
		     DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//Rozmiar pojedynczych przesylanych danych po stronie licznika (Byte = 8bit)
		     DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;//Rozmiar pojedynczych przesylanych danych po stronie pamieci (bufora)
		     DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//Tryb dzialana kontrolera DMA - powtarzanie cykliczne
		     DMA_InitStructure.DMA_Priority = DMA_Priority_High;//Priorytet DMA

		     DMA_Init(DMA1_Channel6,&DMA_InitStructure);

		     DMA_Cmd(DMA1_Channel6, ENABLE);//rx

		     USART_DMACmd(USART2, USART_DMAReq_Rx, ENABLE);
		     USART_Cmd(USART2, ENABLE);
}
uint32_t* returnbuffer()
{
	return BuforRX;
}





