/*
  程序说明: CT117E嵌入式竞赛板GPIO模拟I2C总线驱动程序
  软件环境: Keil uVision 4.10 
  硬件环境: CT117E嵌入式竞赛板
  日    期: 2011-8-9
*/

#include "stm32f10x.h"
#include "hardware.h"

/** I2C 总线接口 */
#define I2C_PORT GPIOB
//#define SDA_Pin	GPIO_Pin_7
//#define SCL_Pin GPIO_Pin_6

#define FAILURE 0
#define SUCCESS 1

//配置SDA信号线为输入模式
void SDA_Input_Mode(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SDA_Pin;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 

  	GPIO_Init(I2C_PORT, &GPIO_InitStructure);
}

//配置SDA信号线为输出模式
void SDA_Output_Mode(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SDA_Pin;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

  	GPIO_Init(I2C_PORT, &GPIO_InitStructure);
}

//
void SDA_Output( uint16_t val )
{
	if ( val ) {
		GPIO_SetBits(I2C_PORT,SDA_Pin);
	} else {
		GPIO_ResetBits(I2C_PORT,SDA_Pin);
	}
}

//
void SCL_Output( uint16_t val )
{
	if ( val ) {
		GPIO_SetBits(I2C_PORT,SCL_Pin);
	} else {
		GPIO_ResetBits(I2C_PORT,SCL_Pin);
	}
}

//
uint8_t SDA_Input(void)
{
	return GPIO_ReadInputDataBit( I2C_PORT, SDA_Pin);
}

//延时程序
void delay1(unsigned int n)
{
	unsigned int i;
	for ( i=0;i<n;++i);
}

//I2C总线启动
void I2CStart(void)
{
	SDA_Output(1);//delay_us(1);
	SCL_Output(1);//delay_us(1);
	SDA_Output(0);//delay_us(1);
	SCL_Output(0);//delay_us(1);
}

//I2C总线停止
void I2CStop(void)
{
	SCL_Output(0); //delay_us(1);
	SDA_Output(0); //delay_us(1);
	SCL_Output(1); //delay_us(1);
	SDA_Output(1); //delay_us(1);

}

//等待应答
unsigned char I2CWaitAck(void)
{
	unsigned short cErrTime = 5;
	SDA_Input_Mode(); 
	//delay_us(1);
	SCL_Output(1);//delay_us(1);
	while(SDA_Input())
	{
		cErrTime--;
		//delay_us(1);
		if (0 == cErrTime)
		{
			SDA_Output_Mode();
			I2CStop();
			return FAILURE;
		}
	}
	SDA_Output_Mode();
	SCL_Output(0);//delay_us(1); 
	return SUCCESS;
}

//发送应答位
void I2CSendAck(void)
{
	SDA_Output(0);//delay_us(1);
	//delay_us(1);
	SCL_Output(1); //delay_us(1);
	SCL_Output(0); //delay_us(1);

}

//
void I2CSendNotAck(void)
{
	SDA_Output(1);
	//delay_us(1);
	SCL_Output(1); //delay_us(1);
	SCL_Output(0); //delay_us(1);

}

//通过I2C总线发送一个字节数据
void I2CSendByte(unsigned char cSendByte)
{
	unsigned char  i = 8;
	while (i--)
	{
		SCL_Output(0);//delay_us(1); 
		SDA_Output(cSendByte & 0x80); //delay_us(1);
		cSendByte += cSendByte;
		//delay_us(1); 
		SCL_Output(1);//delay_us(1);
	}
	SCL_Output(0);//delay_us(1); 
}

//从I2C总线接收一个字节数据
unsigned char I2CReceiveByte(void)
{
	unsigned char i = 8;
	unsigned char cR_Byte = 0;
	SDA_Input_Mode(); 
	while (i--)
	{
		cR_Byte += cR_Byte;
		SCL_Output(0);//delay_us(1);
		//delay_us(1); 
		SCL_Output(1);//delay_us(1);
		cR_Byte |=  SDA_Input(); 
	}
	SCL_Output(0);//delay_us(1);
	SDA_Output_Mode();
	return cR_Byte;
}

