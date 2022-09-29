
#include "STD_TYPES.h"
#include "EEPROM.h"
#include "TWI.h"


void EEPROM_SendUserName(u8 Data,u8 Byte_Address)
{
	/*Send start bit to start communication*/
	TWI_SendStart();
	/*Send the username to the first page in eeprom*/
	TWI_MasterSendData(0xA8);
	/*sending the address where the data will be stored in*/
	TWI_MasterSendData(Byte_Address);
	/*Send the data*/
	TWI_MasterSendData(Data);
	/*Stop the communication*/
	TWI_SendStop();

}
void EEPROM_SendPassWord(u8 Data,u8 Byte_Address)
{
	/*Send start bit to start communication*/
	TWI_SendStart();
	/*Send the Password to the second page in eeprom*/
	TWI_MasterSendData(0xAA);
	/*sending the address where the data will be stored in*/
	TWI_MasterSendData(Byte_Address);
	/*Sending the data*/
	TWI_MasterSendData(Data);
	/*Stop the communication*/
	TWI_SendStop();

}
void EEPROM_ReadUserName(char Byte_Adress,u8 *reading)
{
	/*Send start bit to start communication*/
	TWI_SendStart();
	/*Send the username to the first page in eeprom*/
	TWI_MasterSendData(0xA8);
	/*sending the address where the data will be stored in*/
	TWI_MasterSendData(Byte_Adress);
	/*Send repeating start*/
	TWI_SendStart();

	TWI_MasterSendData(0xA9);

	*reading=TWI_MasterReadData();

	TWI_SendStop();

}
void EEPROM_ReadPassWord(char Byte_Adress,u8 *reading)
{
		/*Send start bit to start communication*/
		TWI_SendStart();
		/*Send the password to the second page in eeprom*/
		TWI_MasterSendData(0xAA);
		/*sending the address where the data will be stored in*/
		TWI_MasterSendData(Byte_Adress);
		/*Send repeating start*/
		TWI_SendStart();
		/*Send the address of the eeprom but this time with read request*/
		TWI_MasterSendData(0xAB);

		*reading=TWI_MasterReadData();

		TWI_SendStop();
}










