################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BOTterfly-C/asserv.c \
../Core/Src/BOTterfly-C/encoder.c \
../Core/Src/BOTterfly-C/motor.c \
../Core/Src/BOTterfly-C/odo.c \
../Core/Src/BOTterfly-C/shell.c 

OBJS += \
./Core/Src/BOTterfly-C/asserv.o \
./Core/Src/BOTterfly-C/encoder.o \
./Core/Src/BOTterfly-C/motor.o \
./Core/Src/BOTterfly-C/odo.o \
./Core/Src/BOTterfly-C/shell.o 

C_DEPS += \
./Core/Src/BOTterfly-C/asserv.d \
./Core/Src/BOTterfly-C/encoder.d \
./Core/Src/BOTterfly-C/motor.d \
./Core/Src/BOTterfly-C/odo.d \
./Core/Src/BOTterfly-C/shell.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BOTterfly-C/%.o: ../Core/Src/BOTterfly-C/%.c Core/Src/BOTterfly-C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

