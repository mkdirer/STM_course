################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f1xx_it.c \
../src/syscalls.c \
../src/system_stm32f1xx.c 

OBJS += \
./src/main.o \
./src/stm32f1xx_it.o \
./src/syscalls.o \
./src/system_stm32f1xx.o 

C_DEPS += \
./src/main.d \
./src/stm32f1xx_it.d \
./src/syscalls.d \
./src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DNUCLEO_F103RB -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -I"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/HAL_Driver/Inc/Legacy" -I"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/Utilities/STM32F1xx_Nucleo" -I"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/inc" -I"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/CMSIS/device" -I"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/CMSIS/core" -I"C:/Users/Lukas/workspace/Hall_4.1_Zmiana_kierunku_diod_po_nacisnieciu_wykorzystanie_przerwan/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

