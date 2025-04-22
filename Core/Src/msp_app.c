/*
 * msp_app.c
 *
 *  Created on: Apr 17, 2025
 *      Author: Dinesh Bobburu
 */


#include "stm32f4xx_hal.h"
#include "gpio_app.h"


void HAL_MspInit(void) {
	// Set priority grouping
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	// Enable required system exceptions

	SCB->SHCSR |= 0x7 << 16;

	// configure priority for system exceptions

	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}


void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
	// DO low level initializations of UART2 peripheral.
	__HAL_RCC_USART2_CLK_ENABLE(); // Enable clock for UART2 Peripheral
	GPIO_UART2_Init(); // MAke GPIO pin muxing configurations
	HAL_NVIC_EnableIRQ(USART2_IRQn); // Enable IRQ
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0); // set priority for IRQ

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim) {
	__HAL_RCC_TIM6_CLK_ENABLE();
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0);
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim) {
	__HAL_RCC_TIM2_CLK_ENABLE();

	APP_GPIO_TIM2_CH1_Init();

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_NVIC_SetPriority(TIM2_IRQn, 14, 0);
}

void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim) {
	__HAL_RCC_TIM2_CLK_ENABLE();

	APP_GPIO_TIM2_OC_CH1_To_4_Init();
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_NVIC_SetPriority(TIM2_IRQn, 14, 0);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim) {
	__HAL_RCC_TIM2_CLK_ENABLE();

	APP_GPIO_TIM2_PWM_CH1_To_4_Init();
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_NVIC_SetPriority(TIM2_IRQn, 14, 0);
}


