################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Utilities/STM32F1xx_Nucleo/subdir.mk
-include HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan.elf

# Tool invocations
Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan.elf: $(OBJS) $(USER_OBJS) C:\Users\Lukas\workspace\Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan.elf" "Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan.bin"
	arm-none-eabi-size "Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
