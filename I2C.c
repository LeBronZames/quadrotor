#include "hardware.h"


//static 

/******************************************************************************
函数原型:	void I2C2_Int(void)
功　　能:	初始化I2C总线
*******************************************************************************/ 
void IIC_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE); //打开外设B的时钟
/*
	GPIO_InitStructure.GPIO_Pin = Debug1_Pin | Debug2_Pin | Debug3_Pin; //用于测量程序运行速率
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);		*/

	GPIO_InitStructure.GPIO_Pin = SCL_Pin; //SCL
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //开漏输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = SDA_Pin; //SDA
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
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
	SDA_H;
	SCL_H;
	
	if(!SDA_Read)
		return 0;	//SDA线为低电平则总线忙,退出
	SDA_L;
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
	SDA_L;
	SCL_H;
	SDA_H;
}

/******************************************************************************
函数原型：	static void I2C_ACK(void)	
功    能：	I2C总线Master发送ACK信号
*******************************************************************************/ 
void I2C_ACK(void)
{
	SCL_L;
	
	SDA_L;
	delay_us(2);
	SCL_H;
	delay_us(2);
	SCL_L;    
}

/******************************************************************************
函数原型：	static void I2C_NACK(void)	
功    能：	I2C总线Master发送NACK信号
*******************************************************************************/ 
void I2C_NACK(void)
{
	SCL_L;
	
	SDA_H;
	delay_us(2);
	SCL_H;
	delay_us(2);
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
	SDA_H;
	SCL_H;
		
	if(SDA_Read)
	{
		SCL_L;
		return 0;	
	}
	
	SCL_L;
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
	}   
	SCL_L;  
}

/******************************************************************************
函数原型：	static uint8_t I2C_ReadByte(void)	
功    能：	I2C读一个字节数据,先读高位
返 回 值：	返回读出的一个字节数据
*******************************************************************************/ 
uint8_t I2C_ReadByte(void)
{
	unsigned char i,receive=0;

    for(i=0;i<8;i++ )
	{
        SCL_L; 
        delay_us(2);
		SCL_H;
        receive<<=1;
        if(SDA_Read)receive++;   
		delay_us(1); 
    }					 
  
    return receive;
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
	I2C_WriteByte(Regs_Addr);    //写寄存器地址
	I2C_WaitAck();
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
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//无ACK，返回
	}
	
	I2C_WriteByte(Regs_Addr);    	//写寄存器地址
	I2C_WaitAck();
	I2C_Start();
	I2C_WriteByte(MPU6050Address+1);//写Slave地址，并配置成读模式
	I2C_WaitAck();
	
	ret=I2C_ReadByte();				//从传感器中读出数据

	I2C_NACK();						//无应答
	I2C_Stop();                  	//结束本段IIC进程 
	return ret;	
} 




//IIC连续写
//addr:器件地址 
//reg:寄存器地址
//len:写入长度
//buf:数据区
//返回值:0,正常
//    其他,错误代码
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
	u8 i; 
    I2C_Start(); 
	//led_t(2);
	I2C_WriteByte((addr<<1)|0);//发送器件地址+写命令	
	if(!I2C_WaitAck())	//等待应答
	{
		I2C_Stop();		 
		return 1;		
	}
	//led_t(2);
    I2C_WriteByte(reg);	//写寄存器地址
    I2C_WaitAck();		//等待应答
	for(i=0;i<len;i++)
	{
		I2C_WriteByte(buf[i]);	//发送数据
		if(!I2C_WaitAck())		//等待ACK
		{
			I2C_Stop();	 
			return 1;		 
		}		
	}    
    I2C_Stop();	 
	return 0;	
} 

//u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
//{
//	int i;
//	for(i=0;i<len;i++){
//		Single_WriteI2C_2(addr,reg+i,buf[i]);
//	}
//	
//	return 0;
//	
//	
//}

uint8_t Single_WriteI2C_2(u8 addr,unsigned char Regs_Addr,unsigned char Regs_Data) 
{  
	if( !I2C_Start() )
		return 0;	//I2C起始错误，返回
	I2C_WriteByte((addr<<1)|0); //写Slave地址，并配置成写模式
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//无ACK，返回
	}
	I2C_WriteByte(Regs_Addr);    //写寄存器地址
	I2C_WaitAck();
	I2C_WriteByte(Regs_Data);    //写寄存器数据
	I2C_WaitAck();
	I2C_Stop();         
	return 1;
}
//IIC连续读
//addr:器件地址
//reg:要读取的寄存器地址
//len:要读取的长度
//buf:读取到的数据存储区
//返回值:0,正常
//    其他,错误代码

