

#include "DIO.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reg2.h"

u8 SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	u8 Local_Error =0;
	if(Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= PIN7)
	{
		if(Copy_u8Direction ==0 )
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
			default: Local_Error =1; break;

			}

		}
		else if (Copy_u8Direction ==1)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
			case DIO_PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
			case DIO_PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
			case DIO_PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
			default: Local_Error =1; break;

			}
		}
	}
		else
		{
			Local_Error =1;
		}

	return Local_Error;

}

u8 SetPortDirection(u8 Copy_u8Port,u8 Copy_u8Value)
{ u8 Local_Error =0;
if(Copy_u8Port <= DIO_PORTD )
{
	switch(Copy_u8Port)
	{
	case DIO_PORTA : DDRA = Copy_u8Value; break;
	case DIO_PORTB : DDRB = Copy_u8Value; break;
	case DIO_PORTC : DDRC = Copy_u8Value; break;
	case DIO_PORTD : DDRD = Copy_u8Value; break;
	default: Local_Error =1; break;

	}


}
else
{
	Local_Error =0;
}
return Local_Error;
}
u8 SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	u8 Local_Error =0;
	if(Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= PIN7)
	{
		if(Copy_u8Value ==HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(PORTA ,Copy_u8Pin); break;
			case DIO_PORTB : SET_BIT(PORTB ,Copy_u8Pin); break;
			case DIO_PORTC : SET_BIT(PORTC ,Copy_u8Pin); break;
			case DIO_PORTD : SET_BIT(PORTD ,Copy_u8Pin); break;
			default : Local_Error =1; break;
			}
		}
		else if(Copy_u8Value ==LOW)
		{switch(Copy_u8Port){
case DIO_PORTA : CLR_BIT(PORTA ,Copy_u8Pin); break;
case DIO_PORTB : CLR_BIT(PORTB ,Copy_u8Pin); break;
case DIO_PORTC : CLR_BIT(PORTC ,Copy_u8Pin); break;
case DIO_PORTD : CLR_BIT(PORTD ,Copy_u8Pin); break;
default : Local_Error=1; break;
		}
		}
	}
	else
	{
		Local_Error =1;
	}

	return Local_Error;
}
u8 SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value){
	u8 Local_Error =0;
	if(Copy_u8Port <= DIO_PORTD)
	{


		switch(Copy_u8Port)
		{
		case DIO_PORTA : PORTA = Copy_u8Value; break;
		case DIO_PORTB : PORTB = Copy_u8Value; break;
		case DIO_PORTC : PORTC = Copy_u8Value; break;
		case DIO_PORTD : PORTD = Copy_u8Value; break;
		default : Local_Error =1; break;
		}
	}

	else
	{
		Local_Error = 1;
	}

		return Local_Error;
}
u8 GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case DIO_PORTA: u8ResultLocal= GET_BIT(PORTA,u8PinIdCopy); break;
			case DIO_PORTB: u8ResultLocal= GET_BIT(PORTB,u8PinIdCopy); break;
			case DIO_PORTC: u8ResultLocal= GET_BIT(PORTC,u8PinIdCopy); break;
			case DIO_PORTD: u8ResultLocal= GET_BIT(PORTD,u8PinIdCopy); break;
		}
	}

	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}

	return u8ResultLocal;
}

