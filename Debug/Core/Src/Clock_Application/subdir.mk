################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Clock_Application/clock_app.c 

OBJS += \
./Core/Src/Clock_Application/clock_app.o 

C_DEPS += \
./Core/Src/Clock_Application/clock_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Clock_Application/%.o Core/Src/Clock_Application/%.su Core/Src/Clock_Application/%.cyclo: ../Core/Src/Clock_Application/%.c Core/Src/Clock_Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Clock_Application

clean-Core-2f-Src-2f-Clock_Application:
	-$(RM) ./Core/Src/Clock_Application/clock_app.cyclo ./Core/Src/Clock_Application/clock_app.d ./Core/Src/Clock_Application/clock_app.o ./Core/Src/Clock_Application/clock_app.su

.PHONY: clean-Core-2f-Src-2f-Clock_Application

