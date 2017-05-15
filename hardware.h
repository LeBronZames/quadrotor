#include "sys.h"
#include "delay.h"
#include "usart.h"
#include  "stdlib.h"
#include "i2c_t.h"

#define Pi	3.1415927f
#define Radian_to_Angle	   57.2957795f
#define RawData_to_Angle	0.0610351f	//以下参数对应2000度每秒
#define RawData_to_Radian	0.0010653f



#define RGB888_RED      0x00ff0000  
#define RGB888_GREEN    0x0000ff00  
#define RGB888_BLUE     0x000000ff 

//LED ###############################
void led_t(int a);
void var_init(void);

//#define  LED0      PAout(8)
//#define  LED1      PDout(2)

#define LED2_GPIO	GPIOB
#define LED2_Pin	GPIO_Pin_3
#define LED3_GPIO	GPIOC
#define LED3_Pin	GPIO_Pin_13

#define LED0    PBout(3)
#define LED1    PCout(13)


#define LED_m    PBout(12)
//IIC ################################

#define SCL_Pin 	GPIO_Pin_10
#define SDA_Pin 	GPIO_Pin_11

#define	SCL_H   	GPIOB->BSRR = SCL_Pin	 //SCL高电平
#define	SCL_L   	GPIOB->BRR  = SCL_Pin	 //SCL低电平
#define	SDA_H   	GPIOB->BSRR = SDA_Pin	 //SDA高电平
#define	SDA_L   	GPIOB->BRR  = SDA_Pin	 //SDA低电平
#define	SDA_Read	GPIOB->IDR  & SDA_Pin	 //SDA读数据

#define Debug1_Pin	GPIO_Pin_5	//用于测量程序运行速率
#define	Debug1_H   	GPIOB->BSRR = Debug1_Pin //高电平
#define	Debug1_L   	GPIOB->BRR  = Debug1_Pin //低电平

#define Debug2_Pin	GPIO_Pin_9		
#define	Debug2_H   	GPIOB->BSRR = Debug2_Pin 
#define	Debug2_L   	GPIOB->BRR  = Debug2_Pin 

#define Debug3_Pin	GPIO_Pin_8		
#define	Debug3_H   	GPIOB->BSRR = Debug3_Pin 
#define	Debug3_L   	GPIOB->BRR  = Debug3_Pin 

//#define SCL_Pin 	GPIO_Pin_5
//#define SDA_Pin 	GPIO_Pin_6

//IO方向设置
#define SDA_IN  SDA_Input_Mode
#define SDA_OUT SDA_Output_Mode

//#define SDA_IN()  {GPIOB->CRL&=0XF0FFFFFF;GPIOB->CRL|=(u32)8<<6;} 
//#define SDA_OUT() {GPIOB->CRL&=0XF0FFFFFF;GPIOB->CRL|=(u32)3<<6;}

//IO操作函数	 
#define IIC_SCL    PBout(10) //SCL
#define IIC_SDA    PBout(11) //SDA	 
#define READ_SDA   PBin(11)  //输入SDA 

//#define IIC_SCL    PBout(11) //SCL
//#define IIC_SDA    PBout(10) //SDA	 
//#define READ_SDA   PBin(10)  //输入SDA 

/******************************************************************************
							定义MPU6050寄存器地址
*******************************************************************************/ 
#define	SMPLRT_DIV		0x19	
#define	CONFIG2			0x1A	
#define	GYRO_CONFIG		0x1B	
#define	ACCEL_CONFIG	0x1C	
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//电源管理，典型值：0x00(正常启用)
#define	WHO_AM_I		0x75	//IIC地址寄存器的地址(默认数值0x68，只读!!!)

//定义器件在IIC总线中的从地址
//I2C器件地址是7bit而不是8bit，而模拟I2C用8bit传送地址，因此是0xD0（器件AD0引脚接地）
#define	MPU6050Address	0xD0
void IO_bing_Init(void);
void send_data(int send);
void send_string(int a,int b,int c,int d);

void test_test(void);
uint8_t Single_ReadI2C_2(u8 addr,unsigned char Regs_Addr) ;
extern  unsigned char data[6];
void test_test_3(void);
void test_test_4(void);
uint8_t Single_ReadI2C_2(u8 addr,unsigned char Regs_Addr) ;
void SDA_Output_Mode(void);
void SDA_Input_Mode(void);

//function for LED########################

void led_init(void);
	void test_test_2(void);
	uint8_t Single_WriteI2C_2(u8 addr,unsigned char Regs_Addr,unsigned char Regs_Data) ;
	void led_init_min(void);

