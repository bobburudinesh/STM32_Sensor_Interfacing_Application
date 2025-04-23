################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/RTC_Application/rtc_app.c 

OBJS += \
./Core/Src/RTC_Application/rtc_app.o 

C_DEPS += \
./Core/Src/RTC_Application/rtc_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/RTC_Application/%.o Core/Src/RTC_Application/%.su Core/Src/RTC_Application/%.cyclo: ../Core/Src/RTC_Application/%.c Core/Src/RTC_Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-RTC_Application

clean-Core-2f-Src-2f-RTC_Application:
	-$(RM) ./Core/Src/RTC_Application/rtc_app.cyclo ./Core/Src/RTC_Application/rtc_app.d ./Core/Src/RTC_Application/rtc_app.o ./Core/Src/RTC_Application/rtc_app.su

.PHONY: clean-Core-2f-Src-2f-RTC_Application

