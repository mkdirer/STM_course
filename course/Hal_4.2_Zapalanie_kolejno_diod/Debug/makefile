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
all: Hal_4.2_Zapalanie_kolejno_diod.elf

# Tool invocations
Hal_4.2_Zapalanie_kolejno_diod.elf: $(OBJS) $(USER_OBJS) C:\Users\Lukas\workspace\Hal_4.2_Zapalanie_kolejno_diod/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Hal_4.2_Zapalanie_kolejno_diod.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Hal_4.2_Zapalanie_kolejno_diod.elf" "Hal_4.2_Zapalanie_kolejno_diod.bin"
	arm-none-eabi-size "Hal_4.2_Zapalanie_kolejno_diod.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
