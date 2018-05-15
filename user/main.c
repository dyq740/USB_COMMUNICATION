#include "led.h"
#include "dma.h"
#include "delay.h"
#include "usart.h"
#include "hw_config.h"
#include "stm32f10x.h"
extern  void 	Ch_TX_Send(u8 *p_buf,u16 Count);
extern   u8     Rx_ORDER_Buffer[128];
////////////////////////////////////
//USB 通讯程序
//主函数
//修改日期：2017/7/6
////////////////////////////////////
int main(void)
{
	delay_init();
	LED_Init();
	DMA_Config(14,(u32)&Rx_ORDER_Buffer[0]);
	uart_init(9600);
	DMA_Cmd(DMA1_Channel5, ENABLE);
	USART_Cmd(USART1, ENABLE);
	while(1)
	{
		if(SET==DMA_GetFlagStatus(DMA1_FLAG_HT5))
			{		
					DMA_ClearFlag(DMA1_FLAG_HT5);
					Ch_TX_Send(&Rx_ORDER_Buffer[0],7);
					GPIO_WriteBit(GPIOC,GPIO_Pin_1,Bit_RESET);
			}
		else if(SET==DMA_GetFlagStatus(DMA1_FLAG_TC5))	
			 {		
					DMA_ClearFlag(DMA1_FLAG_TC5);
					Ch_TX_Send(&Rx_ORDER_Buffer[64],64);
					GPIO_WriteBit(GPIOC,GPIO_Pin_1,Bit_SET);			 
			 }
	}
//	while(1){
//		
//	GPIO_ResetBits(GPIOC,GPIO_Pin_1);
//	delay_ms(50);
//	GPIO_SetBits(GPIOC,GPIO_Pin_1);
//	delay_ms(50);
//}
}

