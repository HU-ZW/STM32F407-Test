#include "common.h" 

u16 Num_R=50;
u16 Num_X=20, Num_Y=20;
int Temp=0;
int main(void)
{
	All_init();	
	LCD_Clear(BLACK);
	//Picture_Draw(0, 0, UI);
	while(1)
	{
		
		/*Touch_Mission();
		LCD_ShowNum(100, 0,tp_dev.x[0],5,16);
		LCD_ShowNum(100, 20,tp_dev.y[0],5,16);*/
		Car_Task();
		LCD_ShowChar(100,100,Car_CMD,16,0);
		LCD_ShowNum(100, 120,Mode,1,16);
		if(WK_UP==1)
		{
			delay_ms(100);//È¥¶¶¶¯ 
			if( WK_UP==1 && Mode == 1 )	
			{
				LED1(0);
				Mode = 0;
			}
			else if( WK_UP==1 && Mode == 0) 
			{
				LED1(1);
				Mode = 1;
			}
		}
		
	}
}


