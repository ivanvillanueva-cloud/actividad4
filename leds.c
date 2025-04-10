#include <stm32f10x.h>

#include "delay.h"
#include "garrita.h"

void led_on_off(int repeat){
		delay_init();
		for(int i=1; i <= repeat; i++){
		GPIOC->ODR ^=(1 << 13);
		delay_ms(200);
		}
}

void led_onoff_timer2(int repeat){
		for(int i=1; i <= repeat; i++)
	{
		GPIOC->ODR ^=(1 << 13);
		delaytimer2();
		}
}
