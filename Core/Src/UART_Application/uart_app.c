/*
 * uart_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#include "uart_app.h"
#include "main_app.h"

//UART_HandleTypeDef *uart_Handle_Console;
extern UART_HandleTypeDef uart2_Handle;

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

//void APP_Initialize_UART_Handle_Console(UART_HandleTypeDef *uart_Handle){
//	uart_Handle_Console = uart_Handle;
//}


void APP_Print_Log_UART(char *message) {

	HAL_UART_Transmit(&uart2_Handle, (uint8_t*) message, (uint16_t)strlen(message), HAL_MAX_DELAY);
}



