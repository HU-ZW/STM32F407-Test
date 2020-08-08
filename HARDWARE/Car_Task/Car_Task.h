#ifndef _CAR_TASK_H_
#define _CAR_TASK_H_

#include "stm32f4xx.h" 

extern char Car_CMD;
extern u8 Car_Buffer[10];
extern u8 Mode;

void Car_Task(void);//������

void Car_Left(void);//��ת
void Car_Right(void);//��ת
void Car_Forward(void);//ǰ��
void Car_Back_Off(void);//����
void Car_Stop(void);//ͣ��



#endif


