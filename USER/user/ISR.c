#include "common.h"

extern unsigned char DealData(unsigned char data, unsigned int *Buffer);

//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET) //����ж�
	{
		
	}
	
	
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);   //����жϱ�־λ
}

//��ʱ��4�жϷ�����
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) == SET) //����ж�
	{
		
	}
	
	
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);   //����жϱ�־λ
}

u16 Rec_Count=0;
u16 BUFF[BUFFER_MAX]={0};
unsigned int BUFFER[5] = {0};
//char String='0';
u8 RUNorSTOP = 1;
void USART6_IRQHandler(void)
{
	u16 Rec=0;
	unsigned char isReady = 0;
	if( USART_GetITStatus(USART6, USART_IT_RXNE) != RESET )
	{
		Rec = USART_ReceiveData(USART6);
		
		isReady = DealData( Rec, BUFFER );
		if( isReady )
		{
			SendData(USART6, BUFFER);
		}
		
		//Car  *----------------------------------------------
		/*Car_CMD = Rec;
		Car_Buffer[0] = Rec;
		
		if( Car_Buffer[0] == 0xA5 && Car_Buffer[1]==0 )
		{
			Car_Buffer[1]++;
		}
		else if( Car_Buffer[1] == 1 )
		{
			Car_Buffer[2] = Rec;
			Car_Buffer[1]++;
		}
		else
		{
			Car_Buffer[1] = 0;
		}
		//end   *----------------------------------------------
		if (Rec == 0xAA) //��0xAA ���� һЩ�ض����ֲ���ʹ��43520 170  ���ɱ�����մ�������
		{
			Rec_Count = 0;
			Rec_Count++;
		}
		else if (Rec == 0x55 && Rec_Count == 1) Rec_Count++;
		else if (Rec == 0xDF && RUNorSTOP) RUNorSTOP = 0;
		else if (Rec_Count >= 2 && RUNorSTOP) 
		{
			BUFF[Rec_Count-1] = Rec;
			Rec_Count++;
			if( Rec_Count>BUFFER_MAX ) Rec_Count = 0;//���ݳ�����  ���½���
		}
		if (!RUNorSTOP)
		{
			Data_Deal(USART6);//���ͽ��յ�����������λ����ʾ
			for (int i = 10; i >= 0; i--)
			{
				BUFF[i] = 0x00;
			}
			Rec_Count = 0;
			RUNorSTOP = 1;
		}*/
	}
	USART_ClearITPendingBit(USART6, USART_IT_RXNE);//����жϱ�־λ 
}


unsigned char DealData(unsigned char data, unsigned int *Buffer)
{
	#define MAX_BUFF 9	

	static const unsigned char READY_TO_GO 		= 1;	
	static const unsigned char RECEIVE 			= 2;	
	static const unsigned char READY_TO_STOP 	= 3;	
	static const unsigned char END 				= 4;	

	static unsigned char statue = 4;				
    static unsigned char buff[MAX_BUFF] = {0};		
    static unsigned char count = 0;

	int i = 0;

	if( data == 0xDF && statue == RECEIVE )
	{
		statue = READY_TO_STOP;
	}
	else if( data == 0xFD && statue == READY_TO_STOP )
	{
		statue = END;
		count = 0;
		for( i=0; i<MAX_BUFF; i++ )
		{
			if( i<1 )
			{
				Buffer[count++] = buff[i];
			}
			else
			{
				Buffer[count++] = (buff[i]<<8) + buff[i+1];
				i++;
			}
		}

		for( i=0; i<MAX_BUFF; i++ )
		{
			buff[i] = 0;
		}
		count = 0;

		return 1;
	}
	else
	{
		if( statue == READY_TO_STOP )
		{
            buff[count++] = 0xDF;
            statue = RECEIVE;
		}
	}

	if( data == 0xAA && statue == END )
	{
		statue = READY_TO_GO;
	}
	else if( data == 0x55 && statue == READY_TO_GO )
	{
		statue = RECEIVE;
	}
	else if( statue == RECEIVE )
	{
		buff[count++] = data;
	}
	return 0;
}



void USART1_IRQHandler(void)
{
	u16 Rec=0;
	
	if( USART_GetITStatus(USART1, USART_IT_RXNE) != RESET )
	{
		Rec = USART_ReceiveData(USART1);
		//if (Rec == 0xAA && Rec_Count == 0) Rec_Count++;//���ɽ���,����������Ҳ�����
		if (Rec == 0xAA) //��0xAA ���� һЩ�ض����ֲ���ʹ��43520 170  ���ɱ�����մ�������
		{
			Rec_Count = 0;
			Rec_Count++;
		}
		else if (Rec == 0x55 && Rec_Count == 1) Rec_Count++;
		else if (Rec == 0xDF && RUNorSTOP) RUNorSTOP = 0;
		else if (Rec_Count >= 2 && RUNorSTOP) 
		{
			BUFF[Rec_Count-1] = Rec;
			Rec_Count++;
			if( Rec_Count>BUFFER_MAX ) Rec_Count = 0;//���ݳ�����  ���½���
		}
		if (!RUNorSTOP)
		{
			//Data_Deal(USART1);//���ͽ��յ�����������λ����ʾ
			for (int i = 10; i >= 0; i--)
			{
				BUFF[i] = 0x00;
			}
			Rec_Count = 0;
			RUNorSTOP = 1;
		}
	}
	//USART_SendData(USART1,Rec);
	//while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
	USART_ClearITPendingBit(USART1, USART_IT_RXNE);//����жϱ�־λ
}

//[0]:��������
//[1]:����1
//[2]:����2
//[3]:����3
//[4]:����4
u16 Rec_Data[BUFFER_MAX];
//USART1~6
void SendData(USART_TypeDef* USARTx, unsigned int *buffer)
{				 
	u16 Data[4]={0xAA,0x55,0xDF, 0xFD};//֡ͷ:2�ֽ� ֡β:2�ֽ�
	
//	for(int i=0; i<10; i+=2)
//	{
//		if( i==0 )	Rec_Data[i]   = BUFF[i+1];
//		else		Rec_Data[i/2] = BUFF[i+1]+(BUFF[i]<<8);
//			
//	}
	//��λ����ʾ
	//֡ͷ
	USART_SendData(USARTx,Data[0]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	USART_SendData(USARTx,Data[1]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	//����
	for(int i=0; i<5; i++)
	{
		if( i==0 )
		{
			USART_SendData(USARTx,buffer[i]);
			while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
		}
		else
		{
			USART_SendData(USARTx,buffer[i]>>8);
			while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
			USART_SendData(USARTx,buffer[i]&0xFF);
			while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
		}
	}
	//֡β
	USART_SendData(USARTx,Data[2]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	USART_SendData(USARTx,Data[3]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	
	//LCD��ʾ
	for(int i=1;i<6;i++)
	{
		LCD_ShowNum(0, (i-1)*20,buffer[i-1],5,16);
	}
	
	/*for(int i=0;i<3;i++)
	{
		LCD_ShowNum(50, i*20,Rec_Data[i],5,16);
	}*/
}

