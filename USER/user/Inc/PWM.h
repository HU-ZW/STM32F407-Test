#ifndef _PWM_H
#define _PWM_H

#include "stm32f4xx.h"

typedef enum
{
	//APB1
	PWM2   =  0x00000001,
	PWM3   =  0x00000002,
	
	PWM4_1 =  0x00000004,
	PWM4_2 =  0x00000005,
	PWM4_3 =  0x00000006,
	PWM4_4 =  0x00000007,
	
	PWM5   =  0x00000008,
	PWM6   =  0x00000010,
	PWM7   =  0x00000020,
	
	PWM12  =  0x00000040,
	PWM13  =  0x00000080,
	PWM14  =  0x00000100,
	
	
	//APB2
	PWM10  =  0x00020000,
	PWM11  =  0x00040000,
	
}enPWM_APB;


void APB_PWM_init(u16 arr,u16 psc, enPWM_APB ePWM_APB, TIM_TypeDef* TIMx);
void TIM13_PWM_init(u16 arr,u16 psc);
void TIM14_PWM_init(u16 arr,u16 psc);
void PWM_Test( enPWM_APB ePWM ,TIM_TypeDef* TIMx, u16 MAX);
void PWM13_LED(void);
void PWM14_LED(void);

#endif

