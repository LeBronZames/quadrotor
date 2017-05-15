#include "hardware.h"
#include "mpu6050.h"


uint8_t	MPU6050_Buffer[14];	//I2C读取数据缓存



u8 InitMPU6050(void)
{
	u8 aaa[3];
	//LED0 = 1;  
	//LED1 = 0;
	
	//if(Single_ReadI2C(WHO_AM_I)!= 0x68)//检查MPU6050是否正常
	//{//led_t(1);
	/*
		delay_ms(500);
		TFT_clear(0xffff);
		draw_number(10, 225, number_tran_to_display_wan(Single_ReadI2C(WHO_AM_I)), 0x5656);
		draw_number(10+20, 225, number_tran_to_display_qian(Single_ReadI2C(WHO_AM_I)), 0x5656);  //屏幕左上
		draw_number(10+20+20, 225, number_tran_to_display_bai(Single_ReadI2C(WHO_AM_I)), 0x5656);
		draw_number(10+20+20+20, 225, number_tran_to_display_shi(Single_ReadI2C(WHO_AM_I)), 0x5656);
		draw_number(10+20+20+20+20, 225, number_tran_to_display_ge(Single_ReadI2C(WHO_AM_I)), 0x5656);*/
		//return 0;
	//}
	MPU_Read_Len(MPU6050Address>>1,WHO_AM_I-2,3,aaa);
	
	
	if(aaa[2] !=0x68){
		return 0;
	}
		
	
	//led_t(0);

	//led_t(1);
	//PrintString("\r\n MPU6050  正常！");
	//Single_WriteI2C(PWR_MGMT_1, 0x00);	//电源管理，典型值：0x00，正常模式
	//delay_ms(2);
	//Single_WriteI2C(SMPLRT_DIV, 0x00);	//陀螺仪采样率，典型值：0x00，不分频（8KHZ）
	//delay_ms(2);            
	//Single_WriteI2C(CONFIG2, 0x00);   	//低通滤波频率，典型值：0x00，不启用MPU6050自带滤波
	//delay_ms(2);
	Single_WriteI2C(GYRO_CONFIG, 0x18);	//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
	delay_ms(2);
	Single_WriteI2C(ACCEL_CONFIG, 0x1F);//加速计自检、测量范围及高通滤波频率，典型值：0x1F(不自检，16G)
	//delay_ms(2);
	
	//PrintString("\r\n MPU6050  初始化完成！");
	//LED0 = 0;
	//LED1 = 1;

	return 1;
	
}


/******************************************************************************
函数原型：	uint8_t MPU6050_SequenceRead(void) 	
功    能：	连续读MPU6050数据寄存器
返 回 值：	0出错；1成功
*******************************************************************************/ 
/*
uint8_t MPU6050_SequenceRead(void)
{
	uint8_t index=14;
	
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

//#*****************************************************************************
函数原型：	void MPU6050_SingleRead(void)
功    能：	分次读MPU6050数据寄存器
*******************************************************************************/ 

void MPU6050_SingleRead(void)
{

//	MPU_Read_Len_1(MPU6050Address,ACCEL_XOUT_H,12,MPU6050_Buffer);
//	X_A = (MPU6050_Buffer[0]<<8)+MPU6050_Buffer[1] - X_A_0;
//	Y_A = (MPU6050_Buffer[2]<<8)+MPU6050_Buffer[3] - Y_A_0;
//	Z_A = (MPU6050_Buffer[4]<<8)+MPU6050_Buffer[5] - Z_A_0;
//	X_G = (MPU6050_Buffer[6]<<8)+MPU6050_Buffer[7] - X_G_0;
//	Y_G = (MPU6050_Buffer[8]<<8)+MPU6050_Buffer[9] - Y_G_0;
//	Z_G = (MPU6050_Buffer[10]<<8)+MPU6050_Buffer[11] - Z_G_0;
	
		MPU6050_Buffer[0] = Single_ReadI2C(ACCEL_XOUT_H);
		MPU6050_Buffer[1] = Single_ReadI2C(ACCEL_XOUT_L);		
		MPU6050_Buffer[2] = Single_ReadI2C(ACCEL_YOUT_H);	
		MPU6050_Buffer[3] = Single_ReadI2C(ACCEL_YOUT_L);
		MPU6050_Buffer[4] = Single_ReadI2C(ACCEL_ZOUT_H);
		MPU6050_Buffer[5] = Single_ReadI2C(ACCEL_ZOUT_L);
		

	
	X_A = (MPU6050_Buffer[0]<<8)+MPU6050_Buffer[1] - X_A_0;
	Y_A = (MPU6050_Buffer[2]<<8)+MPU6050_Buffer[3] - Y_A_0;
	Z_A = (MPU6050_Buffer[4]<<8)+MPU6050_Buffer[5] - Z_A_0;
		MPU6050_Buffer[8]  = Single_ReadI2C(GYRO_XOUT_H);
		MPU6050_Buffer[9]  = Single_ReadI2C(GYRO_XOUT_L);
		MPU6050_Buffer[10] = Single_ReadI2C(GYRO_YOUT_H);
		MPU6050_Buffer[11] = Single_ReadI2C(GYRO_YOUT_L);
		MPU6050_Buffer[12] = Single_ReadI2C(GYRO_ZOUT_H);
		MPU6050_Buffer[13] = Single_ReadI2C(GYRO_ZOUT_L);
		X_G = (MPU6050_Buffer[8]<<8)+MPU6050_Buffer[9] - X_G_0;
		Y_G = (MPU6050_Buffer[10]<<8)+MPU6050_Buffer[11] - Y_G_0;
		Z_G = (MPU6050_Buffer[12]<<8)+MPU6050_Buffer[13] - Z_G_0;
	

	
}




