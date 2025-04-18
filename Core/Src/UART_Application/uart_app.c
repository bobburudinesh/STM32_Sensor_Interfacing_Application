/*
 * uart_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#include "uart_app.h"

HAL_StatusTypeDef UART_Init_With_Handle(UART_HandleTypeDef *uart_Handle) {
	UART_InitTypeDef uart2_Init;
	uart2_Init.BaudRate = 115200;
	uart2_Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart2_Init.Mode = UART_MODE_TX_RX;
	uart2_Init.Parity = UART_PARITY_NONE;
	uart2_Init.StopBits = UART_STOPBITS_1;
	uart2_Init.WordLength = UART_WORDLENGTH_8B;
	uart_Handle->Init = uart2_Init;

	return HAL_UART_Init(uart_Handle);


}



