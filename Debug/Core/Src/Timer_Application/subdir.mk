################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Timer_Application/timer_app.c 

OBJS += \
./Core/Src/Timer_Application/timer_app.o 

C_DEPS += \
./Core/Src/Timer_Application/timer_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Timer_Application/%.o Core/Src/Timer_Application/%.su Core/Src/Timer_Application/%.cyclo: ../Core/Src/Timer_Application/%.c Core/Src/Timer_Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Timer_Application

clean-Core-2f-Src-2f-Timer_Application:
	-$(RM) ./Core/Src/Timer_Application/timer_app.cyclo ./Core/Src/Timer_Application/timer_app.d ./Core/Src/Timer_Application/timer_app.o ./Core/Src/Timer_Application/timer_app.su

.PHONY: clean-Core-2f-Src-2f-Timer_Application

