#ifndef  _ISR_H
#define  _ISR_H
#include "stm32f4xx.h"
#define BUFFER_MAX 20

extern u16 Rec_Data[BUFFER_MAX];


void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void USART1_IRQHandler(void);
void USART6_IRQHandler(void);
void SendData(USART_TypeDef* USARTx, unsigned int *buffer);

//extern char String;


#endif