uint8_t MPU6050_SequenceRead(void)
{
	uint8_t index=14;
	u8 MPU6050_Buffer[14];
	if( !I2C_Start() )
		return 0;	//I2C起始错误，返回
	I2C_WriteByte(MPU6050Address); 	//写Slave地址，并配置成写模式
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//无ACK，返回
	}
	I2C_WriteByte(ACCEL_XOUT_H);    //写寄存器地址
	I2C_WaitAck();
	
	I2C_Start();
	I2C_WriteByte(MPU6050Address+1);//写Slave地址，并配置成读模式
	I2C_WaitAck();

	while(--index)	//连读13位寄存器
	{
		MPU6050_Buffer[13 - index] = I2C_ReadByte();
		I2C_ACK();
	}

	MPU6050_Buffer[13] = I2C_ReadByte();	//读第14寄存器
	I2C_NACK();	
	I2C_Stop();	
	
	return 1;
}
//uint8_t MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
//{
//	uint8_t index=len;
//	
//	if( !I2C_Start() )
//		return 0;	//I2C起始错误，返回
//	I2C_WriteByte((addr<<1)|0); 	//写Slave地址，并配置成写模式
//	if( !I2C_WaitAck() )
//	{
//		I2C_Stop(); 
//		return 1;	//无ACK，返回
//	}
//	I2C_WriteByte(reg);    //写寄存器地址
//	I2C_WaitAck();
//	
//	I2C_Start();
//	I2C_WriteByte((addr<<1)|1);//写Slave地址，并配置成读模式
//	I2C_WaitAck();

//	while(--index)	//连读13位寄存器
//	{
//		buf[len - index - 1] = I2C_ReadByte();
//		I2C_ACK();
//		delay_ms(2);
//	}

//	buf[len-1] = I2C_ReadByte();	//读第14寄存器
//	I2C_NACK();	
//	I2C_Stop();	
//	
//	return 0;
//}


u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	I2C_Start(); 
	I2C_WriteByte((addr<<1)|0);//发送器件地址+写命令	
	if(!I2C_WaitAck())	//等待应答
	{
		I2C_Stop();		 
		return 1;		
	}
    I2C_WriteByte(reg);	//写寄存器地址
    I2C_WaitAck();		//等待应答
    I2C_Start();
	I2C_WriteByte((addr<<1)|1);//发送器件地址+读命令	
    I2C_WaitAck();		//等待应答 
	while(len)
	{
		if(len==1){//*buf=IIC_Read_Byte(0);//读数据,发送nACK 
		
			*buf=I2C_ReadByte();				//从传感器中读出数据
			I2C_NACK();						//无应答
		}
		
		else {*buf=I2C_ReadByte();		//读数据,发送ACK  
			I2C_ACK();
		
			
		}
		
		
		len--;
		buf++; 
	}    
    I2C_Stop();	//产生一个停止条件 
	return 0;	
}



//u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)      //器件内的自加一和外部定义的reg自加不一样
//{
//	int i;
//	for(i=0;i<len;i++){
//		*buf=Single_ReadI2C_2(addr,(reg)+i) ;buf++;
//		
//	}
//	return 0;
//}

uint8_t Single_ReadI2C_2(u8 addr,unsigned char Regs_Addr) 
{
	uint8_t ret;

	if( !I2C_Start() )
		return 0;	//I2C起始错误，返回
	I2C_WriteByte((addr<<1)|0); 	//写Slave地址，并配置成写模式
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//无ACK，返回
	}
	
	I2C_WriteByte(Regs_Addr);    	//写寄存器地址
	I2C_WaitAck();
	I2C_Start();
	I2C_WriteByte((addr<<1)|1);//写Slave地址，并配置成读模式
	I2C_WaitAck();
	
	ret=I2C_ReadByte();				//从传感器中读出数据

	I2C_NACK();						//无应答
	I2C_Stop();                  	//结束本段IIC进程 
	return ret;	
} 

//MPU_Read_Len(0x68, 0x06, 6, data);


//	int i;
//	for(i=0;i<len;i++){
//		*buf=Single_ReadI2C(((addr<<1)+i)|0) ;buf++;
//		
//	}











