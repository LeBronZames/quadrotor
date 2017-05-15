#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "nrf24l01.h"


void send_data(int send){        //并口传输用
	int i;
			PBout(9) = 1;delay_us(10);
			for(i=4;i<9;i++){
				PBout(i) = (send>>(i-4)) & 0x01;
			}
			//PAout(15) = (send>>(5)) & 0x01;
			
			PBout(9) = 0;delay_us(10);
			PBout(9) = 1;delay_us(10);
	
	
}


void IO_bing_Init(void)      //并口传输初始化
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);	 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;				 //LED0-->PA.8 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
 GPIO_SetBits(GPIOB,GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 );						 //PA.8 输出高


// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4   ;				 //LED0-->PA.8 端口配置
// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
// GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
// GPIO_SetBits(GPIOA,GPIO_Pin_4 );						 //PA.8 输出高
	
	
}




void task_1(void)           //欧拉角、角速度、角速度取值模块
{
	static int i = 0;
	if(mpu_dmp_get_data(&pitch,&roll,&yaw) == 0){
		//MPU6050_SingleRead();
		//MPU_filtering();
		MPU6050_SingleRead();
		X_G_f = X_G;
		Y_G_f = Y_G;
		Z_G_f = Z_G;
//			pitch = pitch - pitch_buf;
//			roll = roll - roll_buf;
//			yaw = yaw - yaw_buf;
	
		//num_for_dmp(pitch,roll,yaw,dynamo_1, dynamo_2, dynamo_3, dynamo_4);
	}
	if((i%10) == 0){     //加速度滤波
		X_A_f = (X_A_f*0.9) + (X_A/10);
		Y_A_f = (Y_A_f*0.9) + (Y_A/10);
		Z_A_f = (Z_A_f*0.9) + (Z_A/10);
		
	}
	if(i>100){     //观察程序进行快慢用，每100次进行led闪烁
		LED0 = ~LED0;
		LED1 = ~LED1;
		i = 0;
	}
	
	i++;
}


void task_2(void)         //角速度环与电机控制
{
	PID_inner();
	motor_task_1();

}


void task_3(void)         //欧拉角度环
{
	PID_outer();
}

void task_4(void)   //蓝牙控制模块与并口传输数据测试模块
{
//	static int i = 0;
	u8 get_data[32];
	send_dmp_test(4); //并口传输函数，1是欧拉角，2是转数,3是角速度,4是速度
//	u8 d1,d2,d3,d4;
//	if(i>10){
//		LED0 = ~LED0;
//		LED1 = ~LED1;
//		i = 0;
//	}
//	i++;
	
//	d1 = dynamo_1/16;
//	d2 = dynamo_2/16;
//	d3 = dynamo_3/16;
//	d4 = dynamo_4/16;
//	send_string(dynamo_1,dynamo_2,dynamo_3,dynamo_4);
//	USART_SendData(USART1,'S');delay_ms(1);
//	USART_SendData(USART1,d1);delay_ms(1);
//	USART_SendData(USART1,d2);delay_ms(1);
//	USART_SendData(USART1,d3);delay_ms(1);
//	USART_SendData(USART1,d4);delay_ms(1);
//	USART_SendData(USART1,'E');delay_ms(1);
	if(NRF24L01_RxPacket(get_data)==0){
		if((get_data[0] == 0x05) & (get_data[1] == 0x00) & (get_data[6] == 0x00)){
			if(FLY_START_FLAG == 0){
				FLY_START_FLAG = 1;
			}
			else if(FLY_START_FLAG == 1){
				FLY_START_FLAG = 0;
			}
			LED0 = ~LED0;
			LED1 = ~LED1;
		}
		else if((get_data[0] == 0x10 )& (get_data[1] == 0x00) & (get_data[6] == 0x00)){
			LED0 = ~LED0;
			LED1 = ~LED1;
			START_RESET_FLAG = 1;
		}
		//****************************//
		else if((get_data[0] == 'D') & (get_data[1] == 'T') & (get_data[6] == 'D')){
			
			resist_1 = U8_to_int8(get_data[2]) * 9;
			resist_2 = U8_to_int8(get_data[2]) * 9;
			resist_3 = U8_to_int8(get_data[2]) * 9;
			resist_4 = U8_to_int8(get_data[2]) * 9;
//			resist_1 = 0;
//			resist_2 = 0;
//			resist_3 = 0;
//			resist_4 = 0;
			direction_1 = U8_to_int8(get_data[4])*3;
			direction_2 = - (U8_to_int8(get_data[5])*3);
			direction_3 = U8_to_int8(get_data[5])*3;
			direction_4 = - (U8_to_int8(get_data[4])*3);
		}
	}	
}

