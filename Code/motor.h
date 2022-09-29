#ifndef MOTOR_H_
#define MOTOR_H_
#include "STD_TYPES.h"
#define DC_MOTOR_PORT1 DIO_PORTD
#define DC_MOTOR_PORT2 DIO_PORTD

#define DC_MOTOR_PIN0   PIN6
#define DC_MOTOR_PIN1   PIN7


typedef enum{
	CW ,CCW,OFF

}States;
void DC_voidInit();

void DC_Rotate(States state,u8 speed);

#endif /* MOTOR_H_ */
