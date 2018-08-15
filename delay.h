/*
 * delay.h
 *
 *  Created on: 25.06.2018
 *      Author: RTomczyk
 */

#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_

typedef uint32_t DELAY_t;

void _delay_init( uint32_t system_clock_speed );
void _delay_us( DELAY_t us );
void _delay_ms( DELAY_t ms );


#endif /* DELAY_DELAY_H_ */
