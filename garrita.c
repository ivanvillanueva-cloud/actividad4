#include <stm32f10x.h>
#include "garrita.h"

// Valores PWM para posiciones específicas

void timer2_pwm()
{
    RCC->APB1ENR |= 1 << 0; // TIM2 clock enable
    TIM2->PSC = 27;
    TIM2->ARR = 64284;
    TIM2->CCMR1 |= (1 << 6) | (1 <<5);
    TIM2->CCER |= (1 << 4);
    TIM2->CR1 |= (1 << 7) | (1 << 0);
    TIM2->CCR2 = 1800;
}

void timer3_pwm()
{
    RCC->APB1ENR |= 1 << 1; // TIM3 clock enable
    TIM3->PSC = 27;
    TIM3->ARR = 64284;
    TIM3->CCMR1 |= (1 << 6) | (1 << 5);
    TIM3->CCER |= (1 << 4);
    TIM3->CR1 |= (1 << 7) | (1 << 0);
    TIM3->CCR2 = 1800;
	
}

void motor1_secuencia1()
{
    // 0°->90°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM2->CCR2 = 1800;
        for(int j = 0; j < 75453; j++);
    }
    
    // 90°->180°
    for(volatile int i = 100; i > 0; i--)
    {
        TIM2->CCR2 = 3857;
        for(int j = 0; j < 75453; j++);
    }
    
    // Mantener 180°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM2->CCR2 = 5914;
        for(int j = 0; j < 75453; j++);
    }
}

void motor1_secuencia2()
{
    // 180°->90°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM2->CCR2 =5914;
        for(int j = 0; j < 75453; j++);
    }
    
    // 90°->0°
    for(volatile int i = 100; i > 0; i--)
    {
        TIM2->CCR2 = 3857;
        for(int j = 0; j < 75453; j++);
    }
    
    // Mantener 0°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM2->CCR2 = 1800;
        for(int j = 0; j < 75453; j++);
    }
}

void motor2_secuencia1()
{
    // 0°->90°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM3->CCR2 = 18000;
        for(int j = 0; j < 65453; j++);
    }
    
    // 90°->180°
    for(volatile int i = 100; i > 0; i--)
    {
        TIM3->CCR2 = 3857;
        for(int j = 0; j < 65453; j++);
    }
    
    // Mantener 180°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM3->CCR2 = 5914;
        for(int j = 0; j < 65453; j++);
    }
}

void motor2_secuencia2()
{
    // 180°->90°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM3->CCR2 = 1800;
        for(int j = 0; j < 65453; j++);
    }
    
    // 90°->0°
    for(volatile int i = 100; i > 0; i--)
    {
        TIM3->CCR2 = 3857;
        for(int j = 0; j < 65453; j++);
    }
    
    // Mantener 0°
    for(volatile int i = 0; i < 100; i++)
    {
        TIM3->CCR2 = 1800;
        for(int j = 0; j < 65453; j++);
    }
}