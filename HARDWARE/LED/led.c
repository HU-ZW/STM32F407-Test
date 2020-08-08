#include "led.h"
#include "stm32f4xx.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//使能GPIOF时钟
	//F9
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//普通输出 
//	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//推挽输出
//	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//上拉
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//50MHz
//	
//	GPIO_Init(GPIOF,&GPIO_InitStructure);//初始化
//	GPIO_SetBits(GPIOF,GPIO_Pin_9);//GPIOF9,F10设置高，灯灭

	//F10
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(GPIOF,&GPIO_InitStructure);	
	GPIO_ResetBits(GPIOF,GPIO_Pin_10);
	

}

/***************************
*eg:	
*		LED0(1);	//点亮LED0
***************************/
void LED0(unsigned char Mode)
{
	Mode==1 ? GPIO_SetBits(GPIOF, GPIO_Pin_9) : GPIO_ResetBits(GPIOF, GPIO_Pin_9);
}

void LED1(unsigned char Mode)
{
	Mode==1 ? GPIO_SetBits(GPIOF, GPIO_Pin_10) : GPIO_ResetBits(GPIOF, GPIO_Pin_10);
}

void LED0_Turn(void)
{
	static unsigned char Dir=0;
	Dir==1 ? GPIO_SetBits(GPIOF, GPIO_Pin_9) : GPIO_ResetBits(GPIOF, GPIO_Pin_9);
	Dir = !Dir;
}

void LED1_Turn(void)
{
	static unsigned char Dir=0;
	Dir==0 ? GPIO_SetBits(GPIOF, GPIO_Pin_10) : GPIO_ResetBits(GPIOF, GPIO_Pin_10);
	Dir = !Dir;
}



