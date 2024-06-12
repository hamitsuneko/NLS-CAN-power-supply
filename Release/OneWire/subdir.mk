################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OneWire/onewire.c 

C_DEPS += \
./OneWire/onewire.d 

OBJS += \
./OneWire/onewire.o 


# Each subdirectory must supply rules for building sources it contributes
OneWire/%.o OneWire/%.su: ../OneWire/%.c OneWire/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/personalfiles/Projects/NLS-IRM_v1/CANopenNode" -I"C:/personalfiles/Projects/NLS-IRM_v1/CANopenNode_STM32" -I"C:/personalfiles/Projects/NLS-IRM_v1/DS18B20" -I"C:/personalfiles/Projects/NLS-IRM_v1/OneWire" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-OneWire

clean-OneWire:
	-$(RM) ./OneWire/onewire.d ./OneWire/onewire.o ./OneWire/onewire.su

.PHONY: clean-OneWire

