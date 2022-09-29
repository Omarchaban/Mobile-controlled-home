
#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD_TYPES.h"

void EEPROM_SendUserName(u8 Data,u8 Byte_Address);
void EEPROM_SendPassWord(u8 Data,u8 Byte_Address);
void EEPROM_ReadUserName(char Byte_Adress,u8 *reading);
void EEPROM_ReadPassWord(char Byte_Adress,u8 *reading);

#endif /* EEPROM_H_ */
