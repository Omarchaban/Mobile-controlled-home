#ifndef TWI_H_
#define TWI_H_
#include "STD_TYPES.h"

#define TWBR			*((volatile u8 *)0x20)

#define TWSR			*((volatile u8 *)0x21)
#define TWSR_TWPS1		1
#define TWSR_TWPS0		0

#define TWAR			*((volatile u8 *)0x22)

#define TWDR			*((volatile u8 *)0x23)
#define TWDR_TWGCE		0

#define TWCR			*((volatile u8 *)0x56)
#define TWCR_TWINT		7
#define TWCR_TWEA		6
#define TWCR_TWSTA		5
#define TWCR_TWSTO		4
#define TWCR_TWEN		2


void TWI_MasterInit(void);
void TWI_SlaveInit(u8 Address);
void TWI_SendStart(void);
void TWI_SendStop(void);

void TWI_MasterSendData(u8 Data);
u8 TWI_MasterReadData(void);





#endif /* TWI_H_ */
