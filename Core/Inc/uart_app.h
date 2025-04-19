/*
 * uart_app.h
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#ifndef INC_UART_APPLICATION_HEADERS_UART_APP_H_
#define INC_UART_APPLICATION_HEADERS_UART_APP_H_

#include "gpio_app.h"
#include "main_app.h"
#include "stm32f4xx_hal_uart.h"


#define TRUE	1
#define FALSE	0



/*
 * UART Initialixation with default settings
 * */
void UART_Init_With_Handle(UART_HandleTypeDef *uart_Handle);
void APP_Initialize_UART_Handle_Console(UART_HandleTypeDef *uart_Handle);
void APP_Print_Log_UART(char *message);


#endif /* INC_UART_APPLICATION_HEADERS_UART_APP_H_ */
