################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/aio.c \
../src/encoder.c \
../src/io.c \
../src/main.c \
../src/nvic.c \
../src/rcc.c \
../src/rs232.c \
../src/runtime.c \
../src/stepdir.c \
../src/syscalls.c \
../src/system_stm32f30x.c \
../src/usb.c 

OBJS += \
./src/aio.o \
./src/encoder.o \
./src/io.o \
./src/main.o \
./src/nvic.o \
./src/rcc.o \
./src/rs232.o \
./src/runtime.o \
./src/stepdir.o \
./src/syscalls.o \
./src/system_stm32f30x.o \
./src/usb.o 

C_DEPS += \
./src/aio.d \
./src/encoder.d \
./src/io.d \
./src/main.d \
./src/nvic.d \
./src/rcc.d \
./src/rs232.d \
./src/runtime.d \
./src/stepdir.d \
./src/syscalls.d \
./src/system_stm32f30x.d \
./src/usb.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -DSTM32F30 -DSTM32F3 -DSTM32F303RDTx -DSTM32 -DUSE_STDPERIPH_DRIVER -DSTM32F303xE -I"C:/workspace1/projekt1/inc" -I"C:/workspace1/projekt1/CMSIS/core" -I"C:/workspace1/projekt1/CMSIS/device" -I"C:/workspace1/projekt1/StdPeriph_Driver/inc" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


