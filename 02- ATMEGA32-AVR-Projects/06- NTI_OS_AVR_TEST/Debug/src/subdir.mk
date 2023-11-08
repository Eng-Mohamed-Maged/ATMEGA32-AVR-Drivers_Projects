################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIO_program.c \
../src/EXTI_program.c \
../src/GIE_program.c \
../src/OS_program.c \
../src/TIMER0_program.c \
../src/main.c 

OBJS += \
./src/DIO_program.o \
./src/EXTI_program.o \
./src/GIE_program.o \
./src/OS_program.o \
./src/TIMER0_program.o \
./src/main.o 

C_DEPS += \
./src/DIO_program.d \
./src/EXTI_program.d \
./src/GIE_program.d \
./src/OS_program.d \
./src/TIMER0_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


