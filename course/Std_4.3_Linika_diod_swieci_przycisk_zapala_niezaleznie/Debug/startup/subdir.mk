################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup/startup_stm32f10x_md.S 

OBJS += \
./startup/startup_stm32f10x_md.o 

S_UPPER_DEPS += \
./startup/startup_stm32f10x_md.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DNUCLEO_F103RB -DDEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"C:/Users/Lukas/workspace/4.3_Linika_diod_swieci_przycisk_zapala_niezaleznie/StdPeriph_Driver/inc" -I"C:/Users/Lukas/workspace/4.3_Linika_diod_swieci_przycisk_zapala_niezaleznie/inc" -I"C:/Users/Lukas/workspace/4.3_Linika_diod_swieci_przycisk_zapala_niezaleznie/CMSIS/device" -I"C:/Users/Lukas/workspace/4.3_Linika_diod_swieci_przycisk_zapala_niezaleznie/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


