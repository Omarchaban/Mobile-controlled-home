
#ifndef UART_H_
#define UART_H_
#include "STD_TYPES.h"

#define  UDR         	*((volatile u8 *)0x2c)
#define  UCSRA          *((volatile u8 *)0x2b)
#define  UCSRA_RXC		7
#define  UCSRA_TXC		6
#define  UCSRA_UDRE		5


#define  UCSRB          *((volatile u8 *)0x2a)
#define  UCSRB_RXCIE	7
#define  UCSRB_TXCIE	6
#define  UCSRB_RXEN		4
#define  UCSRB_TXEN		3

#define  UBRRL          *((volatile u8 *)0x29)
#define  UCSRC          *((volatile u8 *)0x40) 		//UBRRH has the same address
#define UCSRC_URSEL		7
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1


#define  UBRRH          *((volatile u8 *)0x40)
void UART_init();

u8 UART_ReceiveByte();
void UART_SendByte(u8 Data);

void UART_SendSting(const char *string);

#endif /* UART_H_ */
