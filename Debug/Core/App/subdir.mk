################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/App/Car.c \
../Core/App/Command.c \
../Core/App/HC_06_Bluetooth.c \
../Core/App/Ultrasonic.c 

OBJS += \
./Core/App/Car.o \
./Core/App/Command.o \
./Core/App/HC_06_Bluetooth.o \
./Core/App/Ultrasonic.o 

C_DEPS += \
./Core/App/Car.d \
./Core/App/Command.d \
./Core/App/HC_06_Bluetooth.d \
./Core/App/Ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
Core/App/%.o Core/App/%.su Core/App/%.cyclo: ../Core/App/%.c Core/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/01_Source_Git/STM32/ControlCarProjectSTM32/Core/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-App

clean-Core-2f-App:
	-$(RM) ./Core/App/Car.cyclo ./Core/App/Car.d ./Core/App/Car.o ./Core/App/Car.su ./Core/App/Command.cyclo ./Core/App/Command.d ./Core/App/Command.o ./Core/App/Command.su ./Core/App/HC_06_Bluetooth.cyclo ./Core/App/HC_06_Bluetooth.d ./Core/App/HC_06_Bluetooth.o ./Core/App/HC_06_Bluetooth.su ./Core/App/Ultrasonic.cyclo ./Core/App/Ultrasonic.d ./Core/App/Ultrasonic.o ./Core/App/Ultrasonic.su

.PHONY: clean-Core-2f-App

