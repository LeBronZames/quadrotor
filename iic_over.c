#include "hardware.h"

//��ʼ��IIC
void IIC_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	//RCC->APB2ENR|=1<<4;//��ʹ������IO PORTCʱ�� 
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	IIC_SCL=1;
	IIC_SDA=1;

}

//??SDA????????
void SDA_Input_Mode()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SDA_Pin;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 

  	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

//??SDA????????
void SDA_Output_Mode()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SDA_Pin;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

  	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(4);
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{
	SDA_OUT();//sda�����
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL=1; 
	IIC_SDA=1;//����I2C���߽����ź�
	delay_us(4);							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
	IIC_SDA=1;delay_us(1);	   
	IIC_SCL=1;	 
	while(READ_SDA)
	{
		ucErrTime++;
		/*
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}*/
	}
	IIC_SCL=0;//ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(2);
	IIC_SCL=1;
	delay_us(2);
	IIC_SCL=0;
}
//������ACKӦ��		    
void IIC_NAck(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(2);
	IIC_SCL=1;
	delay_us(2);
	IIC_SCL=0;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL=1;
		delay_us(2); 
		IIC_SCL=0;	
		delay_us(2);
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0; 
        delay_us(2);
		IIC_SCL=1;
        receive<<=1;
        if(READ_SDA)receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK   
    return receive;
}


/******************************************************************************
����ԭ�ͣ�	static uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) 	
��    �ܣ�	дMPU6050�Ĵ���
�� �� ֵ��	0����1�ɹ�
*******************************************************************************/ 
uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) 
{  /*
	if( !IIC_Start() )
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte(MPU6050Address); //дSlave��ַ�������ó�дģʽ
	if( !I2C_WaitAck() )
	{
		I2C_Stop(); 
		return 0;	//��ACK������
	}*/
	IIC_Start();
	IIC_Send_Byte(MPU6050Address); //дSlave��ַ�������ó�дģʽ
	IIC_Wait_Ack();
	//led_t();
	IIC_Send_Byte(Regs_Addr);    //д�Ĵ�����ַ
	IIC_Wait_Ack();
	//led_t();
	IIC_Send_Byte(Regs_Data);    //д�Ĵ�������
	IIC_Wait_Ack();
	IIC_Stop();         
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
  /*
	if( !I2C_Start() )
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte(MPU6050Address); 	//дSlave��ַ�������ó�дģʽ
	*/
	/*if( !I2C_WaitAck() )
	{
		//led_t();
		I2C_Stop(); 
		return 0;	//��ACK������
	}*/
	IIC_Start();
	IIC_Send_Byte(MPU6050Address);
	IIC_Wait_Ack();
	//led_t(1);
	IIC_Send_Byte(Regs_Addr);    	//д�Ĵ�����ַ
	//led_t();
	IIC_Wait_Ack();
	//led_t(1);
	IIC_Start();
	IIC_Send_Byte(MPU6050Address+1);//дSlave��ַ�������óɶ�ģʽ
	IIC_Wait_Ack();
	//led_t();
	
	
	
	ret=IIC_Read_Byte(0);				//�Ӵ������ж�������

	//IIC_NAck();						//��Ӧ��
	IIC_Stop();                  	//��������IIC���� 
	led_t(2);
	return ret;	
} 

uint8_t Single_ReadI2C_2(u8 addr,unsigned char Regs_Addr) 
{
	uint8_t ret;
  /*
	if( !I2C_Start() )
		return 0;	//I2C��ʼ���󣬷���
	I2C_WriteByte(MPU6050Address); 	//дSlave��ַ�������ó�дģʽ
	*/
	/*if( !I2C_WaitAck() )
	{
		//led_t();
		I2C_Stop(); 
		return 0;	//��ACK������
	}*/
	IIC_Start();
	IIC_Send_Byte((addr<<1)|0);
	IIC_Wait_Ack();
	//led_t(1);
	IIC_Send_Byte(Regs_Addr);    	//д�Ĵ�����ַ
	//led_t();
	IIC_Wait_Ack();
	//led_t(1);
	IIC_Start();
	IIC_Send_Byte((addr<<1)|1);//дSlave��ַ�������óɶ�ģʽ
	IIC_Wait_Ack();
	//led_t();
	
	
	
	ret=IIC_Read_Byte(0);				//�Ӵ������ж�������

	//IIC_NAck();						//��Ӧ��
	IIC_Stop();                  	//��������IIC���� 
	led_t(2);
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
    IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte(buf[i]);	//��������
		if(IIC_Wait_Ack())		//�ȴ�ACK
		{
			IIC_Stop();	 
			return 1;		 
		}		
	}    
    IIC_Stop();	 
	return 0;	
} 
//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������
u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
    IIC_Start();
	IIC_Send_Byte((addr<<1)|1);//����������ַ+������	
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	while(len)
	{
		if(len==1)*buf=IIC_Read_Byte(0);//������,����nACK 
		else *buf=IIC_Read_Byte(1);		//������,����ACK  
		len--;
		buf++; 
	}    
    IIC_Stop();	//����һ��ֹͣ���� 
	return 0;	
}


