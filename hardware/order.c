#include "stm32f10x_usart.h"
/****************************************
�������ƣ�Ch_TX_Send
�������������ڷ�������
������������ڷ������ݻ��棬�������ݳ���
�����������

*****************************************/ 
void Ch_TX_Send(u8 *p_buf,u16 Count)
{
	 while(Count--)
	 {
		USART_SendData(USART1,*p_buf++);
		while(RESET == USART_GetFlagStatus(USART1, USART_FLAG_TXE));
	 }
}
