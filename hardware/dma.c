#include "dma.h"
#include "hw_config.h"

////////////////////////////////////
//USB ͨѶ����
//DMA��������
//�޸����ڣ�2017/7/6
////////////////////////////////////

/***********************************
* ��������  : DMA_Config
* ��������  : DMA���ڵĳ�ʼ������
* ����      : ���ݴ����� dma_count���洢����ַ add
* ���      : None
* Return   : None
***********************************/
u8     Rx_ORDER_Buffer[128];

void DMA_Config(u16 dma_count,u32 add)
{
	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);                        //����DMAʱ��
	DMA_DeInit(DMA1_Channel5);																							 //��DMA1��Ϊȱʡֵ
	DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_DR_Base;							 //���ô������ݼĴ�����ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = add;															 //�����ڴ��ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;										   //�������ݴ��䷽�򣬵�ǰ��Ϊ�ɴ��ڵ��ڴ�
	DMA_InitStructure.DMA_BufferSize = dma_count;														 //���ô������ݴ�С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;				 //�����ַ������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;									 //�ڴ��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  //�������ݵ�λ
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;					 //�ڴ����ݵ�λ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                          //����ѭ��ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;									 //���ȼ���Ϊ���
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;														 //��ֹ�ڴ浽�ڴ�Ĵ���
	DMA_Init(DMA1_Channel5, &DMA_InitStructure);														 //����DMA1ͨ��5
	DMA_ITConfig(DMA1_Channel5,DMA_IT_TC,ENABLE);														 //����DMA������ɺ�����ж�
}

