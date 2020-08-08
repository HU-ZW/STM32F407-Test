#include "common.h"

//PWM��ʼ�� 
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//eg: TIM_SetCompare1(TIM14,X); �ı�X���ı�ռ�ձ� ��Ϊ1ͨ��     TIM_SetCompare2Ϊ2ͨ��
//TIM14_PWM_init(MAX,FREQUENCY/2);MAXΪռ�ձȵ����ֵ
//
//eg: APB_PWM_init(500,FREQUENCY/2, PWM14, TIM14);

void APB_PWM_init(u16 arr,u16 psc, enPWM_APB ePWM_APB, TIM_TypeDef* TIMx)
{
	//�˲������ֶ��޸�IO������
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	switch(ePWM_APB)
	{
		case PWM4_1://B6
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//ʹ��GPIOBʱ��
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM4); //GPIOB9����Ϊ��ʱ��4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM4_2://B7
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//ʹ��GPIOBʱ��
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_TIM4); //GPIOB9����Ϊ��ʱ��4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM4_3://B8
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//ʹ��GPIOBʱ��
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM4); //GPIOB9����Ϊ��ʱ��4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM4_4://B9
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//ʹ��GPIOBʱ��
			GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_TIM4); //GPIOB9����Ϊ��ʱ��4
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOB,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM10://F6
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//ʹ��GPIOFʱ��
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource6,GPIO_AF_TIM10); //GPIOF6����Ϊ��ʱ��10
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM11://F7
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//ʹ��GPIOFʱ��
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource7,GPIO_AF_TIM11); //GPIOF7����Ϊ��ʱ��11
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM13://F8
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//ʹ��GPIOFʱ��
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource8,GPIO_AF_TIM13); //GPIOF8����Ϊ��ʱ��13
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//��ʼ��
			break;
		case PWM14://F9
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//ʹ��GPIOFʱ��
			GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14); //GPIOF9����Ϊ��ʱ��14
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//������� 
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
			GPIO_Init(GPIOF,&GPIO_InitStructure);//��ʼ��
			break;
		default:
			break;
	}
	
	//TIMʱ��ʹ�� 
	if( ePWM_APB==PWM12  || ePWM_APB==PWM13  || ePWM_APB==PWM14 )
		RCC_APB1PeriphClockCmd(ePWM_APB, ENABLE);  	
	else if(ePWM_APB==PWM4_1 || ePWM_APB==PWM4_2 || ePWM_APB==PWM4_3 || ePWM_APB==PWM4_4 )
		RCC_APB1PeriphClockCmd(PWM4_1, ENABLE);  	
	else if( ePWM_APB==PWM10 || ePWM_APB==PWM11 ) 
		RCC_APB2PeriphClockCmd(ePWM_APB, ENABLE);  
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc-1;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr-1;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseStructure);//��ʼ����ʱ��
	
	//��ʼ��TIM Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
	if( ePWM_APB==PWM4_1 || ePWM_APB==PWM4_2 || ePWM_APB==PWM4_3 || ePWM_APB==PWM4_4 )
	{
		TIM_OCInitStructure.TIM_Pulse = 0;
		if( ePWM_APB==PWM4_1 )//1ͨ��
		{
			TIM_OC1Init(TIMx, &TIM_OCInitStructure);
			TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		else if( ePWM_APB==PWM4_2 )//2ͨ��
		{
			TIM_OC2Init(TIMx, &TIM_OCInitStructure);
			TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		else if( ePWM_APB==PWM4_3 )//3ͨ��
		{
			TIM_OC3Init(TIMx, &TIM_OCInitStructure);
			TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		else if( ePWM_APB==PWM4_4 )//4ͨ��
		{
			TIM_OC4Init(TIMx, &TIM_OCInitStructure);
			TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
		}
		
	}
	else
	{
		TIM_OC1Init(TIMx, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIMx OC1 TIMx_CH1
		TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);  //ʹ��TIM��CCR1�ϵ�Ԥװ�ؼĴ���
	}
	
	TIM_ARRPreloadConfig(TIMx,ENABLE);//ARPEʹ�� 
	
	TIM_Cmd(TIMx, ENABLE);  //ʹ��TIM
}

//��Ҫ��GPIOF9����Ϊ��ʱ��14
//���ģʽ��Ϊ�������
//��ʼ��TIM14_PWM_init(500,FREQUENCY/2);
void PWM14_LED(void)
{
	static u8 Dir=1;
	static u16 Count=0;
	if( Dir==1 )	Count++;
	else			Count--;
	if( Count>99 )	Dir = 0;
	if( Count<1 )	Dir = 1;
	TIM_SetCompare1(TIM14,Count);	//�޸ıȽ�ֵ���޸�ռ�ձ�
	delay_ms(10);
	LCD_ShowNum(100, 120,Count,5,16);
}

//��Ҫ��GPIOF9����Ϊ��ʱ��13
//���ģʽ��Ϊ�������
//��ʼ��TIM14_PWM_init(500,FREQUENCY/2);
void PWM13_LED(void)
{
	static u8 Dir=1;
	static u16 Count=0;
	if( Dir==1 )	Count++;
	else			Count--;
	if( Count>499 )	Dir = 0;
	if( Count<1 )	Dir = 1;
	TIM_SetCompare1(TIM13,Count);	//�޸ıȽ�ֵ���޸�ռ�ձ�
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
		TIM_SetCompare2(TIMx,Count);	//�޸ıȽ�ֵ���޸�ռ�ձ�
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




