################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EEPROM.c \
../TIMER.c \
../TWI.c \
../UART.c \
../eep.c \
../main.c \
../motor.c \
../twi2.c 

OBJS += \
./DIO.o \
./EEPROM.o \
./TIMER.o \
./TWI.o \
./UART.o \
./eep.o \
./main.o \
./motor.o \
./twi2.o 

C_DEPS += \
./DIO.d \
./EEPROM.d \
./TIMER.d \
./TWI.d \
./UART.d \
./eep.d \
./main.d \
./motor.d \
./twi2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


