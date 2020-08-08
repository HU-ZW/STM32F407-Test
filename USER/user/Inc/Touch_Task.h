#ifndef _TOUCH_TASK_H
#define _TOUCH_TASK_H

#include "stm32f4xx.h"

typedef struct
{
	u8 Up;
	u8 Down;
	u8 Left;
	u8 Right;
	
	u8 Decrease;
	u8 Increase;
}stKEY;	

extern stKEY sKEY;



void Touch_Mission(void);

#endif



