#include "hardware.h"



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



//**************************************
//I2C��ʼ�ź�
//**************************************
void I2C_Start(void)
{
    SDA_H;                    //����������
    SCL_H;                    //����ʱ����
    delay_us(5);                 //��ʱ
    SDA_L;                    //�����½���
    delay_us(5);                 //��ʱ
    SCL_L;                    //����ʱ����
}
//**************************************
//I2Cֹͣ�ź�
//**************************************
void I2C_Stop(void)
{
    SDA_L;                    //����������
    SCL_H;                    //����ʱ����
    delay_us(5);                 //��ʱ
    SDA_H;                    //����������
    delay_us(5);                 //��ʱ
}
//**************************************
//I2C����Ӧ���ź�
//��ڲ���:ack (0:ACK 1:NAK)
//**************************************
void I2C_SendACK(int ack)
{
	if(ack == 0)
    SDA_L;                  //дӦ���ź�
	else if(ack == 1)
		SDA_H;
    SCL_H;                    //����ʱ����
    delay_us(5);                 //��ʱ
    SCL_L;                    //����ʱ����
    delay_us(5);                 //��ʱ
}
//**************************************
//I2C����Ӧ���ź�
//**************************************
int I2C_RecvACK(void)
{
		int CY;
    SCL_H;                    //����ʱ����
    delay_us(5);                 //��ʱ
    CY = SDA_Read;                   //��Ӧ���ź�
    SCL_L;                    //����ʱ����
    delay_us(5);                 //��ʱ
	
	  while(CY == 1){
			delay_us(5);
		}
		
    return CY;
}
//**************************************
//��I2C���߷���һ���ֽ�����
//**************************************
void I2C_SendByte(int dat)
{
    int i;
    for (i=0; i<8; i++)         //8λ������
    {
				SCL_L;                //����ʱ����
        delay_us(5);             //��ʱ
				if( dat&0x80 ) 
				SDA_H;
				else 
				SDA_L;
        dat <<= 1;              //�Ƴ����ݵ����λ
        //SDA = CY;               //�����ݿ�
        SCL_H;                //����ʱ����
        delay_us(5);             //��ʱ
        
    }
    I2C_RecvACK();
}
//**************************************
//��I2C���߽���һ���ֽ�����
//**************************************
int I2C_RecvByte(void)
{
    int i;
    int dat = 0;
    SDA_H;                    //ʹ���ڲ�����,׼����ȡ����,
    for (i=0; i<8; i++)         //8λ������
    {
        dat <<= 1;
        SCL_H;                //����ʱ����
        delay_us(5);             //��ʱ
			
			if(SDA_Read)
        dat |= 1;             //������  
			else if(!SDA_Read)
				dat |= 0;
			
        SCL_L;                //����ʱ����
        delay_us(5);             //��ʱ
    }
    return dat;
}
//**************************************
//��I2C�豸д��һ���ֽ�����
//**************************************
void Single_WriteI2C(int REG_Address,int REG_data)
{
    I2C_Start();                  //��ʼ�ź�
    I2C_SendByte(MPU6050Address);   //�����豸��ַ+д�ź�
	//led_t();
    I2C_SendByte(REG_Address);    //�ڲ��Ĵ�����ַ��
	//led_t();
    I2C_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
    I2C_Stop();                   //����ֹͣ�ź�
}
//**************************************
//��I2C�豸��ȡһ���ֽ�����
//**************************************
int Single_ReadI2C(int REG_Address)
{
	int REG_data;
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(MPU6050Address);    //�����豸��ַ+д�ź�
	I2C_SendByte(REG_Address);     //���ʹ洢��Ԫ��ַ����0��ʼ	
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(MPU6050Address+1);  //�����豸��ַ+���ź�
	//led_t();
	REG_data=I2C_RecvByte();       //�����Ĵ�������
	I2C_SendACK(1);                //����Ӧ���ź�
	I2C_Stop();                    //ֹͣ�ź�
	return REG_data;
}












