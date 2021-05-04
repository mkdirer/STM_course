################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f103xb.s 

OBJS += \
./startup/startup_stm32f103xb.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/HAL_Driver/Inc/Legacy" -I"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/Utilities/STM32F1xx_Nucleo" -I"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/inc" -I"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/CMSIS/device" -I"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/CMSIS/core" -I"C:/Users/Lukas/workspace/Hal_4.2_Zapalanie_kolejno_diod/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


