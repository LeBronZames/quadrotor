
#include "hardware.h"
//#include  "fond.h"






int draw_point(u16 a, u16 b, u16 color) //四个像素为一个点
{
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((a>>8), 1);TFT_WRITE((a&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((b>>8), 1);TFT_WRITE((b&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//***************************************
	TFT_WRITE(0x2b, 0);
	TFT_WRITE(((a+1)>>8), 1);TFT_WRITE(((a+1)&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE(((b)>>8), 1);TFT_WRITE((b&0XFF),1);
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//***************************************
	TFT_WRITE(0x2b, 0);
	TFT_WRITE(((a)>>8), 1);TFT_WRITE((a&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE(((b+1)>>8), 1);TFT_WRITE(((b+1)&0XFF),1);
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//***************************************
	TFT_WRITE(0x2b, 0);
	TFT_WRITE(((a+1)>>8), 1);TFT_WRITE(((a+1)&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE(((b+1)>>8), 1);TFT_WRITE(((b+1)&0XFF),1);
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	
	return 1;
}



int draw_point_one(u16 a, u16 b, u16 color)
{
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((a>>8), 1);TFT_WRITE((a&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((b>>8), 1);TFT_WRITE((b&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//delay_us(10);
	//***************************************
	return 1;
}
/*
void draw_point_word(u16 a, u16 b, u16 color)
{
	TFT_WRITE(0x2a,0); 
		TFT_WRITE(a>>8 ,1);TFT_WRITE(a&0XFF ,1);  			 
		TFT_WRITE(0x2b,0); 
		TFT_WRITE(b>>8,1);TFT_WRITE(b&0XFF,1); 
	RS_CLR;
 	CS_CLR; 
	TFT_WRITE(0x2c,0);//写指令  
	WR_CLR; 
	WR_SET; 
 	CS_SET; 
	TFT_WRITE_16(color,1);		//写数据
}

*/
void draw_color(int rand)
{
	u16 a;
	u16 b;
	u16 c;
	u16 d;
	u8 add_x;
	//int mmmmmmm;
	//mmmmmmm = 1;
	switch(rand)
	{
		case 0: {add_x = 0;break;}
		case 1: {add_x = 85;break;}
		case 2: {add_x = 170;break;}
	}
	c= 10 + add_x;
	d = 175;
	a = 10; 
	b = 175;	
	
	//******************P_1_1****************************//
	//if(mmmmmmm == 1)
	{
	
	//line1
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c;
	
	b = b - 1;
	
	//line2
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = c;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = c;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = c;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = c;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C3 ,1)); a = c;
	
	b = d;
	}	
	
	
	//**************page_1_2***************************//
	a = c + 10;
	b = d;
	
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 10;
	
	b = b - 1;
	
	//line2
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 10;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(C1 ,1)); a = c + 10;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = c + 10;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c + 10;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c + 10;
	
	b = d;	
	}
	
	
	
	
	//***************page_1_3***************************//
	a = c + 20;
	b = d;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 20;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 20;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = d;
	
	}
	//***************page_1_4***************************//
	a = c + 30;
	b = d;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 30;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 30;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 30;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = c + 30;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 30;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = c + 30;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	//line8
	b = b - 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 30;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	}
	
	
	
	
	
	
	
	//***************page_1_5***************************//
	a = c + 40;
	b = d;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = c + 40;
	
	b = b - 1;
	
	
	
	}
	
	//***************page_2_1***************************//
	a = c;
	b = d - 10;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c;
	
	b = b - 1;	
	//line3
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c;
	
	b = b - 1;	
	//line4
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c;
	
	b = b - 1;	
	//line5
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c;
	
	b = b - 1;	
	//line6
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c;
	
	b = b - 1;	
	//line7
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c;
	
	b = b - 1;	
	
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(0 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c;
	
	b = b - 1;
	
	}
	
	//***************page_2_2***************************//
	a = c + 10;
	b = d - 10;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 10;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	
	
	}
	
	//***************page_2_3***************************//
	a = c + 20;
	b = d - 10;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 20;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c + 20;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = c + 20;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	
	}
	//***************page_2_4***************************//
	a = c + 30;
	b = d - 10;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c + 30;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	}
	//***************page_2_5***************************//
	a = c + 40;
	b = d - 10;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c + 40;
	
	b = b - 1;
	}
	
	//***************page_3_1***************************//
	a = c ;
	b = d - 20;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c ;
	
	b = b - 1;
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c2 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c5 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	}
	//***************page_3_2***************************//
	a = c + 10;
	b = d - 20;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +10;
	
	b = b - 1;
	
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +10;
	
	b = b - 1;
	}
	//***************page_3_3***************************//
	a = c + 20;
	b = d - 20;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +20;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c +20;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +20;
	
	b = b - 1;
	}
	//***************page_3_4***************************//
	a = c + 30;
	b = d - 20;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
		//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,3)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,3)); a = c +30;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	}
	//***************page_3_5***************************//
	a = c + 40;
	b = d - 20;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +40;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +40;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +40;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c +40;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +40;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c +40;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c +40;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c +40;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c +40;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = c +40;
	
	b = b - 1;
	}
	
	//***************page_4_1***************************//
	a = c ;
	b = d - 30;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c4 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	
	
	}
	//***************page_4_2***************************//
	a = c + 10;
	b = d - 30;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 10;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,5)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,5)); a = c + 10;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c + 10;
	
	b = b - 1;
	}
	//***************page_4_3***************************//
	a = c + 20;
	b = d - 30;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c6 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 20;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = c + 20;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = c + 20;
	
	b = b - 1;
	}
	//***************page_4_4***************************//
	a = c + 30;
	b = d - 30;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c + 30;
	
	b = b - 1;
	}
	//***************page_4_5***************************//
	a = c + 40;
	b = d - 30;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c + 40;
	
	b = b - 1;
	
	}
	//***************page_5_1***************************//
	a = c ;
	b = d - 40;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c ;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c ;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c ;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = c ;
	
	b = b - 1;
	}
	
	//***************page_5_2***************************//
	
	a = c +10;
	b = d - 40;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +10;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = c +10;
	
	b = b - 1;
	}
	
	//***************page_5_3***************************//
	a = c +20;
	b = d - 40;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = c +20;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = c +20;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +20;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +20;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +20;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +20;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +20;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +20;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = c +20;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = c +20;
	
	b = b - 1;
	}
	//***************page_5_4***************************//
	a = c +30;
	b = d - 40;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +30;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c8 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c10 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +30;
	
	b = b - 1;
	}
	//***************page_5_5***************************//
	a = c +40;
	b = d - 40;
	//if(mmmmmmm == 1)
	{
	//line1
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c +40;
	
	b = b - 1;
	//line2
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c +40;
	
	b = b - 1;
	//line3
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c9 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,0)); a = c +40;
	
	b = b - 1;
	//line4
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +40;
	
	b = b - 1;
	//line5
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c4 ,1)); a = c +40;
	
	b = b - 1;
	//line6
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +40;
	
	b = b - 1;
	//line7
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = c +40;
	
	b = b - 1;
	//line8
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = c +40;
	
	b = b - 1;
	//line9
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +40;
	
	b = b - 1;
	//line10
	draw_point_one(a, b, RGB888ToRGB565(c3 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c1 ,1)); a = a + 1;
	draw_point_one(a, b, RGB888ToRGB565(c5 ,1)); a = c +40;
	
	b = b - 1;
	}
	
	
}



