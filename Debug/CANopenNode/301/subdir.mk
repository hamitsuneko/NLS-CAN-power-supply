################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode/301/CO_Emergency.c \
../CANopenNode/301/CO_HBconsumer.c \
../CANopenNode/301/CO_NMT_Heartbeat.c \
../CANopenNode/301/CO_ODinterface.c \
../CANopenNode/301/CO_PDO.c \
../CANopenNode/301/CO_SDOclient.c \
../CANopenNode/301/CO_SDOserver.c \
../CANopenNode/301/CO_SYNC.c \
../CANopenNode/301/CO_TIME.c \
../CANopenNode/301/CO_fifo.c \
../CANopenNode/301/crc16-ccitt.c 

C_DEPS += \
./CANopenNode/301/CO_Emergency.d \
./CANopenNode/301/CO_HBconsumer.d \
./CANopenNode/301/CO_NMT_Heartbeat.d \
./CANopenNode/301/CO_ODinterface.d \
./CANopenNode/301/CO_PDO.d \
./CANopenNode/301/CO_SDOclient.d \
./CANopenNode/301/CO_SDOserver.d \
./CANopenNode/301/CO_SYNC.d \
./CANopenNode/301/CO_TIME.d \
./CANopenNode/301/CO_fifo.d \
./CANopenNode/301/crc16-ccitt.d 

OBJS += \
./CANopenNode/301/CO_Emergency.o \
./CANopenNode/301/CO_HBconsumer.o \
./CANopenNode/301/CO_NMT_Heartbeat.o \
./CANopenNode/301/CO_ODinterface.o \
./CANopenNode/301/CO_PDO.o \
./CANopenNode/301/CO_SDOclient.o \
./CANopenNode/301/CO_SDOserver.o \
./CANopenNode/301/CO_SYNC.o \
./CANopenNode/301/CO_TIME.o \
./CANopenNode/301/CO_fifo.o \
./CANopenNode/301/crc16-ccitt.o 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode/301/%.o CANopenNode/301/%.su: ../CANopenNode/301/%.c CANopenNode/301/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/personalfiles/Projects/NLS-IRM_v1/OneWire" -I"C:/personalfiles/Projects/NLS-IRM_v1/DS18B20" -I"C:/personalfiles/Projects/NLS-IRM_v1/Core/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../CANopenNode/ -I../CANopenNode_STM32/ -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CANopenNode-2f-301

clean-CANopenNode-2f-301:
	-$(RM) ./CANopenNode/301/CO_Emergency.d ./CANopenNode/301/CO_Emergency.o ./CANopenNode/301/CO_Emergency.su ./CANopenNode/301/CO_HBconsumer.d ./CANopenNode/301/CO_HBconsumer.o ./CANopenNode/301/CO_HBconsumer.su ./CANopenNode/301/CO_NMT_Heartbeat.d ./CANopenNode/301/CO_NMT_Heartbeat.o ./CANopenNode/301/CO_NMT_Heartbeat.su ./CANopenNode/301/CO_ODinterface.d ./CANopenNode/301/CO_ODinterface.o ./CANopenNode/301/CO_ODinterface.su ./CANopenNode/301/CO_PDO.d ./CANopenNode/301/CO_PDO.o ./CANopenNode/301/CO_PDO.su ./CANopenNode/301/CO_SDOclient.d ./CANopenNode/301/CO_SDOclient.o ./CANopenNode/301/CO_SDOclient.su ./CANopenNode/301/CO_SDOserver.d ./CANopenNode/301/CO_SDOserver.o ./CANopenNode/301/CO_SDOserver.su ./CANopenNode/301/CO_SYNC.d ./CANopenNode/301/CO_SYNC.o ./CANopenNode/301/CO_SYNC.su ./CANopenNode/301/CO_TIME.d ./CANopenNode/301/CO_TIME.o ./CANopenNode/301/CO_TIME.su ./CANopenNode/301/CO_fifo.d ./CANopenNode/301/CO_fifo.o ./CANopenNode/301/CO_fifo.su ./CANopenNode/301/crc16-ccitt.d ./CANopenNode/301/crc16-ccitt.o ./CANopenNode/301/crc16-ccitt.su

.PHONY: clean-CANopenNode-2f-301

