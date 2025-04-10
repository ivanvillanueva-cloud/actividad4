#include <stm32f10x.h>
#include "garrita.h"
#include "interrupts.h"
#include "gpio.h"
#include "delay.h"



int main(void)
{
    init_gpio();
	  timer2_pwm();
		timer3_pwm();
		init_interruputs();
    
    while(1)
    {
        
   
        }
			}