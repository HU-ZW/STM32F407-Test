#ifndef	_COMMON_H
#define	_COMMON_H

#include "stm32f4xx.h"
#include "delay.h"
#include "misc.h"

#include "led.h"		//LEDµÆ 
#include "key.h"		//°´¼ü
#include "lcd.h"		//LCDÏÔÊ¾ÆÁ
#include "usart.h"		//´®¿Ú
#include "picture.h"	//Í¼Æ¬Êý×é
#include "isr.h"		//ÖÐ¶Ï
#include "init.h"		//³õÊ¼»¯
#include "pwm.h"		//PWM
#include "touch.h" 		//´¥ÃþÆÁ
#include "touch_task.h"	//´¥ÃþÆÁÈÎÎ
#include "24cxx.h" 		//ATC02

#include "Car_Task.h"

#define  FREQUENCY 168	//Ð¾Æ¬Ö÷Æµ

typedef struct
{
	u16 A;
	u16 B;
	u16 C;
}C_ST;


#endif