//function for IIC########################
/*
 void I2C2_Int(void);
 void I2C_delay(int delay);
 uint8_t I2C_Start(void)	;
 void I2C_Stop(void);
 void I2C_ACK(void);
 void I2C_NACK(void);
 uint8_t I2C_WaitAck(void);
 void I2C_WriteByte(unsigned char SendByte) ;
 uint8_t I2C_ReadByte(void);
 uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) ;
 uint8_t Single_ReadI2C(unsigned char Regs_Addr) ;
 */
 
//IIC test######################################
/*
void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendACK(int ack);
int I2C_RecvACK(void);
void I2C_SendByte(int dat);
int I2C_RecvByte(void);
void Single_WriteI2C(int REG_Address,int REG_data);
int Single_ReadI2C(int REG_Address);
void I2C2_Int(void);*/
//**********************************************

//############iic_over##########################
//void IIC_Init(void);
//void IIC_Start(void);
//void IIC_Stop(void);
//u8 IIC_Wait_Ack(void);
//void IIC_Ack(void);
//void IIC_NAck(void);
//void IIC_Send_Byte(u8 txd);
//u8 IIC_Read_Byte(unsigned char ack);
//uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data);
//uint8_t Single_ReadI2C(unsigned char Regs_Addr) ;


//**********************************************

//########################################

//***********油门********************//
extern int resist_1 ;
extern int resist_2 ;
extern int resist_3 ;
extern int resist_4;
//**********方向********************//
extern int direction_1 ;
extern int direction_2 ;
extern int direction_3;
extern int direction_4;

int U8_to_int8(u8 number);

extern short int FLY_START_FLAG;
extern short int START_RESET_FLAG;
extern float pitch, roll, yaw;
extern float pitch_buf, roll_buf, yaw_buf;
extern float Vx,Vy,Vz; //三轴速度
extern short int Adjust;

extern float Error_roll_all,
	Error_roll_max,
	Error_roll_I_max,
	Error_roll_I,
	Error_roll_D,
	Error_roll_all_last,
	K_roll_P,
	K_roll_I,
	K_roll_D,
	Roll_out
;

extern float Error_pitch_all,
	Error_pitch_max,
	Error_pitch_I_max,
	Error_pitch_I,
	Error_pitch_D,
	Error_pitch_all_last,
	K_pitch_P,
	K_pitch_I,
	K_pitch_D,
	Pitch_out
;

extern float Error_yaw_all,
	Error_yaw_max,
	Error_yaw_I_max,
	Error_yaw_I,
	Error_yaw_D,
	Error_yaw_all_last,
	K_yaw_P,
	K_yaw_I,
	K_yaw_D,
	Yaw_out
;

extern float IN_Error_roll_all,
	IN_Error_roll_max,
	IN_Error_roll_I_max,
	IN_Error_roll_I,
	IN_Error_roll_D,
	IN_Error_roll_all_last,
	IN_K_roll_P,
	IN_K_roll_I,
	IN_K_roll_D,
	IN_Roll_out
;

extern float IN_Error_pitch_all,
	IN_Error_pitch_max,
	IN_Error_pitch_I_max,
	IN_Error_pitch_I,
	IN_Error_pitch_D,
	IN_Error_pitch_all_last,
	IN_K_pitch_P,
	IN_K_pitch_I,
	IN_K_pitch_D,
	IN_Pitch_out
;

extern float IN_Error_yaw_all,
	IN_Error_yaw_max ,
	IN_Error_yaw_I_max,
	IN_Error_yaw_I,
	IN_Error_yaw_D,
	IN_Error_yaw_all_last,
	IN_K_yaw_P ,
	IN_K_yaw_I ,
	IN_K_yaw_D,
	IN_Yaw_out
;

u8 InitMPU6050(void);
void MPU6050_SingleRead(void);
void MPU_filtering(void);
uint8_t MPU6050_SequenceRead(void);
void MPU_adjust(void);
void MPU_ADJ(void);
void motor_task_1(void);
void send_dmp_test(int test_num);

void PID_outer(void);
void PID_inner(void);

void task_1(void);
void task_2(void);
void task_3(void);
void task_4(void);
//***********TFTLCD****************************//

extern int dynamo_1,dynamo_2,dynamo_3,dynamo_4;

extern short int X_A_f,
Y_A_f,
Z_A_f,

X_G_f,
Y_G_f,
Z_G_f


;