void MPU_filtering(void)
{
	static int Adjust = 0;
	short int i;
	short int j[6] = {10,10,10,10,10,10};
	short int X_G_f_buff = 0,Y_G_f_buff = 0,Z_G_f_buff = 0;
	
	short int X_A_filtering[10],
	Y_A_filtering[10],
	Z_A_filtering[10],

	X_G_filtering[10],
	Y_G_filtering[10],
	Z_G_filtering[10];
	
	for(i=0;i<10;i++){
		MPU6050_SingleRead();
		X_A_filtering[i] = X_A;
		Y_A_filtering[i] = Y_A;
		Z_A_filtering[i] = Z_A;

		X_G_filtering[i] = X_G;
		Y_G_filtering[i] = Y_G;
		Z_G_filtering[i] = Z_G;
	}
	
	for(i=0;i<10;i++){
		if(X_A_filtering[i] > 0x1d6){X_A_filtering[i] = 0;j[0] -=1;}
		else if(X_A_filtering[i] < -0x1d6){X_A_filtering[i] = 0;j[0] -=1;}
		if(Y_A_filtering[i] > 0x1d6){Y_A_filtering[i] = 0;j[1] -=1;}
		else if(Y_A_filtering[i] < -0x1d6){Y_A_filtering[i] = 0;j[0] -=1;}
		if(Z_A_filtering[i] > 0x1d6){Z_A_filtering[i] = 0;j[2] -=1;}
		else if(Z_A_filtering[i] < -0x1d6){Z_A_filtering[i] = 0;j[0] -=1;}
		if(X_G_filtering[i] > 0x1d6){X_G_filtering[i] = 0;j[3] -=1;}
		else if(X_G_filtering[i] < -0x1d6){X_G_filtering[i] = 0;j[0] -=1;}
		if(Y_G_filtering[i] > 0x1d6){Y_G_filtering[i] = 0;j[4] -=1;}
		else if(Y_G_filtering[i] < -0x1d6){Y_G_filtering[i] = 0;j[0] -=1;}
		if(Z_G_filtering[i] > 0x1d6){Z_G_filtering[i] = 0;j[5] -=1;}
		else if(Z_G_filtering[i] < -0x1d6){Z_G_filtering[i] = 0;j[0] -=1;}
	}
	if(j[3]!=0 && j[4]!=0 && j[5]!=0)
	for(i=0;i<10;i++){
		/*
		X_A_f += (X_A_filtering[i] / j[0]);
		Y_A_f += (X_A_filtering[i] / j[1]);
		Z_A_f += (X_A_filtering[i] / j[2]);
		*/
		X_G_f_buff += (X_G_filtering[i] / j[3]);
		Y_G_f_buff += (Y_G_filtering[i] / j[4]);
		Z_G_f_buff += (Z_G_filtering[i] / j[5]);
	}
	  X_G_f = X_G_f_buff;
		Y_G_f = Y_G_f_buff;
		Z_G_f = Z_G_f_buff;
	
	if(Adjust == 0)
	{
	
		X_G_2 = X_G_f;
		Y_G_2 = Y_G_f;
		Z_G_2 = Z_G_f;
		Adjust = 1;
	}
//	MPU6050_SingleRead();
//	X_G_f = X_G;
//	Y_G_f = Y_G;
//	Z_G_f = Z_G;
//	X_A_f = X_A;
//	Y_A_f = Y_A;
//	Z_A_f = Z_A;
}


void MPU_adjust(void)  //MPU 是带符号位的，最高位为负号位

