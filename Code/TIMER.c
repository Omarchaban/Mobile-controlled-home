

#include "TIMER.h"

void TIMER_init()
{
/*for operating in PWM mode*/
SET_BIT(TCCR0,3);
SET_BIT(TCCR0,6);

/**/
CLR_BIT(TCCR0,4);
SET_BIT(TCCR0,5);

/*setting value for comparison*/
//OCR0 =250;

/*setting OCR0 interrupt enable*/
SET_BIT(TIMSK,1);
/*setting prescaler*/
SET_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
CLR_BIT(TCCR0,0);
}
void Timer0_PWM_Init( u8 speed)
{

	OCR0 = speed *2.55;

}
