


#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "nrf24l01.h"

short int X_A,  //没有滤波的值
Y_A,
Z_A,

X_G,
Y_G,
Z_G,

X_G_2,
Y_G_2,
Z_G_2


;

short int X_A_0,  //0偏
		Y_A_0,
		Z_A_0,
		X_G_0,
		Y_G_0,
		Z_G_0;

short int X_A_f,  //滤波后可用数据
Y_A_f,
Z_A_f,

X_G_f,
Y_G_f,
Z_G_f


;

float Vx,Vy,Vz; //三轴速度

int ACC_Offset = 1,
	GYRO_Offset = 1;

float pitch, roll, yaw;  //欧拉角
float pitch_buf, roll_buf, yaw_buf;
int dynamo_1,dynamo_2,dynamo_3,dynamo_4;  //电机转动
//************************************************************//
//***********油门********************//
int resist_1 = 0;
int resist_2 = 0;
int resist_3 = 0;
int resist_4 = 0;
//**********方向********************//
int direction_1 = 0;
int direction_2 = 0;
int direction_3 = 0;
int direction_4 = 0;


//int resist = 100;
//int resist = 300;

void motor_task_1(void)
{
	/*
	  throttle1 = rc->THROTTLE - 1050 + gyro_pitch.output + gyro_roll.output - gyro_yaw.output;
		throttle2 = rc->THROTTLE - 1050 + gyro_pitch.output - gyro_roll.output + gyro_yaw.output;
		throttle3 = rc->THROTTLE - 1050 - gyro_pitch.output + gyro_roll.output + gyro_yaw.output;
		throttle4 = rc->THROTTLE - 1050 - gyro_pitch.output - gyro_roll.output - gyro_yaw.output; */
	//IN_Roll_out
	//IN_Pitch_out
	
	
	
	dynamo_1 = resist_1 + IN_Roll_out + IN_Pitch_out - IN_Yaw_out + direction_1;
	dynamo_2 = resist_2 + IN_Roll_out - IN_Pitch_out + IN_Yaw_out + direction_2;
	dynamo_3 = resist_3 - IN_Roll_out + IN_Pitch_out + IN_Yaw_out + direction_3;
	dynamo_4 = resist_4 - IN_Roll_out - IN_Pitch_out - IN_Yaw_out + direction_4;
	
//	dynamo_1 = resist + Roll_out + Pitch_out;
//	dynamo_2 = resist + Roll_out - Pitch_out;
//	dynamo_3 = resist - Roll_out + Pitch_out;
//	dynamo_4 = resist - Roll_out - Pitch_out;
	
	
//	dynamo_1 = resist_1 ;
//	dynamo_2 = resist_2 ;
//	dynamo_3 = resist_3 ;
//	dynamo_4 = resist_4 ;
	
//	if(dynamo_1>=500){dynamo_1 = 500;}
//	else if(dynamo_1 <=0) dynamo_1 = 0;
//	if(dynamo_2>=500){dynamo_2 = 500;}
//	else if(dynamo_2 <=0) dynamo_2 = 0;
//	if(dynamo_3>=500){dynamo_3 = 500;}
//	else if(dynamo_3 <=0) dynamo_3 = 0;
//	if(dynamo_4>=500){dynamo_4 = 500;}
//	else if(dynamo_4 <=0) dynamo_4 = 0;
	
	
	
	if(dynamo_1>=1000){dynamo_1 = 1000;}      //D7,
	else if(dynamo_1 <=0) dynamo_1 = 0;
	
	
	if(dynamo_2>=1000){dynamo_2 = 1000;}      //D10
	else if(dynamo_2 <=0) dynamo_2 = 0;
	
	
	
	if(dynamo_3>=1000){dynamo_3 = 1000;}      //D11
	else if(dynamo_3 <=0) dynamo_3 = 0;
	 
	
	if(dynamo_4>=1000){dynamo_4 = 1000;}      //D14
	else if(dynamo_4 <=0) dynamo_4 = 0;
	
	
	Motor_Out(dynamo_1,dynamo_2,dynamo_3,dynamo_4);     //输出转数
	//Motor_Out(0,0,0,0);
	
}
unsigned char data[6];
short int FLY_START_FLAG;  //电机转动标志
short int START_RESET_FLAG;  //重启系统标志位
short int Adjust;   //0偏调整标志位
//***********************************************************//
int main(void)
{
	
	short int cnt_t1,cnt_t2,cnt_t3,cnt_t4;
	START_RESET:
	var_init();
	delay_init();
	led_init();		 //IO_set: ok
	SPI1_Init();
	//uart_init(38400);
	IIC_Init();		 //IO_set: ok
	Motor_Init();  //IO_set: ok
	IO_bing_Init();
	delay_ms(100);
	
	//while(1);
	//while(InitMPU6050() == 0);

	NRF24L01_Init();
	NRF24L01_Check();
	NRF24L01_RX_Mode();
	

	
	//############MPU6050初始化相关###############//
	while(mpu_dmp_init())
	{
		delay_ms(1);
	}

	
	

	while(InitMPU6050() == 0);
	delay_ms(20);
	led_t(1);
	MPU_adjust();
	delay_ms(10000);
	//MPU_ADJ();
	//MPU6050_SingleRead();
	MPU_filtering(); //滤波取值函数
	FLY_START_FLAG = 0;  //电机转动标志
	led_t(1);
	//##############################################//
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	TIM3_Int_Init(999,7199);//10Khz的计数频率，计数到5000为500ms  ,100ms进行一次积分
	
	

	while(1)
	{
		if(START_RESET_FLAG == 1){
			goto START_RESET;    //重新初始化！！！！！！用蓝牙控制
		}
		delay_us(100);
		if(cnt_t1 == 0)
		{
			task_1();
			cnt_t1 = 0;
		}
		
		if(cnt_t2 >= 2)
		{
			task_2();
			cnt_t2 = 0;	
		}
		else cnt_t2 = cnt_t2 + 1;
		
		if(cnt_t3 >= 4)
		{
			task_3();
			cnt_t3 = 0;
		}
		else cnt_t3 = cnt_t3 + 1;
		
		if(cnt_t4 >= 8)
		{
			task_4();
			cnt_t4 = 0;
		}
		else cnt_t4 = cnt_t4 + 1;
	}
	
	
}















