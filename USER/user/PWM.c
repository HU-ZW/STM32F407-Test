#include "common.h"

//PWM初始化 
//arr：自动重装值
//psc：时钟预分频数
//eg: TIM_SetCompare1(TIM14,X); 改变X即改变占空比 此为1通道     TIM_SetCompare2为2通道
//TIM14_PWM_init(MAX,FREQUENCY/2);MAX为占空比的最大值
//
//eg: APB_PWM_init(500,FREQUENCY/2, PWM14, TIM14);

void APB_PWM_init(u16 arr,u16 psc, enPWM_APB ePWM_APB, TIM_TypeDef* TIMx)
{
	//此部分需手动修改IO口设置
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	switch(ePWM_APB)
	{
		case PWM4_1://B6
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//使能GPIOB时钟
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM4); //GPIOB9复用为定时器4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
			break;
		case PWM4_2://B7
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//使能GPIOB时钟
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_TIM4); //GPIOB9复用为定时器4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
			break;
		case PWM4_3://B8
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//使能GPIOB时钟
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM4); //GPIOB9复用为定时器4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
			break;
		case PWM4_4://B9
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//使能GPIOB时钟
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_TIM4); //GPIOB9复用为定时器4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
			break;
		case PWM10://F6
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//使能GPIOF时钟
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource6,GPIO_AF_TIM10); //GPIOF6复用为定时器10
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//初始化
			break;
		case PWM11://F7
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//使能GPIOF时钟
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource7,GPIO_AF_TIM11); //GPIOF7复用为定时器11
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//初始化
			break;
		case PWM13://F8
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//使能GPIOF时钟
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource8,GPIO_AF_TIM13); //GPIOF8复用为定时器13
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//初始化
			break;
		case PWM14://F9
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//使能GPIOF时钟
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14); //GPIOF9复用为定时器14
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用输出 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//初始化
			break;
		default:
			break;
	}
	
	//TIM时钟使能 
	if( ePWM_APB==PWM12  || ePWM_APB==PWM13  || ePWM_APB==PWM14 )
		RCC_APB1PeriphClockCmd(ePWM_APB, ENABLE);  	
	else if(ePWM_APB==PWM4_1 || ePWM_APB==PWM4_2 || ePWM_APB==PWM4_3 || ePWM_APB==PWM4_4 )
		RCC_APB1PeriphClockCmd(PWM4_1, ENABLE);  	
	else if( ePWM_APB==PWM10 || ePWM_APB==PWM11 ) 
		RCC_APB2PeriphClockCmd(ePWM_APB, ENABLE);  
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc-1;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr-1;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseStructure);//初始化定时器
	
	//初始化TIM Channel1 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	if( ePWM_APB==PWM4_1 || ePWM_APB==PWM4_2 || ePWM_APB==PWM4_3 || ePWM_APB==PWM4_4 )
	{
		TIM_OCInitStructure.TIM_Pulse = 0;
		if( ePWM_APB==PWM4_1 )//1通道
		{
			TIM_OC1Init(TIMx, &TIM_OCInitStructure);
			TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		else if( ePWM_APB==PWM4_2 )//2通道
		{
			TIM_OC2Init(TIMx, &TIM_OCInitStructure);
			TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		else if( ePWM_APB==PWM4_3 )//3通道
		{
			TIM_OC3Init(TIMx, &TIM_OCInitStructure);
			TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		else if( ePWM_APB==PWM4_4 )//4通道
		{
			TIM_OC4Init(TIMx, &TIM_OCInitStructure);
			TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		
	}
	else
	{
		TIM_OC1Init(TIMx, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIMx OC1 TIMx_CH1
		TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);  //使能TIM在CCR1上的预装载寄存器
	}
	
	TIM_ARRPreloadConfig(TIMx,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIMx, ENABLE);  //使能TIM
}

//需要将GPIOF9复用为定时器14
//输出模式改为复用输出
//初始化TIM14_PWM_init(500,FREQUENCY/2);
void PWM14_LED(void)
{
	static u8 Dir=1;
	static u16 Count=0;
	if( Dir==1 )	Count++;
	else			Count--;
	if( Count>99 )	Dir = 0;
	if( Count<1 )	Dir = 1;
	TIM_SetCompare1(TIM14,Count);	//修改比较值，修改占空比
	delay_ms(10);
	LCD_ShowNum(100, 120,Count,5,16);
}

//需要将GPIOF9复用为定时器13
//输出模式改为复用输出
//初始化TIM14_PWM_init(500,FREQUENCY/2);
void PWM13_LED(void)
{
	static u8 Dir=1;
	static u16 Count=0;
	if( Dir==1 )	Count++;
	else			Count--;
	if( Count>499 )	Dir = 0;
	if( Count<1 )	Dir = 1;
	TIM_SetCompare1(TIM13,Count);	//修改比较值，修改占空比
	delay_ms(10);
	LCD_ShowNum(100, 100,Count,5,16);
}

//PWM_Test(PWM4_4, TIM4, 500); 
void PWM_Test( enPWM_APB ePWM ,TIM_TypeDef* TIMx, u16 MAX)
{
	static u8 Dir=1;
	static u16 Count=0;
	if( Dir==1 )		Count++;
	else				Count--;
	if( Count>MAX-1 )	Dir = 0;
	if( Count<1 )		Dir = 1;
	
	if( ePWM==PWM4_2 )
		TIM_SetCompare2(TIMx,Count);	//修改比较值，修改占空比
	else if( ePWM==PWM4_3 )
		TIM_SetCompare3(TIMx,Count);
	else if( ePWM==PWM4_4 )
		TIM_SetCompare4(TIMx,Count);
	else
		TIM_SetCompare1(TIMx,Count);
	
	delay_ms(30);
	if( ePWM==PWM4_1 || ePWM==PWM4_2 || ePWM==PWM4_3 || ePWM==PWM4_4 )
		LCD_ShowNum(100, 100+(ePWM-4)*16,Count,5,16);
	else
		LCD_ShowNum(100, 100,Count,5,16);
}




