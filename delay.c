/*
 * delay.c
 *
 *  Created on: 25.06.2018
 *      Author: RTomczyk
 */
#include "stm32f0xx.h"
#include "delay.h"

volatile uint32_t flag = 0;

void _delay_init( uint32_t system_clock_speed )
{
	  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	  TIM2->ARR     = system_clock_speed / 1000000;
	  TIM2->PSC     = 0;
	  TIM2->CNT     = 0;
	  TIM2->SR      = 0;


}

void _delay_us( DELAY_t us )
{
	if(us==1)asm volatile("nop");
	else
	{
		TIM2->CR1 |= TIM_CR1_CEN;
		do
		{
			us--;
			while(!(TIM2->SR & TIM_SR_UIF));
			TIM2->SR = 0;
		}while(us);
		TIM2->CR1 &= ~TIM_CR1_CEN;
		TIM2->CNT = 0;
		TIM2->SR = 0;
	}
}

void _delay_ms( DELAY_t ms )
{
	while(ms--)	_delay_us( 1000 );
}