{
	u8 MPU6050_adj[14];
	//int X_A_0_buff = 0,
		//Y_A_0_buff = 0,
		//Z_A_0_buff = 0,
		//X_G_0_buff = 0,
		//Y_G_0_buff = 0,
		//Z_G_0_buff = 0;
	int i;


	
	for(i=0; i<=9; i++){
		MPU6050_adj[0] = Single_ReadI2C(ACCEL_XOUT_H);
		MPU6050_adj[1] = Single_ReadI2C(ACCEL_XOUT_L);
		MPU6050_adj[2] = Single_ReadI2C(ACCEL_YOUT_H);	
		MPU6050_adj[3] = Single_ReadI2C(ACCEL_YOUT_L);
		MPU6050_adj[4] = Single_ReadI2C(ACCEL_ZOUT_H);
		MPU6050_adj[5] = Single_ReadI2C(ACCEL_ZOUT_L);
		
		MPU6050_adj[6]  = Single_ReadI2C(GYRO_XOUT_H);
		MPU6050_adj[7]  = Single_ReadI2C(GYRO_XOUT_L);
		MPU6050_adj[8] = Single_ReadI2C(GYRO_YOUT_H);
		MPU6050_adj[9] = Single_ReadI2C(GYRO_YOUT_L);
		MPU6050_adj[10] = Single_ReadI2C(GYRO_ZOUT_H);
		MPU6050_adj[11] = Single_ReadI2C(GYRO_ZOUT_L);


		X_A_0 = X_A_0 + ((MPU6050_adj[0]<<8)+MPU6050_adj[1])/10;
		Y_A_0 = Y_A_0 + ((MPU6050_adj[2]<<8)+MPU6050_adj[3])/10;
		Z_A_0 = Z_A_0 + ((MPU6050_adj[4]<<8)+MPU6050_adj[5] - 2048)/10;
		X_G_0 = X_G_0 + ((MPU6050_adj[8]<<8)+MPU6050_adj[9])/10;
		Y_G_0 = Y_G_0 + ((MPU6050_adj[10]<<8)+MPU6050_adj[11])/10;
		Z_G_0 = Z_G_0 + ((MPU6050_adj[12]<<8)+MPU6050_adj[13])/10;
		delay_ms(10);
		
				/*
		if(MPU6050_adj[0] <0x80){
		X_A_0_buff = X_A_0_buff + ((MPU6050_adj[0]<<8)+MPU6050_adj[1]);}
		else X_A_0_buff = X_A_0_buff - (((MPU6050_adj[0]<<8)+MPU6050_adj[1])&0x7fff);
			
		if(MPU6050_adj[2] <0x80){
		Y_A_0_buff = Y_A_0_buff + ((MPU6050_adj[2]<<8)+MPU6050_adj[3]);}
		else Y_A_0_buff = Y_A_0_buff - (((MPU6050_adj[2]<<8)+MPU6050_adj[1] )&0x7fff);
		
		if(MPU6050_adj[4] <0x80){
		Z_A_0_buff = Z_A_0_buff + (((MPU6050_adj[4]<<8)+MPU6050_adj[5])&0x7fff) -2048;}
		else Z_A_0_buff = Z_A_0_buff - (((MPU6050_adj[4]<<8)+MPU6050_adj[5])&0x7fff) -2048;
		
		if(MPU6050_adj[6] <0x80){
		X_G_0_buff = X_G_0_buff + ((MPU6050_adj[6]<<8)+MPU6050_adj[7]);}
		else X_G_0_buff = X_G_0_buff - (((MPU6050_adj[6]<<8)+MPU6050_adj[7])&0x7fff);
		
		if(MPU6050_adj[8] <0x80){
		Y_G_0_buff = Y_G_0_buff + ((MPU6050_adj[8]<<8)+MPU6050_adj[9]);}
		else Y_G_0_buff = Y_G_0_buff - (((MPU6050_adj[8]<<8)+MPU6050_adj[9])&0x7fff);
		
		if(MPU6050_adj[10] <0x80){
		Z_G_0_buff = Z_G_0_buff + ((MPU6050_adj[10]<<8)+MPU6050_adj[11]);}
		else Z_G_0_buff = Z_G_0_buff - (((MPU6050_adj[10]<<8)+MPU6050_adj[11])&0x7fff);
		*/
		//delay_ms(1);
	}
		
	
	
	//X_A_0 = (MPU6050_adj[0]<<8)+MPU6050_adj[1];
	//Y_A_0 = (MPU6050_adj[2]<<8)+MPU6050_adj[3];
	//Z_A_0 = (MPU6050_adj[4]<<8)+MPU6050_adj[5];
	//X_G_0 = (MPU6050_adj[8]<<8)+MPU6050_adj[9];
	//Y_G_0 = (MPU6050_adj[10]<<8)+MPU6050_adj[11];
	//Z_G_0 = (MPU6050_adj[12]<<8)+MPU6050_adj[13];
	
	
	//X_A_0 = X_A_0_buff/10;
	//Y_A_0 = Y_A_0_buff/10;
	//Z_A_0 = Z_A_0_buff/10;
	//X_G_0 = X_G_0_buff /10;
	//Y_G_0 = Y_G_0_buff /10;
	//Z_G_0 = Z_G_0_buff /10;
	
}



