void draw_circle(void)
{
	int a;
	int b;
	int c;
	int d;
	int b_buf;
	a = 175;
	b = 275;
	c = 175;
	d = 275;
	
	
	a = c ;
	b = d ;
	//if(mmmmmmm == 1)
	
	//line1
	b= d-8;
	for(a=189;a<=(189 + 8);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	//line2
	for(a=(189 -3);a<=(189+8 +3);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line3
	for(a=(189 -3 - 2);a<=(189+8 +3 + 2);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line4
	for(a=(189 -3 - 2-1);a<=(189+8 +3 + 2+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line5
	for(a=(189 -3 - 2-1-1);a<=(189+8 +3 + 2+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	//line6
	for(a=(189 -3 - 2-1-1-1);a<=(189+8 +3 + 2+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line7
	for(a=(189 -3 - 2-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	//line8
	for(a=(189 -3 - 2-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	//line9
	for(a=(189 -3 - 2-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line10
	for(a=(189 -3 - 2-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	//line11
	for(a=(189 -3 - 2-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line12
	for(a=(189 -3 - 2-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line13
	for(a=(189 -3 - 2-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line14
	for(a=(189 -3 - 2-1-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line15
	for(a=(189 -3 - 2-1-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line16
	for(a=(189 -3 - 2-1-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	if(kir == 1)
	{
		a = 193;
		for(a=(189 -3 - 2-1-1-1-1-1-1-1-1-20);a<=(189 -3 - 2-1-1-1-1-1-1-1-1-5);a++)
		{
			draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
		}
		for(a=(189+8 +3 + 2+1+1+1+1+1+1+1+1+5);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1+20);a++)
		{
			draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
		}
	}
	else 
	{
		a = 193;
		for(a=(189 -3 - 2-1-1-1-1-1-1-1-1-20);a<=(189 -3 - 2-1-1-1-1-1-1-1-1-5);a++)
		{
			draw_point(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
		}
		for(a=(189+8 +3 + 2+1+1+1+1+1+1+1+1+5);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1+20);a++)
		{
			draw_point(a, b, RGB888ToRGB565(c5 ,1)); a = a + 1;
		}
	}
	
	b = b - 1;
	
	//line16
	for(a=(189 -3 - 2-1-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line15
	for(a=(189 -3 - 2-1-1-1-1-1-1-1-1);a<=(189+8+3 + 2+1+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line14
	for(a=(189 -3 - 2-1-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line13
	for(a=(189 -3 - 2-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line12
	for(a=(189 -3 - 2-1-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line11
	for(a=(189 -3 - 2-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line10
	for(a=(189 -3 - 2-1-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line9
	for(a=(189 -3 - 2-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line8
	for(a=(189 -3 - 2-1-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	//line7
	for(a=(189 -3 - 2-1-1-1-1);a<=(189+8 +3 + 2+1+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line6
	for(a=(189 -3 - 2-1-1-1);a<=(189+8 +3 + 2+1+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line5
	for(a=(189 -3 - 2-1-1);a<=(189+8 +3 + 2+1+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line4
	for(a=(189 -3 - 2-1);a<=(189+8 +3 + 2+1);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line3
	for(a=(189 -3 - 2);a<=(189+8 +3 + 2);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line2
	for(a=(189 -3);a<=(189+8 +3);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	//line1
	b= b - 1;
	for(a=189;a<=(189 + 8);a++)
	{
		draw_point(a, b, RGB888ToRGB565(c7 ,1)); a = a + 1;
	}
	b = b - 1;
	
	b_buf = b;
	
	if(kir == 1)
	{ 
		a = 193;
		for(b = b_buf-5;b>=b_buf-5-15;b--)
		{
			draw_point(a, b, RGB888ToRGB565(c7 ,1)); b = b - 1;
		}
		for(b=275;b<=275+15;b++)
		{
			draw_point(a, b, RGB888ToRGB565(c7 ,1)); b = b + 1;
		}
	}
	else 
	{
		a = 193;
		for(b = b_buf-5;b>=b_buf-5-15;b--)
		{
			draw_point(a, b, RGB888ToRGB565(c5 ,1)); b = b - 1;
		}
		for(b=275;b<=275+15;b++)
		{
			draw_point(a, b, RGB888ToRGB565(c5 ,1)); b = b + 1;
		}
	}
	
	
	
}




















































void TFT_clear(u16 color)
{
	int a;
	a = 96800;
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	
	for(;a >=0;a--)
	{
		TFT_WRITE_16(color, 1);
	}
}


void TFT_clear_diglett(void)
{
	int x; 
	int y; x=10;y=180;
	
		
	for(x=10;x<=230;x++)
	{
		y = 126;
		TFT_WRITE(0x2b, 0);
		TFT_WRITE((x>>8), 1);TFT_WRITE((x&0XFF),1);
		
		TFT_WRITE(0x2a, 0);
		TFT_WRITE((y>>8), 1);TFT_WRITE((y&0XFF),1);
		
		TFT_WRITE(0x2c, 0);
		for(y=126;y<=180;y++)
		{
			TFT_WRITE_16(0xffff, 1);
		}
	
	}
	  
}


void TFT_clear_num_1(void)
{
	int x; 
	int y; x=30;y=190;
	
		
	for(x=30;x<=70;x++)
	{
		y = 190;
		TFT_WRITE(0x2b, 0);
		TFT_WRITE((x>>8), 1);TFT_WRITE((x&0XFF),1);
		
		TFT_WRITE(0x2a, 0);
		TFT_WRITE((y>>8), 1);TFT_WRITE((y&0XFF),1);
		
		TFT_WRITE(0x2c, 0);
		for(y=190;y<=230;y++)
		{
			TFT_WRITE_16(0xffff, 1);
		}
	
	}
	  
}

void TFT_clear_num_2(void)
{
	int x; 
	int y; x=160;y=80;
	
		
	for(x=140;x<=210;x++)
	{
		y = 40;
		TFT_WRITE(0x2b, 0);
		TFT_WRITE((x>>8), 1);TFT_WRITE((x&0XFF),1);
		
		TFT_WRITE(0x2a, 0);
		TFT_WRITE((y>>8), 1);TFT_WRITE((y&0XFF),1);
		
		TFT_WRITE(0x2c, 0);
		for(y=40;y<=80;y++)
		{
			TFT_WRITE_16(0xffff, 1);
		}
	
	}
	  
}



void TFT_background(u16 color)
{
	int a;
	int x;
	int y;x=10;y=125;
	a = 96800;
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	
	for(;a >=0;a--)
	{
		TFT_WRITE_16(color, 1);
	}
	
	for(y=125;y>=100;y--)
	{
		for(x=10;x<=230;x++)
		{
			draw_point_one(x, y, RGB888ToRGB565(c10 ,1));
		}
	
	}
}








void draw_Diglett(int Diglett_sel) //简约风地鼠
{
	u16 a;
	u16 b;
	b = 140;
	
	switch(Diglett_sel)
	{
		case 1:
		{
			a = 30;
			for (;a <= 60;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**************************
			b = 170;
			a = 30;
			for (;a <= 60;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**************************
			b = 185;
			a = 30;
			for (;a <= 40;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			b = 185;
			a = 50;
			for (;a <= 60;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//****************************
			b = 155;
			a = 36;
			for (;a <= 42;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//******************************
			b = 155;
			a = 48;
			for (;a <= 54;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//*******************************
			b = 161;
			a = 36;
			for (;a <= 42;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//********************************
			b = 161;
			a = 48;
			for (;a <= 54;a = a+2)
			{
				draw_point(a, b, 0x5656);
			}
			//*************x over***********//
			b = 140;
			a = 30;
			for (;b <= 185;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 140;
			a = 60;
			for (;b <= 185;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 170;
			a = 40;
			for (;b <= 185;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 170;
			a = 50;
			for (;b <= 185;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 155;
			a = 36;
			for (;b <= 161;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 155;
			a = 42;
			for (;b <= 161;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 155;
			a = 48;
			for (;b <= 161;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//**********************************
			b = 155;
			a = 54;
			for (;b <= 161;b = b+2)
			{
				draw_point(a, b, 0x5656);
			}
			//***********y over******************
			b = 146;
			a = 45;
			draw_point(a, b, 0x5656);
			
			
			break;
		}
		
		
		
		
		
		
	}
	
}












