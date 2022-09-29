


#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO.h"
#include"UART.h"


void UART_init()
{
	u8 var;
	SET_BIT(var,UCSRC_URSEL);
	SET_BIT(var,UCSRC_UCSZ1);
	SET_BIT(var,UCSRC_UCSZ0);
	/*Setting Baud rate to 9600*/
	UBRRL=12;

	/*1-Selecting UCSRC
	  2- Choosing Asynchronous mode
	  3-Disable Parity mode
	  4-Selecting 1 stop bit
	  5-Choosing 8-bit data*/
	UCSRC=var;


	/*Rx Enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	/*Tx Enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);

}

u8 UART_ReceiveByte()
{
	while(GET_BIT(UCSRA,UCSRA_RXC) ==0);
	return UDR;
}

void UART_SendByte(u8 Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE) ==0);
    UDR =Data;

}


void UART_SendSting(const char *string)
{
	u16 counter=0;
	while(string[counter] != '\0')
	{
		UART_SendByte(string[counter]);
		counter++;

	}



}


