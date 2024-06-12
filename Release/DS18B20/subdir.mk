################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DS18B20/ds18b20.c 

C_DEPS += \
./DS18B20/ds18b20.d 

OBJS += \
./DS18B20/ds18b20.o 


# Each subdirectory must supply rules for building sources it contributes
DS18B20/%.o DS18B20/%.su: ../DS18B20/%.c DS18B20/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/personalfiles/Projects/NLS-IRM_v1/CANopenNode" -I"C:/personalfiles/Projects/NLS-IRM_v1/CANopenNode_STM32" -I"C:/personalfiles/Projects/NLS-IRM_v1/DS18B20" -I"C:/personalfiles/Projects/NLS-IRM_v1/OneWire" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DS18B20

clean-DS18B20:
	-$(RM) ./DS18B20/ds18b20.d ./DS18B20/ds18b20.o ./DS18B20/ds18b20.su

.PHONY: clean-DS18B20

