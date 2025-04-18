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
HAL_StatusTypeDef UART_Init_With_Handle(UART_HandleTypeDef *uart_Handle);



#endif /* INC_UART_APPLICATION_HEADERS_UART_APP_H_ */
