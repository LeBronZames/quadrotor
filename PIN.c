#include "hardware.h"




/*
	roll.kp  = 4.9f;
	roll.ki  = 0.02f;
	roll.kd  = 8.0f;
	pitch.kp = 4.9f;
	pitch.ki = 0.02f;
	pitch.kd = 8.0f;
	gyro_roll.kp  =1.4f;
	gyro_roll.ki  = 0.0f;
	gyro_roll.kd  =2.0f;
	gyro_pitch.kp =1.4f;
	gyro_pitch.ki = 0.0f;
	gyro_pitch.kd =2.0f;
	gyro_yaw.kp   = 8.0f;
	gyro_yaw.ki   = 0.1f;
	gyro_yaw.kd   = 0.1f;

*/




float Error_roll_all,
	Error_roll_max = 10.0f,
	Error_roll_I_max = 1000.0f,
	Error_roll_I,
	Error_roll_D,
	Error_roll_all_last,
	K_roll_P = 1.0f,
	K_roll_I = 0.000f,
	K_roll_D = 1.0f,
	Roll_out
;

float Error_pitch_all,
	Error_pitch_max = 10.0f,
	Error_pitch_I_max = 1000.0f,
	Error_pitch_I,
	Error_pitch_D,
	Error_pitch_all_last,
	K_pitch_P = 1.0f,
	K_pitch_I = 0.000f,
	K_pitch_D =1.0f,
	Pitch_out
;

float Error_yaw_all,
	Error_yaw_max = 10.0f,
	Error_yaw_I_max = 1000.0f,
	Error_yaw_I,
	Error_yaw_D,
	Error_yaw_all_last,
	K_yaw_P = 1.0f,
	K_yaw_I = 0.000f,
	K_yaw_D =1.0f,
	Yaw_out
;

void PID_outer(void)
{
	//***************roll**********************//
	//*******************P *****************//
	Error_roll_all = 0 - roll;   
	
	//*******************I ****************//
	if(Error_roll_all > Error_roll_max){
		Error_roll_I += Error_roll_max;
	}
	else Error_roll_I = Error_roll_I + Error_roll_all;
	
	//*******************D ***************//
	Error_roll_D = Error_roll_all - Error_roll_all_last;
	//*****************************************//
	
	
	Roll_out = K_roll_P * Error_roll_all + K_roll_I * Error_roll_I + K_roll_D * Error_roll_D;
	Error_roll_all_last = Error_roll_all;
	//#################################################################################################
	//***************PITCH**********************//
	//*******************P *****************//
	Error_pitch_all = 0 - pitch;   
	
	//*******************I ****************//
	if(Error_pitch_all > Error_pitch_max)
	{
		Error_pitch_I += Error_pitch_max;
	}
	else Error_pitch_I = Error_pitch_I + Error_pitch_all;
	
	//*******************D ***************//
	Error_pitch_D = Error_pitch_all - Error_pitch_all_last;
	//******************************************//
	
	Pitch_out = K_pitch_P * Error_pitch_all + K_pitch_I * Error_pitch_I + K_pitch_D * Error_pitch_D;
	Error_pitch_all_last = Error_pitch_all;
	//#################################################################################################
	
	
		//***************YAW**********************//
	//*******************P *****************//
	Error_yaw_all = 0 - yaw;   
	
	//*******************I ****************//
	if(Error_yaw_all > Error_yaw_max)
	{
		Error_yaw_I += Error_yaw_max;
	}
	else Error_yaw_I = Error_yaw_I + Error_yaw_all;
	
	//*******************D ***************//
	Error_yaw_D = Error_yaw_all - Error_yaw_all_last;
	//******************************************//
	
	Yaw_out = K_yaw_P * Error_yaw_all + K_yaw_I * Error_yaw_I + K_yaw_D * Error_yaw_D;
	Error_yaw_all_last = Error_yaw_all;
	//#################################################################################################
}


