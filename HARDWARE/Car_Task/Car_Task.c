#include "common.h" 

char Car_CMD;
u8 Car_Buffer[10]={0};
u8 Mode = 0;//0手机控制 1电脑控制

void Car_Task(void)
{
	u8 CMD = (Mode==0?Car_Buffer[2]:Car_CMD);
	switch( CMD )
	{
		case 0x01:
			Car_Forward();
			break;
		case 0x04:
			Car_Left();
			break;
		case 0x08:
			Car_Right();
			break;
		case 0x02:
			Car_Back_Off();
			break;
		default:
			Car_Stop();
			break;
	}
	
	//*--------------------------------------------------
	
	//*-------------------------------------------------
}

void Car_Left(void)//左转
{
	TIM_SetCompare1(TIM14,499);
	TIM_SetCompare1(TIM13,0);
	
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM11,499);
}

void Car_Right(void)//右转
{
	TIM_SetCompare1(TIM14,0);
	TIM_SetCompare1(TIM13,499);
	
	TIM_SetCompare1(TIM10,499);
	TIM_SetCompare1(TIM11,0);
}

void Car_Forward(void)//前进 
{
	TIM_SetCompare1(TIM14,0);
	TIM_SetCompare1(TIM13,499);
	
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM11,499);
}

void Car_Back_Off(void)//后退
{
	TIM_SetCompare1(TIM14,499);
	TIM_SetCompare1(TIM13,0);
	
	TIM_SetCompare1(TIM10,499);
	TIM_SetCompare1(TIM11,0);
}

void Car_Stop(void)//停车
{
	TIM_SetCompare1(TIM14,0);
	TIM_SetCompare1(TIM13,0);
	
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM11,0);
}
