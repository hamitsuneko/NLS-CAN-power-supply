################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode_STM32/CO_app_STM32.c \
../CANopenNode_STM32/CO_driver_STM32.c \
../CANopenNode_STM32/OD.c 

C_DEPS += \
./CANopenNode_STM32/CO_app_STM32.d \
./CANopenNode_STM32/CO_driver_STM32.d \
./CANopenNode_STM32/OD.d 

OBJS += \
./CANopenNode_STM32/CO_app_STM32.o \
./CANopenNode_STM32/CO_driver_STM32.o \
./CANopenNode_STM32/OD.o 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode_STM32/%.o CANopenNode_STM32/%.su: ../CANopenNode_STM32/%.c CANopenNode_STM32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/personalfiles/Projects/NLS-IRM_v1/OneWire" -I"C:/personalfiles/Projects/NLS-IRM_v1/DS18B20" -I"C:/personalfiles/Projects/NLS-IRM_v1/Core/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../CANopenNode/ -I../CANopenNode_STM32/ -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CANopenNode_STM32

clean-CANopenNode_STM32:
	-$(RM) ./CANopenNode_STM32/CO_app_STM32.d ./CANopenNode_STM32/CO_app_STM32.o ./CANopenNode_STM32/CO_app_STM32.su ./CANopenNode_STM32/CO_driver_STM32.d ./CANopenNode_STM32/CO_driver_STM32.o ./CANopenNode_STM32/CO_driver_STM32.su ./CANopenNode_STM32/OD.d ./CANopenNode_STM32/OD.o ./CANopenNode_STM32/OD.su

.PHONY: clean-CANopenNode_STM32

