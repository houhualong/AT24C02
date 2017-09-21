/************************************************************************************
*  Copyright (c), 2014, HelTec Automatic Technology co.,LTD.
*            All rights reserved.
*
* Http:    www.heltec.cn
* Email:   cn.heltec@gmail.com
* WebShop: heltec.taobao.com
*
* File name: main.c
* Project  : HelTec.uvprij
* Processor: STM32F103C8T6
* Compiler : MDK fo ARM
* 
* Author : С��
* Version: 1.00
* Date   : 2014.4.8
* Email  : hello14blog@gmail.com
* Modification: none
* 
* Description:128*64�����OLED��ʾ�������ļ����������ڻ����Զ���(heltec.taobao.com)��SD1306����IICͨ�ŷ�ʽ��ʾ��
*
* Others: none;
*
* Function List:
*	1. int main(void);//������
*
* History: none;
*
*************************************************************************************/
#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "delay.h"

int main(void)
{
	unsigned char i;
	extern const unsigned char BMP1[];
	
	DelayInit();
	I2C_Configuration();
	OLED_Init();
	
	while(1)
	{
		OLED_Fill(0xFF);//ȫ������
		DelayS(2);
		OLED_Fill(0x00);//ȫ����
		DelayS(2);
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//������ʾ����
		}
		DelayS(2);
		OLED_ShowStr(0,3,"HelTec Automation",1);//����6*8�ַ�
		OLED_ShowStr(0,4,"Hello Tech",2);				//����8*16�ַ�
		DelayS(2);
		OLED_CLS();//����
		OLED_OFF();//����OLED����
		DelayS(2);
		OLED_ON();//����OLED���ߺ���
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//����BMPλͼ��ʾ
		DelayS(2);
	}
}
