################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode/example/CO_driver_blank.c \
../CANopenNode/example/CO_storageBlank.c \
../CANopenNode/example/OD.c \
../CANopenNode/example/main_blank.c 

C_DEPS += \
./CANopenNode/example/CO_driver_blank.d \
./CANopenNode/example/CO_storageBlank.d \
./CANopenNode/example/OD.d \
./CANopenNode/example/main_blank.d 

OBJS += \
./CANopenNode/example/CO_driver_blank.o \
./CANopenNode/example/CO_storageBlank.o \
./CANopenNode/example/OD.o \
./CANopenNode/example/main_blank.o 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode/example/%.o CANopenNode/example/%.su: ../CANopenNode/example/%.c CANopenNode/example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/personalfiles/Projects/NLS-IRM_v1/Core/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../CANopenNode/ -I../CANopenNode_STM32/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CANopenNode-2f-example

clean-CANopenNode-2f-example:
	-$(RM) ./CANopenNode/example/CO_driver_blank.d ./CANopenNode/example/CO_driver_blank.o ./CANopenNode/example/CO_driver_blank.su ./CANopenNode/example/CO_storageBlank.d ./CANopenNode/example/CO_storageBlank.o ./CANopenNode/example/CO_storageBlank.su ./CANopenNode/example/OD.d ./CANopenNode/example/OD.o ./CANopenNode/example/OD.su ./CANopenNode/example/main_blank.d ./CANopenNode/example/main_blank.o ./CANopenNode/example/main_blank.su

.PHONY: clean-CANopenNode-2f-example

