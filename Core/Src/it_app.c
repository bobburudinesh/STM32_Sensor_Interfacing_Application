/*
 * it_app.c
 *
 *  Created on: Apr 17, 2025
 *      Author: Dinesh Bobburu
 */


#include "main_app.h"
#include "it_app.h"
#include "gpio_app.h"

extern UART_HandleTypeDef uart2_Handle;
extern TIM_HandleTypeDef tim6_handle;
extern TIM_HandleTypeDef tim2_handle;
extern RTC_HandleTypeDef rtc_handle;

void SysTick_Handler(void) {
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void) {
	HAL_UART_IRQHandler(&uart2_Handle);
}

void TIM6_DAC_IRQHandler(void) {
	//HAL_GPIO_WritePin(GPIOD, LED_BLUE_ON_BOARD, 0);
	HAL_GPIO_TogglePin(GPIOD, LED_BLUE_ON_BOARD);
	HAL_TIM_IRQHandler(&tim6_handle);
	//HAL_GPIO_WritePin(GPIOD, LED_BLUE_ON_BOARD, 1);
}

void TIM2_IRQHandler(void) {

	HAL_TIM_IRQHandler(&tim2_handle);

}

void RTC_WKUP_IRQHandler(void) {

}

