#include "hardware.h"






/*
void led_init(void)
{
	GPIO_InitTypeDef GPIO_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//改变指定管脚的映射 GPIO_Remap_SWJ_Disable SWJ 完全禁用（JTAG+SW-DP）
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	//改变指定管脚的映射 GPIO_Remap_SWJ_JTAGDisable ，JTAG-DP 禁用 + SW-DP 使能
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	
	GPIO_Structure.GPIO_Pin =  GPIO_Pin_8;	//LED2：电源旁的指示灯
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOA, &GPIO_Structure);
	
	GPIO_Structure.GPIO_Pin =  GPIO_Pin_2;	//LED3：机身周围的夜间灯	
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOD, &GPIO_Structure);
	
	LED0 = 1;  //全灭
	LED1 = 1;
}*/

void led_init_min(void)
{
	GPIO_InitTypeDef GPIO_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	

	
	GPIO_Structure.GPIO_Pin =  GPIO_Pin_12 ;	//LED2：电源旁的指示灯
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOB, &GPIO_Structure);
	

}

void led_init(void)
{
	GPIO_InitTypeDef GPIO_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//改变指定管脚的映射 GPIO_Remap_SWJ_Disable SWJ 完全禁用（JTAG+SW-DP）
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	//改变指定管脚的映射 GPIO_Remap_SWJ_JTAGDisable ，JTAG-DP 禁用 + SW-DP 使能
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	
	GPIO_Structure.GPIO_Pin =  LED2_Pin;	//LED2：电源旁的指示灯
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(LED2_GPIO, &GPIO_Structure);
	
	GPIO_Structure.GPIO_Pin =  LED3_Pin;	//LED3：机身周围的夜间灯	
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(LED3_GPIO, &GPIO_Structure);
}

void led_t(int a){
	LED0 = 0;
	LED1 = 0;
	delay_ms(300);
	LED0 = 1;
	LED1 = 1;
	delay_ms(300);
	LED0 = 0;
	LED1 = 0;
}


