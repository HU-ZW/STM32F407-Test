#include "common.h" 

char Car_CMD;
u8 Car_Buffer[10]={0};
u8 Mode = 0;//0�ֻ����� 1���Կ���

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

void Car_Left(void)//��ת
{
	TIM_SetCompare1(TIM14,499);
	TIM_SetCompare1(TIM13,0);
	
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM11,499);
}

void Car_Right(void)//��ת
{
	TIM_SetCompare1(TIM14,0);
	TIM_SetCompare1(TIM13,499);
	
	TIM_SetCompare1(TIM10,499);
	TIM_SetCompare1(TIM11,0);
}

void Car_Forward(void)//ǰ�� 
{
	TIM_SetCompare1(TIM14,0);
	TIM_SetCompare1(TIM13,499);
	
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM11,499);
}

void Car_Back_Off(void)//����
{
	TIM_SetCompare1(TIM14,499);
	TIM_SetCompare1(TIM13,0);
	
	TIM_SetCompare1(TIM10,499);
	TIM_SetCompare1(TIM11,0);
}

void Car_Stop(void)//ͣ��
{
	TIM_SetCompare1(TIM14,0);
	TIM_SetCompare1(TIM13,0);
	
	TIM_SetCompare1(TIM10,0);
	TIM_SetCompare1(TIM11,0);
}
