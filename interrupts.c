/*
EXTI program:
- Enable the clocks for GPIOs and AFIO.
- Configure the Alternate Function to use a GPIO (usually standard after reset).
- Configure the interrupt input pin as input using CRL and CRH registers.
- Select the interrupt input pin using AFIO_EXTICR.
- Configure the RTSR and FTSR registers to choose the interrupt edge.
- Set the EXTI_IMR register to enable the interrupt for the line.
- Enable the EXTI interrupt using the ISER register or NVIC_EnableIRQ function.
- Clear the PR flag in the interrupt routine.
*/
#include <stm32f10x.h>
#include "interrupts.h"



/*
	Selects PB4 as the input for external interrupt.
	On each falling edge, an interrupt is generated.
	Interrupt service routine toggles Led on PC13.
*/
void init_interruputs()
{
	AFIO->EXTICR[0] = (1 << 0); //Selects PA1 for line 1
	EXTI->FTSR |= (1 << 1);	//interrupt on falling edge
	EXTI->IMR |= (1 << 1);	//enable interrupt
	AFIO->EXTICR[0] = (1 << 8); //Selects PA1 for line 1
	EXTI->FTSR |= (1 << 2);	//interrupt on falling edge
	EXTI->IMR |= (1 << 2);	//enable interrupt
	NVIC->ISER[0] |= (1<<8);
	NVIC->ISER[0] |= (1 << 7);

}
void EXTI_IRQHandler()
{
 EXTI->PR |= (1 << 1);
	
 GPIOC->ODR ^= (1 << 13);
	
 }
void EXTI2_IRQHandler()
{
    EXTI->PR |= (1 << 2);
   
    GPIOC->ODR ^= (1 << 13);
}


