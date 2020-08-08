#include "common.h"  

void All_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����жϷ���
	delay_init(FREQUENCY);//168
	uart_init(115200);//���ڳ�ʼ��
	uart6_init(9600);//�������ڳ�ʼ��  C6 TX  C7 RX  
	
	LED_Init();//LED��ʼ��
	KEY_Init();//������ʼ��
	
	LCD_Init();//LCD��ʼ��
	LCD_Display_Dir(1);//0���� LCD��ʾ����
	
	//tp_dev.init();				//��������ʼ��	
	POINT_COLOR = RED;//������ɫ����
	
	APB_PWM_init(500,FREQUENCY/2, PWM14, TIM14);//��ʼ��PWM14  84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ100������PWMƵ��Ϊ 1M/100=10Khz.
	APB_PWM_init(500,FREQUENCY/2, PWM13, TIM13); 
	APB_PWM_init(500,FREQUENCY/2, PWM10, TIM10);
	APB_PWM_init(500,FREQUENCY/2, PWM11, TIM11);  
}

//ͨ�ö�ʱ��3�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��3!
//eg:	TIM3_init(200, FREQUENCY/2);//200ms�ж�
void TIM3_init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE); //ʹ��TIM3ʱ�� 

	TIM_TimeBaseInitStructure.TIM_Period    = arr*10-1 ;//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc*100-1;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ 
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 

	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//��ʼ��TIM3

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM3,ENABLE); //ʹ�ܶ�ʱ��3

	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02; //��ռ���ȼ�1 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03;//�����ȼ�3 
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void TIM4_init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE); //ʹ��TIM4ʱ�� 

	TIM_TimeBaseInitStructure.TIM_Period    = arr*10-1 ;//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc*100-1;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ 
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 

	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);//��ʼ��TIM4

	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM4,ENABLE); //ʹ�ܶ�ʱ��4

	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; //��ʱ��4�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03;//�����ȼ�3 
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

 




