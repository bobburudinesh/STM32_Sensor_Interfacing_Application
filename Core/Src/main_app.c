/*
 * main_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#include <string.h>
#include <main_app.h>
#include "gpio_app.h"
#include "uart_app.h"
#include "clock_app.h"
#include "timer_app.h"

void Error_Handler(void);
void SystemClock_Config(void);


UART_HandleTypeDef	uart2_Handle = {
		.Instance = USART2
};

TIM_HandleTypeDef tim6_handle = {
		.Instance = TIM6,
};

char *sendMessage = "Application Running\r\n";
uint8_t receivedData;
char receivedCmd[100];
uint32_t receivedCmd_Count = 0;
uint8_t uart2_receive_cmplt = FALSE;
HAL_StatusTypeDef status;


int main(void) {
	HAL_Init();

	App_Clock_Init_From_PLL(clock_32Mhz, 1, 1, 1);
	GPIO_LED_Onboard_Init();
	__HAL_RCC_USART2_CLK_ENABLE();
	UART_Init_With_Handle(&uart2_Handle);
	APP_Print_Clock_Log_UART();
	APP_Timer6_Init(&tim6_handle);
	HAL_TIM_Base_Start_IT(&tim6_handle);
	HAL_UART_Transmit(&uart2_Handle, (uint8_t*) sendMessage, (uint16_t)strlen(sendMessage), HAL_MAX_DELAY);
	while(1) {
		//HAL_UART_Receive_IT(&uart2_Handle, &receivedData, 1);
		HAL_GPIO_TogglePin(GPIOD, LED_GREEN_ON_BOARD);
	}

	return 0;
}

void Error_Handler(void) {
	while(1);
}

void APP_Handle_Error(HAL_StatusTypeDef status) {
	while(1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(receivedData == '\r') {
		//receivedCmd[receivedCmd_Count++] = receivedData;

		uart2_receive_cmplt = TRUE;
		HAL_UART_Transmit(&uart2_Handle, (uint8_t*) receivedCmd, (uint16_t)strlen(receivedCmd), HAL_MAX_DELAY);
		memset(receivedCmd, 0, receivedCmd_Count);
		receivedCmd_Count = 0;
	} else {
		receivedCmd[receivedCmd_Count++] = receivedData;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_GPIO_TogglePin(GPIOD, LED_ORANGE_ON_BOARD);
}
