################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Sev_Seg_LT.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Sev_Seg_LT.elf secondary-outputs

# Tool invocations
Sev_Seg_LT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Sev_Seg_LT.map -mmcu=atmega32 -o "Sev_Seg_LT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Sev_Seg_LT.lss: Sev_Seg_LT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Sev_Seg_LT.elf  >"Sev_Seg_LT.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Sev_Seg_LT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Sev_Seg_LT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Sev_Seg_LT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
