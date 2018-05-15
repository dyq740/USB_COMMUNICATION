#include "dma.h"
#include "hw_config.h"

////////////////////////////////////
//USB 通讯程序
//DMA驱动代码
//修改日期：2017/7/6
////////////////////////////////////

/***********************************
* 函数名称  : DMA_Config
* 函数功能  : DMA串口的初始化配置
* 输入      : 数据传输量 dma_count，存储器地址 add
* 输出      : None
* Return   : None
***********************************/
u8     Rx_ORDER_Buffer[128];

void DMA_Config(u16 dma_count,u32 add)
{
	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);                        //开启DMA时钟
	DMA_DeInit(DMA1_Channel5);																							 //将DMA1设为缺省值
	DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_DR_Base;							 //设置串口数据寄存器地址
	DMA_InitStructure.DMA_MemoryBaseAddr = add;															 //设置内存地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;										   //设置数据传输方向，当前设为由串口到内存
	DMA_InitStructure.DMA_BufferSize = dma_count;														 //设置传输数据大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;				 //外设地址不增加
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;									 //内存地址递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  //外设数据单位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;					 //内存数据单位
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                          //工作循环模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;									 //优先级设为最高
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;														 //禁止内存到内存的传输
	DMA_Init(DMA1_Channel5, &DMA_InitStructure);														 //配置DMA1通道5
	DMA_ITConfig(DMA1_Channel5,DMA_IT_TC,ENABLE);														 //配置DMA发送完成后产生中断
}

