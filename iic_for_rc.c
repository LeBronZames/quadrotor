#include "hardware.h"



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



//**************************************
//I2C起始信号
//**************************************
void I2C_Start(void)
{
    SDA_H;                    //拉高数据线
    SCL_H;                    //拉高时钟线
    delay_us(5);                 //延时
    SDA_L;                    //产生下降沿
    delay_us(5);                 //延时
    SCL_L;                    //拉低时钟线
}
//**************************************
//I2C停止信号
//**************************************
void I2C_Stop(void)
{
    SDA_L;                    //拉低数据线
    SCL_H;                    //拉高时钟线
    delay_us(5);                 //延时
    SDA_H;                    //产生上升沿
    delay_us(5);                 //延时
}
//**************************************
//I2C发送应答信号
//入口参数:ack (0:ACK 1:NAK)
//**************************************
void I2C_SendACK(int ack)
{
	if(ack == 0)
    SDA_L;                  //写应答信号
	else if(ack == 1)
		SDA_H;
    SCL_H;                    //拉高时钟线
    delay_us(5);                 //延时
    SCL_L;                    //拉低时钟线
    delay_us(5);                 //延时
}
//**************************************
//I2C接收应答信号
//**************************************
int I2C_RecvACK(void)
{
		int CY;
    SCL_H;                    //拉高时钟线
    delay_us(5);                 //延时
    CY = SDA_Read;                   //读应答信号
    SCL_L;                    //拉低时钟线
    delay_us(5);                 //延时
	
	  while(CY == 1){
			delay_us(5);
		}
		
    return CY;
}
//**************************************
//向I2C总线发送一个字节数据
//**************************************
void I2C_SendByte(int dat)
{
    int i;
    for (i=0; i<8; i++)         //8位计数器
    {
				SCL_L;                //拉低时钟线
        delay_us(5);             //延时
				if( dat&0x80 ) 
				SDA_H;
				else 
				SDA_L;
        dat <<= 1;              //移出数据的最高位
        //SDA = CY;               //送数据口
        SCL_H;                //拉高时钟线
        delay_us(5);             //延时
        
    }
    I2C_RecvACK();
}
//**************************************
//从I2C总线接收一个字节数据
//**************************************
int I2C_RecvByte(void)
{
    int i;
    int dat = 0;
    SDA_H;                    //使能内部上拉,准备读取数据,
    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;
        SCL_H;                //拉高时钟线
        delay_us(5);             //延时
			
			if(SDA_Read)
        dat |= 1;             //读数据  
			else if(!SDA_Read)
				dat |= 0;
			
        SCL_L;                //拉低时钟线
        delay_us(5);             //延时
    }
    return dat;
}
//**************************************
//向I2C设备写入一个字节数据
//**************************************
void Single_WriteI2C(int REG_Address,int REG_data)
{
    I2C_Start();                  //起始信号
    I2C_SendByte(MPU6050Address);   //发送设备地址+写信号
	//led_t();
    I2C_SendByte(REG_Address);    //内部寄存器地址，
	//led_t();
    I2C_SendByte(REG_data);       //内部寄存器数据，
    I2C_Stop();                   //发送停止信号
}
//**************************************
//从I2C设备读取一个字节数据
//**************************************
int Single_ReadI2C(int REG_Address)
{
	int REG_data;
	I2C_Start();                   //起始信号
	I2C_SendByte(MPU6050Address);    //发送设备地址+写信号
	I2C_SendByte(REG_Address);     //发送存储单元地址，从0开始	
	I2C_Start();                   //起始信号
	I2C_SendByte(MPU6050Address+1);  //发送设备地址+读信号
	//led_t();
	REG_data=I2C_RecvByte();       //读出寄存器数据
	I2C_SendACK(1);                //接收应答信号
	I2C_Stop();                    //停止信号
	return REG_data;
}












