#include "hardware.h"


//static 

/******************************************************************************
����ԭ��:	void I2C2_Int(void)
��������:	��ʼ��I2C����
*******************************************************************************/ 
void IIC_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE); //������B��ʱ��
/*
	GPIO_InitStructure.GPIO_Pin = Debug1_Pin | Debug2_Pin | Debug3_Pin; //���ڲ���������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(GPIOB, &GPIO_InitStructure);		*/

	GPIO_InitStructure.GPIO_Pin = SCL_Pin; //SCL
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //��©���
	GPIO_Init(GPIOB, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = SDA_Pin; //SDA
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
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
	SDA_H;
	SCL_H;
	
	if(!SDA_Read)
		return 0;	//SDA��Ϊ�͵�ƽ������æ,�˳�
	SDA_L;
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
	SDA_L;
	SCL_H;
	SDA_H;
}

/******************************************************************************
����ԭ�ͣ�	static void I2C_ACK(void)	
��    �ܣ�	I2C����Master����ACK�ź�
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
����ԭ�ͣ�	static void I2C_NACK(void)	
��    �ܣ�	I2C����Master����NACK�ź�
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
����ԭ�ͣ�	static uint8_t I2C_WaitAck(void)	
��    �ܣ�	I2C����Master����SlaveӦ��
�� �� ֵ��	1���յ�ACK��0�յ�NACK  
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
	}   
	SCL_L;  
}

/******************************************************************************
����ԭ�ͣ�	static uint8_t I2C_ReadByte(void)	
��    �ܣ�	I2C��һ���ֽ�����,�ȶ���λ
�� �� ֵ��	���ض�����һ���ֽ�����
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
	I2C_WriteByte(Regs_Addr);    //д�Ĵ�����ַ
	I2C_WaitAck();
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
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//��ACK������
	}
	
	I2C_WriteByte(Regs_Addr);    	//д�Ĵ�����ַ
	I2C_WaitAck();
	I2C_Start();
	I2C_WriteByte(MPU6050Address+1);//дSlave��ַ�������óɶ�ģʽ
	I2C_WaitAck();
	
	ret=I2C_ReadByte();				//�Ӵ������ж�������

	I2C_NACK();						//��Ӧ��
	I2C_Stop();                  	//��������IIC���� 
	return ret;	
} 




//IIC����д
//addr:������ַ 
//reg:�Ĵ�����ַ
//len:д�볤��
//buf:������
//����ֵ:0,����
//    ����,�������
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
	u8 i; 
    I2C_Start(); 
	//led_t(2);
	I2C_WriteByte((addr<<1)|0);//����������ַ+д����	
	if(!I2C_WaitAck())	//�ȴ�Ӧ��
	{
		I2C_Stop();		 
		return 1;		
	}
	//led_t(2);
    I2C_WriteByte(reg);	//д�Ĵ�����ַ
    I2C_WaitAck();		//�ȴ�Ӧ��
	for(i=0;i<len;i++)
	{
		I2C_WriteByte(buf[i]);	//��������
		if(!I2C_WaitAck())		//�ȴ�ACK
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
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte((addr<<1)|0); //дSlave��ַ�������ó�дģʽ
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//��ACK������
	}
	I2C_WriteByte(Regs_Addr);    //д�Ĵ�����ַ
	I2C_WaitAck();
	I2C_WriteByte(Regs_Data);    //д�Ĵ�������
	I2C_WaitAck();
	I2C_Stop();         
	return 1;
}
//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������

uint8_t MPU6050_SequenceRead(void)
{
	uint8_t index=14;
	u8 MPU6050_Buffer[14];
	if( !I2C_Start() )
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte(MPU6050Address); 	//дSlave��ַ�������ó�дģʽ
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//��ACK������
	}
	I2C_WriteByte(ACCEL_XOUT_H);    //д�Ĵ�����ַ
	I2C_WaitAck();
	
	I2C_Start();
	I2C_WriteByte(MPU6050Address+1);//дSlave��ַ�������óɶ�ģʽ
	I2C_WaitAck();

	while(--index)	//����13λ�Ĵ���
	{
		MPU6050_Buffer[13 - index] = I2C_ReadByte();
		I2C_ACK();
	}

	MPU6050_Buffer[13] = I2C_ReadByte();	//����14�Ĵ���
	I2C_NACK();	
	I2C_Stop();	
	
	return 1;
}
//uint8_t MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
//{
//	uint8_t index=len;
//	
//	if( !I2C_Start() )
//		return 0;	//I2C��ʼ���󣬷���
//	I2C_WriteByte((addr<<1)|0); 	//дSlave��ַ�������ó�дģʽ
//	if( !I2C_WaitAck() )
//	{
//		I2C_Stop(); 
//		return 1;	//��ACK������
//	}
//	I2C_WriteByte(reg);    //д�Ĵ�����ַ
//	I2C_WaitAck();
//	
//	I2C_Start();
//	I2C_WriteByte((addr<<1)|1);//дSlave��ַ�������óɶ�ģʽ
//	I2C_WaitAck();

//	while(--index)	//����13λ�Ĵ���
//	{
//		buf[len - index - 1] = I2C_ReadByte();
//		I2C_ACK();
//		delay_ms(2);
//	}

//	buf[len-1] = I2C_ReadByte();	//����14�Ĵ���
//	I2C_NACK();	
//	I2C_Stop();	
//	
//	return 0;
//}


u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	I2C_Start(); 
	I2C_WriteByte((addr<<1)|0);//����������ַ+д����	
	if(!I2C_WaitAck())	//�ȴ�Ӧ��
	{
		I2C_Stop();		 
		return 1;		
	}
    I2C_WriteByte(reg);	//д�Ĵ�����ַ
    I2C_WaitAck();		//�ȴ�Ӧ��
    I2C_Start();
	I2C_WriteByte((addr<<1)|1);//����������ַ+������	
    I2C_WaitAck();		//�ȴ�Ӧ�� 
	while(len)
	{
		if(len==1){//*buf=IIC_Read_Byte(0);//������,����nACK 
		
			*buf=I2C_ReadByte();				//�Ӵ������ж�������
			I2C_NACK();						//��Ӧ��
		}
		
		else {*buf=I2C_ReadByte();		//������,����ACK  
			I2C_ACK();
		
			
		}
		
		
		len--;
		buf++; 
	}    
    I2C_Stop();	//����һ��ֹͣ���� 
	return 0;	
}



//u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)      //�����ڵ��Լ�һ���ⲿ�����reg�ԼӲ�һ��
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
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte((addr<<1)|0); 	//дSlave��ַ�������ó�дģʽ
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//��ACK������
	}
	
	I2C_WriteByte(Regs_Addr);    	//д�Ĵ�����ַ
	I2C_WaitAck();
	I2C_Start();
	I2C_WriteByte((addr<<1)|1);//дSlave��ַ�������óɶ�ģʽ
	I2C_WaitAck();
	
	ret=I2C_ReadByte();				//�Ӵ������ж�������

	I2C_NACK();						//��Ӧ��
	I2C_Stop();                  	//��������IIC���� 
	return ret;	
} 

//MPU_Read_Len(0x68, 0x06, 6, data);


//	int i;
//	for(i=0;i<len;i++){
//		*buf=Single_ReadI2C(((addr<<1)+i)|0) ;buf++;
//		
//	}











