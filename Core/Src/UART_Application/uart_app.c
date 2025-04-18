/*
 * uart_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#include "uart_app.h"
#include "main_app.h"

void UART_Init_With_Handle(UART_HandleTypeDef *uart_Handle) {
	UART_InitTypeDef uart2_Init;
	HAL_StatusTypeDef status;
	uart2_Init.BaudRate = 115200;
	uart2_Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart2_Init.Mode = UART_MODE_TX_RX;
	uart2_Init.Parity = UART_PARITY_NONE;
	uart2_Init.StopBits = UART_STOPBITS_1;
	uart2_Init.WordLength = UART_WORDLENGTH_8B;
	uart_Handle->Init = uart2_Init;
	status = HAL_UART_Init(uart_Handle);
	if(status != HAL_OK) {
		APP_Handle_Error(status);
	}


}