float IN_Error_roll_all,
	IN_Error_roll_max = 50.0f,
	IN_Error_roll_I_max = 5000.0f,
	IN_Error_roll_I,
	IN_Error_roll_D,
	IN_Error_roll_all_last,
	IN_K_roll_P = 4.0f,
	IN_K_roll_I = 0.005f,
	IN_K_roll_D = 1.0f,
	IN_Roll_out
;

float IN_Error_pitch_all,
	IN_Error_pitch_max = 50.0f,
	IN_Error_pitch_I_max = 5000.0f,
	IN_Error_pitch_I,
	IN_Error_pitch_D,
	IN_Error_pitch_all_last,
	IN_K_pitch_P = 4.0f,
	IN_K_pitch_I = 0.005f,
	IN_K_pitch_D = 1.0f,
	IN_Pitch_out
;

float IN_Error_yaw_all,
	IN_Error_yaw_max = 50.0f,
	IN_Error_yaw_I_max = 5000.0f,
	IN_Error_yaw_I,
	IN_Error_yaw_D,
	IN_Error_yaw_all_last,
	IN_K_yaw_P = 4.0f,
	IN_K_yaw_I = 0.005f,
	IN_K_yaw_D = 1.0f,
	IN_Yaw_out
;

void PID_inner(void)
{
		//***************roll**********************//
	float z_g,y_g, x_g;
	y_g = (Y_G_f-Y_G_2) * RawData_to_Radian;
	x_g = (X_G_f-X_G_2) * RawData_to_Radian;
	z_g = (Z_G_f-Z_G_2) * RawData_to_Radian;
//	y_g = 0;
//	x_g = 0;
	//*******************P *****************//
	IN_Error_roll_all = Roll_out  - x_g * 57.3;   
	//*******************I ****************//
	if(IN_Error_roll_all > IN_Error_roll_max)
	{
		IN_Error_roll_I += IN_Error_roll_max;
	}
	else IN_Error_roll_I = IN_Error_roll_I + IN_Error_roll_all;
	//*******************D ***************//
	IN_Error_roll_D = IN_Error_roll_all - IN_Error_roll_all_last;
	//****************************************************************//
	IN_Roll_out = IN_K_roll_P * IN_Error_roll_all + IN_K_roll_I * IN_Error_roll_I + IN_K_roll_D * IN_Error_roll_D;
	IN_Error_roll_all_last = IN_Error_roll_all;
	//#################################################################################################
	//***************PITCH**********************//
	//*******************P *****************//
	IN_Error_pitch_all = Pitch_out - y_g * 57.3;    
	//*******************I ****************//
	if(IN_Error_pitch_all > IN_Error_pitch_max)
	{
		IN_Error_pitch_I += IN_Error_pitch_max;
	}
	else IN_Error_pitch_I = IN_Error_pitch_I + IN_Error_pitch_all;
	//*******************D ***************//
	IN_Error_pitch_D = IN_Error_pitch_all - IN_Error_pitch_all_last;
	//***********************************************************************//
	IN_Pitch_out = IN_K_pitch_P * IN_Error_pitch_all + IN_K_pitch_I * IN_Error_pitch_I + IN_K_pitch_D * IN_Error_pitch_D;
	IN_Error_pitch_all_last = IN_Error_pitch_all;
	//#################################################################################################
	//***************YAW**********************//
	//*******************P *****************//
	IN_Error_yaw_all = Yaw_out - z_g * 57.3;    
	//*******************I ****************//
	if(IN_Error_yaw_all > IN_Error_yaw_max)
	{
		IN_Error_yaw_I += IN_Error_yaw_max;
	}
	else IN_Error_yaw_I = IN_Error_yaw_I + IN_Error_yaw_all;
	//*******************D ***************//
	IN_Error_yaw_D = IN_Error_yaw_all - IN_Error_yaw_all_last;
	//***********************************************************************//
	IN_Yaw_out = IN_K_yaw_P * IN_Error_yaw_all + IN_K_yaw_I * IN_Error_yaw_I + IN_K_yaw_D * IN_Error_yaw_D;
	IN_Error_yaw_all_last = IN_Error_yaw_all;
	//#################################################################################################
}







