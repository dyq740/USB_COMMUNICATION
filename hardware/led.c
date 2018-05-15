#include "led.h"
#include "stm32f10x.h"
#include "delay.h"
////////////////////////////////////
//USB 通讯程序
//LED驱动代码
//修改日期：2017/9/21
////////////////////////////////////

//初始化PC1为输出口，并使能其时钟
//LED IO初始化
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 	//使能PC口时钟
	
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP; 	//推挽输出
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1;        			//端口配置 LED1->PC1
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;			//IO口速度为50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure); 								//根据设定参数初始化GPIOC.1         
	GPIO_ResetBits(GPIOC,GPIO_Pin_1); 										//PC1输出低电平

	}
