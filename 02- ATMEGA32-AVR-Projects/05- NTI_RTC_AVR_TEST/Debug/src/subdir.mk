################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIO_program.c \
../src/GIE_program.c \
../src/I2C_program.c \
../src/LCD_program.c \
../src/RTC_program.c \
../src/main.c 

OBJS += \
./src/DIO_program.o \
./src/GIE_program.o \
./src/I2C_program.o \
./src/LCD_program.o \
./src/RTC_program.o \
./src/main.o 

C_DEPS += \
./src/DIO_program.d \
./src/GIE_program.d \
./src/I2C_program.d \
./src/LCD_program.d \
./src/RTC_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


