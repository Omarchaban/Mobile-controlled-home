

#ifndef DIO_H_
#define DIO_H_

#include "STD_TYPES.h"

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7

#define HIGH         1
#define LOW          0

#define INPUT        0
#define OUTPUT       1

u8 SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);
u8 SetPortDirection(u8 Copy_u8Port,u8 Copy_u8Value);
u8 SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
u8 SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
u8 GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
u8 GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

#endif /* DIO_H_ */
