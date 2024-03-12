
#include <stdint.h>

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO.h"
#include "lcd.h"


void clock_init()
{
	//Enable port A clock
	RCC_GPIOA_CLK_EN();
	//Enable port B clock
	RCC_GPIOB_CLK_EN();
}
void wait_ms(uint32_t time){
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}//hint time :100 == 1 sec

int main(void)
{
	clock_init();
	lcd_init();
	
	for(int Counter_Col = 0 ; Counter_Col < 16 ; ++Counter_Col){
			lcd_set_position(FIRST_LINE , Counter_Col);
			lcd_send_char('*');
			//wait_ms(10);
		}
		
		for(int Counter_Row = 1 ; Counter_Row < 3 ; ++Counter_Row){
			lcd_set_position(Counter_Row , 15);
			lcd_send_char('*');
			
		}
		
		for(int Counter_Col = 15 ; Counter_Col >= 0 ; --Counter_Col){
			lcd_set_position(FOURTH_LINE , Counter_Col);
			lcd_send_char('*');
			
		}
		
		for(int Counter_Row = 2 ; Counter_Row > 0 ; --Counter_Row){
			lcd_set_position(Counter_Row , 0);
			lcd_send_char('*');
			
		}
		
		lcd_set_position(SECOND_LINE , 1);
		
		lcd_send_string("*IEEE  ManCSC*"); 
		
		for(int Counter_Col = 15 ; Counter_Col >= 0 ; --Counter_Col){
			lcd_set_position(THIRD_LINE , Counter_Col);
			lcd_send_char('*');
			
		}
		
	while(1)
	{
		
		
		
		
	}

}