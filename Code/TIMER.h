

#ifndef TIMER_H_
#define TIMER_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define TCCR0		*((volatile u8 *)0x53)





#define TCNT0 		*((volatile u8 *)0x52)
#define OCR0		*((volatile u8 *)0x5c)
#define TIMSK		*((volatile u8 *)0x59)



void TIMER_init();

void Timer0_PWM_Init(u8 speed);

#endif /* TIMER_H_ */
