#include "stm32f30x.h"
#include "aio.h"
#include "io.h"

uint16_t ADC_Value[2];
void OUT_ANA_Config(void)
{
	//DAC1-o1 PA4 AO1
		//DAC1-o2 PA5 AO2

		 DAC_InitTypeDef DAC_InitStructure;
		 GPIO_InitTypeDef GPIO_InitStructure;

		 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

		 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 | GPIO_Pin_4;
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
		 GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		 //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		 GPIO_Init(GPIOA, &GPIO_InitStructure);

		 DAC_StructInit(&DAC_InitStructure);
		 //DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude =
		 DAC_InitStructure.DAC_Trigger = DAC_Trigger_None; //DAC_Trigger_None; //DAC_Trigger_T2_TRGO;
		 DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_Triangle; //DAC_WaveGeneration_None; //DAC_WaveGeneration_Triangle;
		 //DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
		 DAC_InitStructure.DAC_Buffer_Switch = DAC_BufferSwitch_Enable;

		 DAC_Init(DAC1,DAC_Channel_1,&DAC_InitStructure);
		 DAC_Init(DAC1,DAC_Channel_2,&DAC_InitStructure);
		 DAC_Cmd(DAC1,DAC_Channel_1,ENABLE);
		 DAC_Cmd(DAC1,DAC_Channel_2,ENABLE);

			//DAC_SetChannel1Data(DAC1,DAC_Align_12b_R,0);//AO1
			//DAC_SetChannel2Data(DAC1,DAC_Align_12b_R,0);//AO2


}
void IN_ANA_Config(void)
{
	//ADC1 PA6
	//ADC2 PA7

	ADC_InitTypeDef       ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	DMA_InitTypeDef       DMA_InitStructure;
	GPIO_InitTypeDef      GPIO_InitStructure;


	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC12, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	 RCC_ADCCLKConfig( RCC_ADC12PLLCLK_Div2 );
	 ADC_StructInit( &ADC_InitStructure );

	    ADC_VoltageRegulatorCmd( ADC2, ENABLE );


	    for(volatile uint32_t i=0;i<100000;i++);

	    ADC_SelectCalibrationMode( ADC2, ADC_CalibrationMode_Single );
	    ADC_StartCalibration( ADC2 );

	    while ( ADC_GetCalibrationStatus( ADC2 ) != RESET );


	    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	    ADC_CommonInitStructure.ADC_Clock = ADC_Clock_AsynClkMode;
	    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_1;
	    ADC_CommonInitStructure.ADC_DMAMode = ADC_DMAMode_Circular;
	    ADC_CommonInit( ADC2, &ADC_CommonInitStructure );

	    ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Enable;
	    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	    ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_0;
	    ADC_InitStructure.ADC_ExternalTrigEventEdge = ADC_ExternalTrigEventEdge_None;
	    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	    ADC_InitStructure.ADC_OverrunMode = ADC_OverrunMode_Disable;
	    ADC_InitStructure.ADC_AutoInjMode = ADC_AutoInjec_Disable;
	    ADC_InitStructure.ADC_NbrOfRegChannel = 2;
	    ADC_Init( ADC2, &ADC_InitStructure );

	    /* ADC1 regular channel7 configuration */
	    ADC_RegularChannelConfig( ADC2, ADC_Channel_3, 1, ADC_SampleTime_601Cycles5 );
	    ADC_RegularChannelConfig( ADC2, ADC_Channel_4, 2, ADC_SampleTime_601Cycles5 );


	    DMA_StructInit(&DMA_InitStructure);
	    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC2->DR;
	    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_Value;
	    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	    DMA_InitStructure.DMA_BufferSize =2;
	    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

	    DMA_Init(DMA2_Channel1,&DMA_InitStructure);

	    DMA_Cmd(DMA2_Channel1, ENABLE);
	    ADC_DMAConfig(ADC2,ADC_DMAMode_Circular);
	    ADC_DMACmd(ADC2,ENABLE);

	    ADC_Cmd( ADC2, ENABLE );
	    while( !ADC_GetFlagStatus( ADC2, ADC_FLAG_RDY ) );
	    ADC_StartConversion( ADC2 );

}
uint16_t* returnADC(){
	return ADC_Value;
}

