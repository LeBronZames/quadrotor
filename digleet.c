#include "hardware.h"


void Digleet_task(void *pdata)
{
	 
	 cnt = 59;
	 kir = 0;
	 TFT_clear(0xffff);
	 TFT_background(0xffff);
	 delay_ms(100);
	 
	 while(1)
	 {
		 if(start == 0)
		 {
		 
			 draw_word(60, 200, 'S', 0x5656);
			 draw_word(60+25, 200, 'T', 0x5656);
			 draw_word(60+25+20, 200, 'A', 0x5656);
			 draw_word(60+20+25+20, 200, 'R', 0x5656);
			 draw_word(60+20+25+20+20, 200, 'T', 0x5656);
			 delay_ms(100);
		 }
		
		
		 
		 
		 if(start == 1)
		 {
			 TFT_clear(0xffff);
			 TFT_background(0xffff);
			 draw_circle();
			
			 draw_word(20, 290, 'R', 0x5656);
			 draw_word(20+25, 290, 'E', 0x5656);
			 draw_word(20+25+20, 290, 'M', 0x5656);
			 draw_word(20+30+25+20, 290, 'A', 0x5656);
			 draw_word(20+30+25+20+20, 290, 'I', 0x5656);
			 draw_word(20+30+25+20+20+20, 290, 'N', 0x5656);
			 
			 
			 draw_word(20, 70, 'S', 0x5656);
			 draw_word(20+20, 70, 'C', 0x5656);
			 draw_word(20+20+20, 70, 'O', 0x5656);
			 draw_word(20+20+20+20, 70, 'R', 0x5656);
			 draw_word(20+20+20+20+25, 70, 'E', 0x5656);

			 
			do
			{
				rand_x = Get_Adc(ADC_Channel_1)%3;
				TFT_clear_num_1();
				draw_number(30, 225, number_tran_to_display_shi(cnt), 0x5656);
				draw_number(30+20, 225, number_tran_to_display_ge(cnt), 0x5656);
				TFT_clear_num_2();
				draw_number(20+20+20+20+25+40, 70, number_tran_to_display_shi(score), 0x5656);
				draw_number(20+20+20+20+25+40+20, 70, number_tran_to_display_ge(score), 0x5656);
				
				draw_color(rand_x);
				
				delay_ms(333);
				kir = !kir;
				draw_circle();
				delay_ms(333);
				kir = !kir;
				draw_circle();
				delay_ms(333);
				kir = !kir;
				draw_circle();
				
				cnt --;
				TFT_clear_diglett();
				rand_x = Get_Adc(ADC_Channel_1)%3;
				
				
				
				//draw_Diglett(1);
			}while(cnt >= 0);
			
			start = 0;
			TFT_clear(0xffff);
	    TFT_background(0xffff);
			cnt = 59;
			draw_word(20, 225, 'S', 0x5656);
			draw_word(20+20, 225, 'C', 0x5656);
			draw_word(20+20+20, 225, 'O', 0x5656);
			draw_word(20+20+20+20, 225, 'R', 0x5656);
			draw_word(20+20+20+20+25, 225, 'E', 0x5656);
			draw_number(20+20+20+20+25+40, 225, number_tran_to_display_shi(score), 0x5656);
			draw_number(20+20+20+20+25+40+20, 225, number_tran_to_display_ge(score), 0x5656);
			
			delay_ms(999);
			delay_ms(999);
			delay_ms(999);
			delay_ms(999);
			delay_ms(999);
			score = 0;
			start = 0;
			TFT_clear(0xffff);
			TFT_background(0xffff);
		}
	}
	
}
	

char number_tran_to_display_ge(int cnt)
{
	int a;
	int b;
	b = cnt/10;
	a = cnt - (b*10) ;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
	}
	return 0;
}
char number_tran_to_display_shi(int cnt)
{
	
	int a;
	a = cnt/10 - (cnt/100)*10;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
	}
	return 0;
	
	
}
	

char number_tran_to_display_bai(int cnt)
{
	
	int a;
	a = cnt/100-(cnt/1000)*10;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
	}
	return 0;
	
	
}


char number_tran_to_display_qian(int cnt)
{
	
	int a;
	a = cnt/1000-(cnt/10000)*10;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
	}
	return 0;
	
	
}


char number_tran_to_display_wan(int cnt)
{
	
	int a;
	a = cnt/10000;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
	}
	return 0;
	
	
}