extern short int X_A,
Y_A,
Z_A,

X_G,
Y_G,
Z_G,

X_G_2,
Y_G_2,
Z_G_2;

extern short int X_A_0,
		Y_A_0,
		Z_A_0,
		X_G_0,
		Y_G_0,
		Z_G_0;

#define CS_SET GPIO_SetBits(GPIOC,GPIO_Pin_9)
#define CS_CLR GPIO_ResetBits(GPIOC,GPIO_Pin_9)

#define RS_SET GPIO_SetBits(GPIOC,GPIO_Pin_8)
#define RS_CLR GPIO_ResetBits(GPIOC,GPIO_Pin_8)

#define WR_SET GPIO_SetBits(GPIOC,GPIO_Pin_7)
#define WR_CLR GPIO_ResetBits(GPIOC,GPIO_Pin_7)

#define RD_SET GPIO_SetBits(GPIOC,GPIO_Pin_6)
#define RD_CLR GPIO_ResetBits(GPIOC,GPIO_Pin_6)


#define C1 0x551A00
#define C2 0xdeaa7a
#define C3 0xc48c52
#define C4 0xb57f4e
#define C5 0xffffff
#define C6 0xff6464
#define C7 0xe52b2b
#define C8 0xefefef
#define C9 0xa06938
#define C10 0xdea876

#define c1 0x551A00
#define c2 0xdeaa7a
#define c3 0xc48c52
#define c4 0xb57f4e
#define c5 0xffffff
#define c6 0xff6464
#define c7 0xe52b2b
#define c8 0xefefef
#define c9 0xa06938
#define c10 0xdea876

//#define SDA_IN()  {GPIOC->CRH&=0XFFFF0FFF;GPIOC->CRH|=8<<12;}
//#define SDA_OUT() {GPIOC->CRH&=0XFFFF0FFF;GPIOC->CRH|=3<<12;}



int TFT_init(void);
void TFT_test(void);
void TFT_io_init(void);
void TFT_WRITE(u8 data_reg, int flag);
void TFT_WRITE_16(u16 data, int flag);
int draw_point(u16 a, u16 b, u16 color);
int draw_point_one(u16 a, u16 b, u16 color);
void TFT_clear(u16 color);
void TFT_clear_num_1(void);
void TFT_clear_num_2(void);
void TFT_background(u16 color);
char number_tran_to_display_ge(int cnt);
char number_tran_to_display_shi(int cnt);
char number_tran_to_display_bai(int cnt);
char number_tran_to_display_qian(int cnt);
char number_tran_to_display_wan(int cnt);

char number_tran_to_display_one(int cnt);
char number_tran_to_display_two(int cnt);
char number_tran_to_display_three(int cnt);
char number_tran_to_display_four(int cnt);
char number_tran_to_display_five(int cnt);
char number_tran_to_display_six(int cnt);
char number_tran_to_display_seven(int cnt);
char number_tran_to_display_eight(int cnt);

u16 RGB888ToRGB565(unsigned int n888Color ,int flag);
void draw_word(int x, int y, char word, u16 color);
void draw_number(int x, int y, char number, u16 color);
void draw_across(int x, int y, u16 color);
void draw_vertical(int x, int y, u16 color);
void draw_vertical_short(int x, int y, u16 color);
void num_for_test(float x, float y, float z, int a, int b, int c);
void num_one_for_test(int a);
void num_16_for_test(int x, int y, int z, int a, int b, int c);
void num_for_dmp(float x, float y, float z,short int a,short int b,short int c,short int d);
//*************tran back**********************//
 void I2C2_Int(void);
 void I2C_delay(int delay);
 uint8_t I2C_Start(void)	;
 void I2C_Stop(void);
 void I2C_ACK(void);
 void I2C_NACK(void);
 uint8_t I2C_WaitAck(void);
 void I2C_WriteByte(unsigned char SendByte) ;
 uint8_t I2C_ReadByte(void);
 u8 MPU_Read_Len_1(u8 addr,u8 reg,u8 len,u8 *buf);
 //uint8_t Single_WriteI2C(unsigned char Regs_Addr,unsigned char Regs_Data) ;
 //uint8_t Single_ReadI2C(unsigned char Regs_Addr) ;
//********************  motor  ************************//
static void Tim2_init(void);
void Motor_Init(void);
void Motor_Out(int16_t duty1,int16_t duty2,int16_t duty3,int16_t duty4);
//*******************timer *******************************//
void TIM3_Int_Init(u16 arr,u16 psc);
