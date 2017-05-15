#include "hardware.h"




int TFT_init(void)
{
	TFT_io_init();
	
	
	
	TFT_WRITE(0xCF,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xC1,1);
	TFT_WRITE(0x30,1);
	TFT_WRITE(0xED,0);
	TFT_WRITE(0x64,1);
	TFT_WRITE(0x03,1);
	TFT_WRITE(0x12,1);
	TFT_WRITE(0x81,1);
	TFT_WRITE(0xE8,0);
	TFT_WRITE(0x85,1);
	TFT_WRITE(0x10,1);
	TFT_WRITE(0x7A,1);
	TFT_WRITE(0xCB,0);
	TFT_WRITE(0x39,1);
	TFT_WRITE(0x2C,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x34,1);
	TFT_WRITE(0x02,1);
	TFT_WRITE(0xF7,0);
	TFT_WRITE(0x20,1);
	TFT_WRITE(0xEA,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xc0,0);
	TFT_WRITE(0x1b,1);
	TFT_WRITE(0xc1,1);
	TFT_WRITE(0x01,1);
	TFT_WRITE(0xc5,0);
	TFT_WRITE(0x30,1);
	TFT_WRITE(0x30,1);
	TFT_WRITE(0xc7,0);
	TFT_WRITE(0xb7,1);
	
	TFT_WRITE(0x36,0);
	TFT_WRITE(0x48,1);
	TFT_WRITE(0x3a,0);
	TFT_WRITE(0x55,1);
	TFT_WRITE(0xb1,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x1a,1);
	TFT_WRITE(0xb6,0);
	TFT_WRITE(0x0a,1);
	TFT_WRITE(0xa2,1);
	TFT_WRITE(0xf2,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x26,0);
	TFT_WRITE(0x01,1);
	TFT_WRITE(0xe0,0);
	TFT_WRITE(0x0f,1);
	TFT_WRITE(0x2a,1);
	TFT_WRITE(0x28,1);
	TFT_WRITE(0x08,1);
	TFT_WRITE(0x0e,1);
	TFT_WRITE(0x08,1);
	TFT_WRITE(0x54,1);
	TFT_WRITE(0xa9,1);
	TFT_WRITE(0x43,1);
	TFT_WRITE(0x0a,1);
	TFT_WRITE(0x0f,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xe1,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x15,1);
	TFT_WRITE(0x17,1);
	TFT_WRITE(0x07,1);
	TFT_WRITE(0x11,1);
	TFT_WRITE(0x06,1);
	TFT_WRITE(0x2b,1);
	TFT_WRITE(0x56,1);
	TFT_WRITE(0x3c,1);
	TFT_WRITE(0x05,1);
	TFT_WRITE(0x10,1);
	TFT_WRITE(0x0f,1);
	TFT_WRITE(0x3f,1);
	TFT_WRITE(0x0f,1);
	
	TFT_WRITE(0x2b,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xe1,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0x2a,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xe1,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0x2a,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0x11,0);
	
	//delay_ms(10);
	
	TFT_WRITE(0x29,0);
	TFT_WRITE(0x36,0);
	TFT_WRITE(0x6c,1);
	TFT_WRITE(0x2c,0);
	
	
	
	return 1;
	

	
}


void TFT_test(void)
{
	
	TFT_WRITE_16(0xbb25,1);
	
}



void TFT_io_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure;
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	 GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;			
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		
   GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIO
	 GPIO_SetBits(GPIOB,GPIO_Pin_All);						 //输出高
	
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6 ;				
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		
   GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIO
	 GPIO_SetBits(GPIOC,GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6);						 //输出高
	
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				 //PC13 端口配置
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
   GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOc.13
   GPIO_SetBits(GPIOC,GPIO_Pin_10);						 //PC.13 输出高
	
	
}


void TFT_WRITE(u8 data_reg, int flag)
{
	RD_SET;
	CS_CLR;
	if(flag == 0)
	{
	RS_CLR;
	}
	else if(flag == 1) //rs是1为数据
	{
		RS_SET;
	}
	WR_CLR;
	GPIO_SetBits(GPIOB,(data_reg & 0xFFFF));//DATAOUT(data);
	GPIO_ResetBits(GPIOB,((~data_reg) & 0xFFFF));//DATAOUT(data);
	WR_SET;
	
}
/*
void TFT_data(u8 data_reg)
{
	RD_SET;
	CS_CLR;
	RS_SET;
	WR_CLR;
	GPIO_SetBits(GPIOB,(data_reg & 0xFFFF));//DATAOUT(data);
	GPIO_ResetBits(GPIOB,((~data_reg) & 0xFFFF));//DATAOUT(data);
	WR_SET;
	
}
*/

void TFT_WRITE_16(u16 data, int flag)
{
	RD_SET;
	CS_CLR;
	if(flag == 0)
	{
	RS_CLR;
	}
	else if(flag == 1) //rs是1为数据
	{
		RS_SET;
	}
	WR_CLR;
	GPIO_SetBits(GPIOB,(data & 0xFFFF));//DATAOUT(data);
	GPIO_ResetBits(GPIOB,((~data) & 0xFFFF));//DATAOUT(data);
	WR_SET;
	
	
}

