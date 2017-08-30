################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Src/Assembly.s 

C_SRCS += \
../Src/main.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c \
../Src/task.c 

OBJS += \
./Src/Assembly.o \
./Src/main.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o \
./Src/task.o 

C_DEPS += \
./Src/main.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d \
./Src/task.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:/ChromeDownloads/RTOS/Blinky/Inc" -I"D:/ChromeDownloads/RTOS/Blinky/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/ChromeDownloads/RTOS/Blinky/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"D:/ChromeDownloads/RTOS/Blinky/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/ChromeDownloads/RTOS/Blinky/Drivers/CMSIS/Include" -I"D:/ChromeDownloads/RTOS/Blinky/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


