#include "common.h"

extern unsigned char DealData(unsigned char data, unsigned int *Buffer);

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET) //溢出中断
	{
		
	}
	
	
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);   //清除中断标志位
}

//定时器4中断服务函数
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) == SET) //溢出中断
	{
		
	}
	
	
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);   //清除中断标志位
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
		if (Rec == 0xAA) //遇0xAA 清零 一些特定数字不能使用43520 170  但可避免接收错误数据
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
			if( Rec_Count>BUFFER_MAX ) Rec_Count = 0;//数据超上限  重新接收
		}
		if (!RUNorSTOP)
		{
			Data_Deal(USART6);//发送接收到的数据在上位机显示
			for (int i = 10; i >= 0; i--)
			{
				BUFF[i] = 0x00;
			}
			Rec_Count = 0;
			RUNorSTOP = 1;
		}*/
	}
	USART_ClearITPendingBit(USART6, USART_IT_RXNE);//清除中断标志位 
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
		//if (Rec == 0xAA && Rec_Count == 0) Rec_Count++;//均可接收,但错误数据也会接收
		if (Rec == 0xAA) //遇0xAA 清零 一些特定数字不能使用43520 170  但可避免接收错误数据
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
			if( Rec_Count>BUFFER_MAX ) Rec_Count = 0;//数据超上限  重新接收
		}
		if (!RUNorSTOP)
		{
			//Data_Deal(USART1);//发送接收到的数据在上位机显示
			for (int i = 10; i >= 0; i--)
			{
				BUFF[i] = 0x00;
			}
			Rec_Count = 0;
			RUNorSTOP = 1;
		}
	}
	//USART_SendData(USART1,Rec);
	//while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
	USART_ClearITPendingBit(USART1, USART_IT_RXNE);//清除中断标志位
}

//[0]:控制数据
//[1]:数据1
//[2]:数据2
//[3]:数据3
//[4]:数据4
u16 Rec_Data[BUFFER_MAX];
//USART1~6
void SendData(USART_TypeDef* USARTx, unsigned int *buffer)
{				 
	u16 Data[4]={0xAA,0x55,0xDF, 0xFD};//帧头:2字节 帧尾:2字节
	
//	for(int i=0; i<10; i+=2)
//	{
//		if( i==0 )	Rec_Data[i]   = BUFF[i+1];
//		else		Rec_Data[i/2] = BUFF[i+1]+(BUFF[i]<<8);
//			
//	}
	//上位机显示
	//帧头
	USART_SendData(USARTx,Data[0]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	USART_SendData(USARTx,Data[1]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	//数据
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
	//帧尾
	USART_SendData(USARTx,Data[2]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	USART_SendData(USARTx,Data[3]);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)!=SET);
	
	//LCD显示
	for(int i=1;i<6;i++)
	{
		LCD_ShowNum(0, (i-1)*20,buffer[i-1],5,16);
	}
	
	/*for(int i=0;i<3;i++)
	{
		LCD_ShowNum(50, i*20,Rec_Data[i],5,16);
	}*/
}

