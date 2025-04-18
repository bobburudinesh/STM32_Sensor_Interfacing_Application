################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/UART_Application/uart_app.c 

OBJS += \
./Core/Src/UART_Application/uart_app.o 

C_DEPS += \
./Core/Src/UART_Application/uart_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/UART_Application/%.o Core/Src/UART_Application/%.su Core/Src/UART_Application/%.cyclo: ../Core/Src/UART_Application/%.c Core/Src/UART_Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-UART_Application

clean-Core-2f-Src-2f-UART_Application:
	-$(RM) ./Core/Src/UART_Application/uart_app.cyclo ./Core/Src/UART_Application/uart_app.d ./Core/Src/UART_Application/uart_app.o ./Core/Src/UART_Application/uart_app.su

.PHONY: clean-Core-2f-Src-2f-UART_Application

