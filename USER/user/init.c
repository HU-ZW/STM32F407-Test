#include "common.h"  

void All_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断分组
	delay_init(FREQUENCY);//168
	uart_init(115200);//串口初始化
	uart6_init(9600);//蓝牙串口初始化  C6 TX  C7 RX  
	
	LED_Init();//LED初始化
	KEY_Init();//按键初始化
	
	LCD_Init();//LCD初始化
	LCD_Display_Dir(1);//0竖屏 LCD显示设置
	
	//tp_dev.init();				//触摸屏初始化	
	POINT_COLOR = RED;//画笔颜色设置
	
	APB_PWM_init(500,FREQUENCY/2, PWM14, TIM14);//初始化PWM14  84M/84=1Mhz的计数频率,重装载值100，所以PWM频率为 1M/100=10Khz.
	APB_PWM_init(500,FREQUENCY/2, PWM13, TIM13); 
	APB_PWM_init(500,FREQUENCY/2, PWM10, TIM10);
	APB_PWM_init(500,FREQUENCY/2, PWM11, TIM11);  
}

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!
//eg:	TIM3_init(200, FREQUENCY/2);//200ms中断
void TIM3_init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE); //使能TIM3时钟 

	TIM_TimeBaseInitStructure.TIM_Period    = arr*10-1 ;//自动重装栽值
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc*100-1;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式 
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 

	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//初始化TIM3

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM3,ENABLE); //使能定时器3

	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02; //抢占优先级1 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03;//子优先级3 
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void TIM4_init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE); //使能TIM4时钟 

	TIM_TimeBaseInitStructure.TIM_Period    = arr*10-1 ;//自动重装栽值
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc*100-1;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式 
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 

	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);//初始化TIM4

	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM4,ENABLE); //使能定时器4

	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; //定时器4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03;//子优先级3 
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

 




