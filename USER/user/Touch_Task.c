#include "common.h"

stKEY sKEY;

void Touch_Mission(void)
{
	tp_dev.scan(0);//扫描
	if( tp_dev.sta&TP_PRES_DOWN )//屏幕按下
	{
		if(tp_dev.x[0]<lcddev.width && tp_dev.y[0]<lcddev.height)//范围正确
		{
			if(tp_dev.x[0]>6 && tp_dev.x[0]<96 && tp_dev.y[0]>124 && tp_dev.y[0]<174)//划范围 0<x<70
			{
				sKEY.Increase = 1;
			}
			else if(tp_dev.x[0]>226 && tp_dev.x[0]<316 && tp_dev.y[0]>124 && tp_dev.y[0]<174)
			{
				sKEY.Decrease = 1;
			}
			else if(tp_dev.x[0]>116 && tp_dev.x[0]<206 && tp_dev.y[0]>124 && tp_dev.y[0]<174)
			{
				sKEY.Up = 1;
			}
			else if(tp_dev.x[0]>6 && tp_dev.x[0]<96 && tp_dev.y[0]>180 && tp_dev.y[0]<230)
			{
				sKEY.Left = 1;
			}
			else if(tp_dev.x[0]>116 && tp_dev.x[0]<206 && tp_dev.y[0]>180 && tp_dev.y[0]<230)
			{
				sKEY.Down = 1;
			}
			else if(tp_dev.x[0]>226 && tp_dev.x[0]<316 && tp_dev.y[0]>180 && tp_dev.y[0]<230)
			{
				sKEY.Right = 1;
			}
		}
	}
	
}

	
