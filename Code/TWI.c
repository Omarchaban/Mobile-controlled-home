


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI.h"
//#include <avr/io.h>


void TWI_MasterInit(void)
{
	/*setting prescaler to 1*/
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);
	/*setting bit rate to 2*/
	TWBR =0x02;
	/*Enabling TWI*/
	SET_BIT(TWCR,TWCR_TWEN);

}
void TWI_SlaveInit(u8 Address)
{
	/*Set the slave address*/
	TWAR =Address<<1;

	/*Enabling TWI*/
	SET_BIT(TWCR,TWCR_TWEA);

}
void TWI_SendStart(void)
{
//	/*clear the interrupt flag to make the previous operation*/
TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	/*Wait till the interrupt flag is raised */
	while(GET_BIT(TWCR,TWCR_TWINT) ==0);



}


void TWI_MasterSendData(u8 Data)
{
//
	/*Put data in data register*/
	TWDR =Data;
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	/*clear the interrupt flag to make the previous operation*/
	/*Wait till the interrupt flag is raised */
	while(GET_BIT(TWCR,TWCR_TWINT) ==0);

}

u8 TWI_MasterReadData(void)
{

	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	/*clear the interrupt flag to make the previous operation*/

	/*Wait till the interrupt flag is raised */
	while(GET_BIT(TWCR,TWCR_TWINT) ==0);



	return TWDR;

}

void TWI_SendStop(void)
{
//	/*clear the interrupt flag to make the previous operation*/
TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTO) | (1 << TWCR_TWEN);
}




