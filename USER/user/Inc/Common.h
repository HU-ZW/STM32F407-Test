#ifndef	_COMMON_H
#define	_COMMON_H

#include "stm32f4xx.h"
#include "delay.h"
#include "misc.h"

#include "led.h"		//LED�� 
#include "key.h"		//����
#include "lcd.h"		//LCD��ʾ��
#include "usart.h"		//����
#include "picture.h"	//ͼƬ����
#include "isr.h"		//�ж�
#include "init.h"		//��ʼ��
#include "pwm.h"		//PWM
#include "touch.h" 		//������
#include "touch_task.h"	//���������
#include "24cxx.h" 		//ATC02

#include "Car_Task.h"

#define  FREQUENCY 168	//оƬ��Ƶ

typedef struct
{
	u16 A;
	u16 B;
	u16 C;
}C_ST;


#endif


