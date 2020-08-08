#ifndef _CAR_TASK_H_
#define _CAR_TASK_H_

#include "stm32f4xx.h" 

extern char Car_CMD;
extern u8 Car_Buffer[10];
extern u8 Mode;

void Car_Task(void);//车任务

void Car_Left(void);//左转
void Car_Right(void);//右转
void Car_Forward(void);//前进
void Car_Back_Off(void);//后退
void Car_Stop(void);//停车



#endif


