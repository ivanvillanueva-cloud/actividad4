/*GPIO functional description (p.158)
Memory and bus architecture (p.46)

*/

#include <stm32f10x.h>
#include "garrita.h"
#include "interrupts.h"
#include "gpio.h"

int main(void)
{
  init_gpio();
  init_interruputs();
	timer2_pwm();
	timer3_pwm();
	while(1)
	{
		
 }
	}
