#include "STD_TYPES.h"
#include "DIO.h"
#include "motor.h"
#include <util/delay.h>
#include "UART.h"
#include "TWI.h"
#include "EEPROM.h"
#include "TIMER.h"

#define LOGIN	'0'
#define SIGNUP	'1'
#define LED 	'2'
#define MOTOR	'3'
u8 ForLoopCounter=0;								/*Global counter for for loops*/

u8 stringcmp(u8 *UserName,u8 *ConfirmedUserName);	/*Function to compare two strings*/
void main()
{
	u8 UserName[5];									/*Array to store the username*/
	u8 PassWord[5];									/*Array to store the password*/

	u8 state; 										//for login or signing in

	u8 UserNameCounter=0x00;						/*Counter to know the index of the last entered username to avoid overwriting*/
	u8 PassWordCounter=0x00;						/*Counter to know the index of the last entered password to avoid overwriting*/
	u8 UserNameCounterRead;							/*Variable to read the username counter*/
	u8 PassWordCounterRead;							/*Variable to read the password counter*/
	u8 ConfirmedUserName[5];
	u8 ConfirmedPassWord[5];
	u8 UserNameFlag=0;								/*To check if the username exists or not*/
	EEPROM_SendUserName(0b11111111,UserNameCounter);	/*Send the UserNameCounter to eeprom to store it*/
	_delay_ms(1000);
	EEPROM_SendUserName(0b11111110,PassWordCounter);	/*Send the PassWordCounter to eeprom to store it*/
	_delay_ms(1000);

	u8 i;							/*To know the exact 5 bytes of the User name and password*/

	TIMER_init();
	DC_voidInit();
	UART_init();
	TWI_MasterInit();

	SetPinDirection(DIO_PORTC,PIN0,OUTPUT);

	SetPinDirection(DIO_PORTD,PIN1,OUTPUT);
	SetPinDirection(DIO_PORTD,PIN0,INPUT);
	SetPinDirection(DIO_PORTA,PIN0,OUTPUT);

	while(1)
	{
		UART_SendSting("Enter 0 for login or 1 for singup :");
		state=UART_ReceiveByte();
		UART_SendSting("\r\n");
		switch(state)
		{
		case LOGIN:
			EEPROM_ReadUserName(0b11111111,&UserNameCounterRead);	/*Read the location in which the username will be stored*/
			EEPROM_SendUserName(0b11111111,++UserNameCounter);		/*Increment the position of the current username then send it to eeprom*/

			/*For loop for user to enter his user name*/
			UART_SendSting("Enter UserName:");
			for(u8 i=UserNameCounterRead*5;i<(UserNameCounterRead*5)+0x05;i++)
			{
				UserName[ForLoopCounter] =UART_ReceiveByte();
				EEPROM_SendUserName(UserName[ForLoopCounter],i);
				_delay_ms(1000);

			}
			ForLoopCounter=0;
			UART_SendSting("\r\nEnter Password:");
			EEPROM_ReadPassWord(0b11111110,&PassWordCounterRead);	/*Read the location in which the Password will be stored*/
			EEPROM_SendPassWord(0b11111110,++PassWordCounter);		/*Increment the position of the current Password then send it to eeprom*/
			/*For loop for the user to enter password*/
			for(u8 i=PassWordCounterRead*5;i<(PassWordCounterRead*5)+0x05;i++)
			{
				PassWord[ForLoopCounter] =UART_ReceiveByte();
				EEPROM_SendPassWord(PassWord[ForLoopCounter],i);
				_delay_ms(1000);
			}
			ForLoopCounter=0;
			UART_SendSting("\r\n");
			break;

		case SIGNUP:

			for(u8 trials =0;trials<3; trials++)
			{
				UserNameFlag=0;
				UART_SendSting("Enter UserName :");
				for(u8 x=0;x<0x05;x++)
				{
					UserName[x] =UART_ReceiveByte();

				}
				for(i=0x00;i<0x32;i+=0x05)		/*loop that jumps to the first byte of every User name*/
				{

					for(u8 j=i;j<(0x05+i);j++)	/*loop to go through each byte of each User name*/
					{

						EEPROM_ReadUserName(j,&ConfirmedUserName[ForLoopCounter]);	/*Store the User name from eeprom into this array*/
						_delay_ms(100);
						ForLoopCounter++;

					}
					ForLoopCounter=0;
					if(stringcmp(UserName,ConfirmedUserName) == 1)
					{
						UART_SendSting("\r\nWelcome ");
						UART_SendSting(UserName);
						UART_SendSting("\r\n");
						goto label;				/*Jumps to the end of the loop*/
					}
					else
					{
						UserNameFlag++;						/*Increment the flag if the comparison equals 0*/
						if(UserNameFlag ==10)
						{
							UART_SendSting("\r\nWrong UserName Try again\r\n");
						}
					}
				}
				if((trials == 2) && (stringcmp(UserName,ConfirmedUserName) == 0))
				{
					SetPinValue(DIO_PORTC,PIN0,HIGH);
					_delay_ms(5000);
					SetPinValue(DIO_PORTC,PIN0,LOW);

					goto label2;
				}
			}
			label:
			ForLoopCounter=0;
			for(u8 trials =0;trials<3; trials++)
			{
				UART_SendSting("Enter PassWord :");
				for(u8 x=0;x<0x05;x++)
				{
					PassWord[x] =UART_ReceiveByte();

				}

				for(u8 j=i;j<(0x05+i);j++)	/*Now that we have known the location of the User name lets loop through his password */
				{

					EEPROM_ReadPassWord(j,&ConfirmedPassWord[ForLoopCounter]);	/*Store the Password from eeprom into this array*/
					_delay_ms(100);
					ForLoopCounter++;
				}
				ForLoopCounter=0;
				if(stringcmp(PassWord,ConfirmedPassWord) == 1)
				{
					UART_SendSting("\r\n");
					UART_SendSting("Enter 2 for Led or 3 for Motor :");
					UART_SendSting("\r\n");
					state=UART_ReceiveByte();
					switch(state)
					{
					case LED:
						SetPinValue(DIO_PORTA,PIN0,HIGH);
						break;
					case MOTOR:
						DC_Rotate(CW,100);
						_delay_ms(10000);
						DC_Rotate(CCW,100);
						_delay_ms(10000);
						DC_Rotate(OFF,0);
						break;
					default:
						UART_SendSting("Wrong operation\r\n");
						break;
					}
					goto label2;
				}
				else
				{
					UART_SendSting("\r\nWrong Password\r\n");
				}
				if((trials == 2) && (stringcmp(PassWord,ConfirmedPassWord) != 1))
				{
					SetPinValue(DIO_PORTC,PIN0,HIGH);
					_delay_ms(5000);
					SetPinValue(DIO_PORTC,PIN0,LOW);

				}
			}
			label2:
			break;

		}
	}

}

u8 stringcmp(u8 *UserName,u8 *ConfirmedUserName)
{	u8 Confirmed=1;
for(u8 i=0;i<5;i++)
{
	if(UserName[i] == ConfirmedUserName[i])
		continue;
	else
	{
		Confirmed=0;
		break;
	}
}
return Confirmed;
}
