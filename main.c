#include <stm32f10x.h>
#include "garrita.h"
#include "interrupts.h"
#include "gpio.h"
#include "delay.h"




int main(void)
{
    init_gpio();
    init_interruputs();
    timer2_pwm();
    timer3_pwm();
	  void delay_ms(uint32_t ms);
    
    while(1)
    {
        
            motor2_secuencia1(); // 0°->90°->180°
			delay_ms(1000);
            motor1_secuencia2();
			delay_ms(100000);
		}
        
            motor2_secuencia1(); // 0°->90°->180°
            delay_ms(1000);
            motor2_secuencia2();
			delay_ms(10000);
        }



