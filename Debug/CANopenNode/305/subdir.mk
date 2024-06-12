################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode/305/CO_LSSmaster.c \
../CANopenNode/305/CO_LSSslave.c 

C_DEPS += \
./CANopenNode/305/CO_LSSmaster.d \
./CANopenNode/305/CO_LSSslave.d 

OBJS += \
./CANopenNode/305/CO_LSSmaster.o \
./CANopenNode/305/CO_LSSslave.o 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode/305/%.o CANopenNode/305/%.su: ../CANopenNode/305/%.c CANopenNode/305/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/personalfiles/Projects/NLS-IRM_v1/OneWire" -I"C:/personalfiles/Projects/NLS-IRM_v1/DS18B20" -I"C:/personalfiles/Projects/NLS-IRM_v1/Core/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../CANopenNode/ -I../CANopenNode_STM32/ -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CANopenNode-2f-305

clean-CANopenNode-2f-305:
	-$(RM) ./CANopenNode/305/CO_LSSmaster.d ./CANopenNode/305/CO_LSSmaster.o ./CANopenNode/305/CO_LSSmaster.su ./CANopenNode/305/CO_LSSslave.d ./CANopenNode/305/CO_LSSslave.o ./CANopenNode/305/CO_LSSslave.su

.PHONY: clean-CANopenNode-2f-305

