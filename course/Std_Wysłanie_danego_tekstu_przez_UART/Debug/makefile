################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
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
all: Wys�anie_danego_tekstu_przez_UART.elf

# Tool invocations
Wys�anie_danego_tekstu_przez_UART.elf: $(OBJS) $(USER_OBJS) C:\Users\Lukas\workspace\Wys�anie_danego_tekstu_przez_UART/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T"C:/Users/Lukas/workspace/Wys�anie_danego_tekstu_przez_UART/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Wys�anie_danego_tekstu_przez_UART.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Wys�anie_danego_tekstu_przez_UART.elf" "Wys�anie_danego_tekstu_przez_UART.bin"
	arm-none-eabi-size "Wys�anie_danego_tekstu_przez_UART.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
