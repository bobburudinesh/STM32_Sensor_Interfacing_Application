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



void APP_Handle_Error(HAL_StatusTypeDef status);

UART_HandleTypeDef	uart2_Handle = {
		.Instance = USART2
};

char *sendMessage = "Application Running \r\n";
uint8_t receivedData;
char receivedCmd[100];
uint32_t receivedCmd_Count = 0;
uint8_t uart2_receive_cmplt = FALSE;
HAL_StatusTypeDef status;
int main(void) {
	HAL_Init();
	GPIO_LED_Onboard_Init();
	if((status = UART_Init_With_Handle(&uart2_Handle)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	HAL_UART_Transmit(&uart2_Handle, (uint8_t*) sendMessage, (uint16_t)strlen(sendMessage), HAL_MAX_DELAY);
	while(!uart2_receive_cmplt) {
		HAL_UART_Receive_IT(&uart2_Handle, &receivedData, 1);
	}

	while(1);

	return 0;
}

void APP_Handle_Error(HAL_StatusTypeDef status) {
	while(1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(receivedData == '\r') {
		receivedCmd[receivedCmd_Count++] = receivedData;
		receivedCmd_Count = 0;
		uart2_receive_cmplt = TRUE;
		HAL_UART_Transmit(&uart2_Handle, (uint8_t*) receivedCmd, (uint16_t)strlen(receivedCmd), HAL_MAX_DELAY);
	} else {
		receivedCmd[receivedCmd_Count++] = receivedData;
	}
}
