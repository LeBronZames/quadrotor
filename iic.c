#include "hardware.h"


//static 

/******************************************************************************
函数原型:	void I2C2_Int(void)
功　　能:	初始化I2C总线
*******************************************************************************/ 
void I2C2_Int(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); //打开外设B的时钟

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//改变指定管脚的映射 GPIO_Remap_SWJ_Disable SWJ 完全禁用（JTAG+SW-DP）
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	//改变指定管脚的映射 GPIO_Remap_SWJ_JTAGDisable ，JTAG-DP 禁用 + SW-DP 使能
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = Debug1_Pin | Debug2_Pin | Debug3_Pin; //用于测量程序运行速率
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);		

	GPIO_InitStructure.GPIO_Pin = SCL_Pin; //SCL
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //开漏输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = SDA_Pin; //SDA
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //开漏输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
}




/******************************************************************************
函数原型:	static void I2C_delay(int delay)
功　　能:	I2C总线延时
*******************************************************************************/ 
void I2C_delay(int delay)
{
    while (delay)
        delay--;
}

/******************************************************************************
函数原型：	static uint8_t I2C_Start(void)	
功    能：	I2C总线开始信号
返 回 值：   1成功；0失败   
*******************************************************************************/ 
uint8_t I2C_Start(void)	
{
	SCL_L;	
	delay_us(5);
	SDA_H;
	delay_us(5);
	SCL_H;
	delay_us(2);
	if(!SDA_Read)
		return 0;	//SDA线为低电平则总线忙,退出
	SDA_L;
	delay_us(2);
	if(SDA_Read) 
		return 0;	//SDA线为高电平则总线出错,退出
	
	SDA_L;
	return 1;
}

/******************************************************************************
函数原型：	static void I2C_Stop(void)	
功    能：	I2C总线停止信号
*******************************************************************************/ 
void I2C_Stop(void)
{
	SCL_L;	
delay_us(5);	
	SDA_L;
	delay_us(5);
	SCL_H;
	delay_us(5);
	SDA_H;
	delay_us(5);
}

/******************************************************************************
函数原型：	static void I2C_ACK(void)	
功    能：	I2C总线Master发送ACK信号
*******************************************************************************/ 
void I2C_ACK(void)
{
	SCL_L; 	
	__nop();//延时一个机器周期
	SDA_L;	//写应答信号
	__nop();
    SCL_H; 
	__nop();
    SCL_L;      
}

/******************************************************************************
函数原型：	static void I2C_NACK(void)	
功    能：	I2C总线Master发送NACK信号
*******************************************************************************/ 
void I2C_NACK(void)
{
	SCL_L; 		
	__nop();
	SDA_H;	//不写应答信号
	__nop();
    SCL_H; 
	__nop();
    SCL_L;  
}

/******************************************************************************
函数原型：	static uint8_t I2C_WaitAck(void)	
功    能：	I2C总线Master接收Slave应答
返 回 值：	1有收到ACK；0收到NACK  
*******************************************************************************/ 
uint8_t I2C_WaitAck(void)
{
	SCL_L;
	delay_us(5);	
	SDA_H;
	delay_us(5);
	SCL_H;
	
	while(SDA_Read)
	{
		SCL_H;
		//return 0;	
	}
	//led_t();
	SCL_L;
	delay_us(5);
	return 1;	  
}
/******************************************************************************
函数原型：	static void I2C_WriteByte(unsigned char SendByte) 	
功    能：	I2C写一个字节数据,先写高位
*******************************************************************************/ 
void I2C_WriteByte(unsigned char SendByte) 
{
	uint8_t i=8; 
	
	while(i--)
	{
		
		SCL_L;
		if( SendByte&0x80 ) 
			SDA_H;
		else 
			SDA_L;
		SendByte <<= 1;
		SCL_H;
		delay_us(5);
	}   
	SCL_L;  
	delay_us(5);
}

/******************************************************************************
函数原型：	static uint8_t I2C_ReadByte(void)	
功    能：	I2C读一个字节数据,先读高位
返 回 值：	返回读出的一个字节数据
*******************************************************************************/ 
uint8_t I2C_ReadByte(void)
{
	uint8_t i=8;
	uint8_t ReceiveByte =0;
	
	SDA_H;
	while(i--)
	{
		SCL_L;  
		__nop();
		SCL_H; 		
		ReceiveByte <<= 1;
		if(SDA_Read) 
			ReceiveByte |= 0x01;
	}
	SCL_L;
	return ReceiveByte;
}

/******************************************************************************
函数原型：	static uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) 	
功    能：	写MPU6050寄存器
返 回 值：	0出错；1成功
*******************************************************************************/ 
uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) 
{  
	if( !I2C_Start() )
		return 0;	//I2C起始错误，返回
	I2C_WriteByte(MPU6050Address); //写Slave地址，并配置成写模式
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//无ACK，返回
	}
	//led_t();
	I2C_WriteByte(Regs_Addr);    //写寄存器地址
	I2C_WaitAck();
	led_t();
	I2C_WriteByte(Regs_Data);    //写寄存器数据
	I2C_WaitAck();
	I2C_Stop();         
	return 1;
}
/******************************************************************************
函数原型：	static uint8_t Single_ReadI2C(unsigned char Regs_Addr) 	
功    能：	读MPU6050单字节
返 回 值：	寄存器值
*******************************************************************************/ 
uint8_t Single_ReadI2C(unsigned char Regs_Addr) 
{
	uint8_t ret;
  
	if( !I2C_Start() )
		return 0;	//I2C起始错误，返回
	I2C_WriteByte(MPU6050Address); 	//写Slave地址，并配置成写模式
	
	/*if( !I2C_WaitAck() )
	{
		//led_t();
		I2C_Stop(); 
		return 0;	//无ACK，返回
	}*/
	I2C_WaitAck();
	I2C_WriteByte(Regs_Addr);    	//写寄存器地址
	led_t();
	I2C_WaitAck();
	//led_t();
	I2C_Start();
	I2C_WriteByte(MPU6050Address+1);//写Slave地址，并配置成读模式
	I2C_WaitAck();
	//led_t();
	
	
	
	ret=I2C_ReadByte();				//从传感器中读出数据

	I2C_NACK();						//无应答
	I2C_Stop();                  	//结束本段IIC进程 
	return ret;	
} 


