void send_string(int a,int b,int c,int d){         //并口传递数据用
	
	send_data('S');
	send_data('S'>>5);
	send_data((a));
	send_data((a>>5));
	send_data(b);
	send_data(b>>5);
	send_data(c);
	send_data(c>>5);
	send_data(d);
	send_data(d>>5);
	send_data('E');
	send_data('E'>>5);
	
	
}
void var_init(void){
		{   //全局变量复位

		resist_1 = 0;
		resist_2 = 0;
		resist_3 = 0;
		resist_4 = 0;
		direction_1 = 0;
		direction_2 = 0;
		direction_3 = 0;
		direction_4 = 0;
		dynamo_1 = 0;dynamo_2 = 0;dynamo_3 = 0;dynamo_4 = 0;
		pitch = 0; roll = 0; yaw = 0;
		pitch_buf = 0; roll_buf = 0; yaw_buf = 0;
		START_RESET_FLAG = 0;
		FLY_START_FLAG = 0;
		X_A = 0;Y_A = 0;Z_A = 0;
		X_G = 0;Y_G = 0;Z_G = 0;X_G_2 = 0;Y_G_2 = 0;Z_G_2 = 0;
		X_A_0 = 0;Y_A_0 = 0;Z_A_0 = 0;X_G_0 = 0;Y_G_0 = 0;Z_G_0 = 0;
		X_A_f = 0;Y_A_f = 0;Z_A_f = 0;X_G_f = 0;Y_G_f = 0;Z_G_f = 0;
		data[0] = 0;data[1] = 0;data[2] = 0;data[3] = 0;data[4] = 0;data[5] = 0;
		IN_Pitch_out = 0;IN_Roll_out = 0;Pitch_out = 0;Roll_out = 0;
		Adjust = 0;
		IN_Error_roll_I = 0;
		IN_Error_roll_D = 0;
		IN_Error_roll_all_last = 0;
		IN_Error_pitch_I = 0;
		IN_Error_pitch_D = 0;
		IN_Error_pitch_all_last = 0;
		Error_roll_I = 0;
		Error_roll_D = 0;
		Error_roll_all_last = 0;
		Error_pitch_I = 0;
		Error_pitch_D = 0;
		Error_pitch_all_last = 0;
	}
}
void MPU_ADJ(void){

	if(mpu_dmp_get_data(&pitch_buf,&roll_buf,&yaw_buf) == 0){
		
	}
//	pitch = 0; roll = 0; yaw = 0;
}


void send_dmp_test(int test_num){             //并口数据传输模块，用来测试
	int pitch_buff, roll_buff, yaw_buff;
	int Vx_buff, Vy_buff, Vz_buff;
	switch(test_num){
		case(1):{
			pitch_buff = pitch * 10;
			roll_buff = roll * 10;
			yaw_buff = yaw * 10;
			
			send_string(pitch_buff,roll_buff,yaw_buff,0);
		}
		case(2):{
			send_string(dynamo_1,dynamo_2,dynamo_3,dynamo_4);
		}
		case(3):{
			send_string(X_G_f-X_G_2,Y_G_f-Y_G_2,Z_G_f-Z_G_2,0);
		}
		case(4):{
			Vx_buff = Vx * 10;
			Vy_buff = Vy * 10;
			Vz_buff = Vz * 10;
			send_string(Vx_buff,Vy_buff,Vz_buff,0);
		}
	}
	
}


int U8_to_int8(u8 number){      //无符号转有符号函数
	int MMM;
	if (number > 127){
		MMM=(~number + 1);
		MMM = -MMM;
		return MMM;
	}
	else return number;
	
	
}










/*

	while(1)
	{
		delay_ms(1);
		if(cnt_t1 == 0)
		{
			task_1();
			cnt_t1 = 0;
		}
		
		if(cnt_t2 >= 2)
		{
			task_2();
			motor_task_1();
			cnt_t2 = 0;
		}
		else cnt_t2 = cnt_t2 + 1;
		
		if(cnt_t3 >= 4)
		{
			task_3();
			cnt_t3 = 0;
		}
		else cnt_t3 = cnt_t3 + 1;

		
	}
	*/











