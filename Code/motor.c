#include "motor.h"

#include "DIO.h"
#include "TIMER.h"
void DC_voidInit(void)
{
 SetPinDirection(DC_MOTOR_PORT1,DC_MOTOR_PIN0,OUTPUT);
 SetPinDirection(DC_MOTOR_PORT2,DC_MOTOR_PIN1,OUTPUT);
 SetPinValue(DC_MOTOR_PORT1,DC_MOTOR_PIN0,LOW);
 SetPinValue(DC_MOTOR_PORT2,DC_MOTOR_PIN1,LOW);
}
void DC_Rotate(States state,u8 speed)
{
	Timer0_PWM_Init(speed);

	switch(state)
	{
	case CW  : SetPinValue(DC_MOTOR_PORT1,DC_MOTOR_PIN0,HIGH); SetPinValue(DC_MOTOR_PORT2,DC_MOTOR_PIN1,LOW); break;
    case CCW : SetPinValue(DC_MOTOR_PORT1,DC_MOTOR_PIN0,LOW); SetPinValue(DC_MOTOR_PORT2,DC_MOTOR_PIN1,HIGH); break;
	case OFF : SetPinValue(DC_MOTOR_PORT1,DC_MOTOR_PIN0,LOW); SetPinValue(DC_MOTOR_PORT2,DC_MOTOR_PIN1,LOW); break;
	}
}
