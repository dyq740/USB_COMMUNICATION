#include "stm32f10x_usart.h"
/****************************************
函数名称：Ch_TX_Send
功能描述：串口发送数据
输入参数：串口发送数据缓存，发送数据长度
输出参数：无

*****************************************/ 
void Ch_TX_Send(u8 *p_buf,u16 Count)
{
	 while(Count--)
	 {
		USART_SendData(USART1,*p_buf++);
		while(RESET == USART_GetFlagStatus(USART1, USART_FLAG_TXE));
	 }
}