//I2C总线初始化
void i2c_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SDA_Pin | SCL_Pin;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 // **

  	GPIO_Init(I2C_PORT, &GPIO_InitStructure);

}

void I2cWrite(unsigned char address,unsigned char data)
{
	I2CStart();
	I2CSendByte(MPU6050Address);
	I2CWaitAck();
	I2CSendByte(address);
	I2CWaitAck();
	I2CSendByte(data);
	I2CWaitAck();
	I2CStop();
}

unsigned char I2cRead(unsigned char address)
{
	unsigned char value;
	I2CStart();
	I2CSendByte(MPU6050Address);
	I2CWaitAck();
	I2CSendByte(address);
	I2CWaitAck();
	I2CStart();
	I2CSendByte(MPU6050Address+1);
	I2CWaitAck();
	value = I2CReceiveByte();
	I2CWaitAck();
	I2CStop();	
	return value;
}


u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	I2CStart(); 
	I2CSendByte((addr<<1)|0);//·¢ËÍÆ÷¼þµØÖ·+Ð´ÃüÁî	
	I2CWaitAck();
    I2CSendByte(reg);	//Ð´¼Ä´æÆ÷µØÖ·
    I2CWaitAck();		//µÈ´ýÓ¦´ð
    I2CStart();
	I2CSendByte((addr<<1)|1);//·¢ËÍÆ÷¼þµØÖ·+¶ÁÃüÁî	
    I2CWaitAck();		//µÈ´ýÓ¦´ð 
	while(len)
	{
		if(len==1){//*buf=IIC_Read_Byte(0);//¶ÁÊý¾Ý,·¢ËÍnACK 
		
			*buf=I2CReceiveByte();				//´Ó´«¸ÐÆ÷ÖÐ¶Á³öÊý¾Ý
			I2CSendNotAck();						//ÎÞÓ¦´ð
		}
		
		else {*buf=I2CReceiveByte();		//¶ÁÊý¾Ý,·¢ËÍACK  
			I2CSendAck();
		
			
		}
		
		
		len--;
		buf++; 
	}    
    I2CStop();	//²úÉúÒ»¸öÍ£Ö¹Ìõ¼þ 
	return 0;	
}

u8 MPU_Read_Len_1(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	I2CStart(); 
	I2CSendByte(MPU6050Address);//·¢ËÍÆ÷¼þµØÖ·+Ð´ÃüÁî	
	I2CWaitAck();
    I2CSendByte(reg);	//Ð´¼Ä´æÆ÷µØÖ·
    I2CWaitAck();		//µÈ´ýÓ¦´ð
    I2CStart();
	I2CSendByte(MPU6050Address+1);//·¢ËÍÆ÷¼þµØÖ·+¶ÁÃüÁî	
    I2CWaitAck();		//µÈ´ýÓ¦´ð 
	while(len)
	{
		if(len==1){//*buf=IIC_Read_Byte(0);//¶ÁÊý¾Ý,·¢ËÍnACK 
		
			*buf=I2CReceiveByte();				//´Ó´«¸ÐÆ÷ÖÐ¶Á³öÊý¾Ý
			I2CSendNotAck();						//ÎÞÓ¦´ð
		}
		
		else {*buf=I2CReceiveByte();		//¶ÁÊý¾Ý,·¢ËÍACK  
			I2CSendAck();
		
			
		}
		
		
		len--;
		buf++; 
	}    
    I2CStop();	//²úÉúÒ»¸öÍ£Ö¹Ìõ¼þ 
	return 0;	
}

u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
	u8 i; 
    I2CStart(); 
	//led_t(2);
	I2CSendByte((addr<<1)|0);//·¢ËÍÆ÷¼þµØÖ·+Ð´ÃüÁî	
	I2CWaitAck();
	//led_t(2);
    I2CSendByte(reg);	//Ð´¼Ä´æÆ÷µØÖ·
    I2CWaitAck();		//µÈ´ýÓ¦´ð
	for(i=0;i<len;i++)
	{
		I2CSendByte(buf[i]);	//·¢ËÍÊý¾Ý
		I2CWaitAck();		
	}    
    I2CStop();	 
	return 0;	
}






