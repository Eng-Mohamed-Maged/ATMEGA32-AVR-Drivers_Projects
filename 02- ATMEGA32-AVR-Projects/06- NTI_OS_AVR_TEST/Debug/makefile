################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NTI_OS_AVR_TEST.lss \

FLASH_IMAGE += \
NTI_OS_AVR_TEST.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_OS_AVR_TEST.elf secondary-outputs

# Tool invocations
NTI_OS_AVR_TEST.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_OS_AVR_TEST.map -mmcu=atmega32 -o "NTI_OS_AVR_TEST.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_OS_AVR_TEST.lss: NTI_OS_AVR_TEST.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_OS_AVR_TEST.elf  >"NTI_OS_AVR_TEST.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_OS_AVR_TEST.hex: NTI_OS_AVR_TEST.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_OS_AVR_TEST.elf  "NTI_OS_AVR_TEST.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_OS_AVR_TEST.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_OS_AVR_TEST.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_OS_AVR_TEST.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
