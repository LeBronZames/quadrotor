#include "hardware.h"


//static 

/******************************************************************************
����ԭ��:	void I2C2_Int(void)
��������:	��ʼ��I2C����
*******************************************************************************/ 
void I2C2_Int(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); //������B��ʱ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//�ı�ָ���ܽŵ�ӳ�� GPIO_Remap_SWJ_Disable SWJ ��ȫ���ã�JTAG+SW-DP��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	//�ı�ָ���ܽŵ�ӳ�� GPIO_Remap_SWJ_JTAGDisable ��JTAG-DP ���� + SW-DP ʹ��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = Debug1_Pin | Debug2_Pin | Debug3_Pin; //���ڲ���������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(GPIOB, &GPIO_InitStructure);		

	GPIO_InitStructure.GPIO_Pin = SCL_Pin; //SCL
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //��©���
	GPIO_Init(GPIOB, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = SDA_Pin; //SDA
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //��©���
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
}




/******************************************************************************
����ԭ��:	static void I2C_delay(int delay)
��������:	I2C������ʱ
*******************************************************************************/ 
void I2C_delay(int delay)
{
    while (delay)
        delay--;
}

/******************************************************************************
����ԭ�ͣ�	static uint8_t I2C_Start(void)	
��    �ܣ�	I2C���߿�ʼ�ź�
�� �� ֵ��   1�ɹ���0ʧ��   
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
		return 0;	//SDA��Ϊ�͵�ƽ������æ,�˳�
	SDA_L;
	delay_us(2);
	if(SDA_Read) 
		return 0;	//SDA��Ϊ�ߵ�ƽ�����߳���,�˳�
	
	SDA_L;
	return 1;
}

/******************************************************************************
����ԭ�ͣ�	static void I2C_Stop(void)	
��    �ܣ�	I2C����ֹͣ�ź�
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
����ԭ�ͣ�	static void I2C_ACK(void)	
��    �ܣ�	I2C����Master����ACK�ź�
*******************************************************************************/ 
void I2C_ACK(void)
{
	SCL_L; 	
	__nop();//��ʱһ����������
	SDA_L;	//дӦ���ź�
	__nop();
    SCL_H; 
	__nop();
    SCL_L;      
}

/******************************************************************************
����ԭ�ͣ�	static void I2C_NACK(void)	
��    �ܣ�	I2C����Master����NACK�ź�
*******************************************************************************/ 
void I2C_NACK(void)
{
	SCL_L; 		
	__nop();
	SDA_H;	//��дӦ���ź�
	__nop();
    SCL_H; 
	__nop();
    SCL_L;  
}

/******************************************************************************
����ԭ�ͣ�	static uint8_t I2C_WaitAck(void)	
��    �ܣ�	I2C����Master����SlaveӦ��
�� �� ֵ��	1���յ�ACK��0�յ�NACK  
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
����ԭ�ͣ�	static void I2C_WriteByte(unsigned char SendByte) 	
��    �ܣ�	I2Cдһ���ֽ�����,��д��λ
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
����ԭ�ͣ�	static uint8_t I2C_ReadByte(void)	
��    �ܣ�	I2C��һ���ֽ�����,�ȶ���λ
�� �� ֵ��	���ض�����һ���ֽ�����
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
����ԭ�ͣ�	static uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) 	
��    �ܣ�	дMPU6050�Ĵ���
�� �� ֵ��	0����1�ɹ�
*******************************************************************************/ 
uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) 
{  
	if( !I2C_Start() )
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte(MPU6050Address); //дSlave��ַ�������ó�дģʽ
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//��ACK������
	}
	//led_t();
	I2C_WriteByte(Regs_Addr);    //д�Ĵ�����ַ
	I2C_WaitAck();
	led_t();
	I2C_WriteByte(Regs_Data);    //д�Ĵ�������
	I2C_WaitAck();
	I2C_Stop();         
	return 1;
}
/******************************************************************************
����ԭ�ͣ�	static uint8_t Single_ReadI2C(unsigned char Regs_Addr) 	
��    �ܣ�	��MPU6050���ֽ�
�� �� ֵ��	�Ĵ���ֵ
*******************************************************************************/ 
uint8_t Single_ReadI2C(unsigned char Regs_Addr) 
{
	uint8_t ret;
  
	if( !I2C_Start() )
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte(MPU6050Address); 	//дSlave��ַ�������ó�дģʽ
	
	/*if( !I2C_WaitAck() )
	{
		//led_t();
		I2C_Stop(); 
		return 0;	//��ACK������
	}*/
	I2C_WaitAck();
	I2C_WriteByte(Regs_Addr);    	//д�Ĵ�����ַ
	led_t();
	I2C_WaitAck();
	//led_t();
	I2C_Start();
	I2C_WriteByte(MPU6050Address+1);//дSlave��ַ�������óɶ�ģʽ
	I2C_WaitAck();
	//led_t();
	
	
	
	ret=I2C_ReadByte();				//�Ӵ������ж�������

	I2C_NACK();						//��Ӧ��
	I2C_Stop();                  	//��������IIC���� 
	return ret;	
} 


























