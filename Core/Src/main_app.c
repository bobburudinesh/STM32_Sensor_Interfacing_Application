/*
 * main_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */


#include <main_app.h>
#include "gpio_app.h"
#include "uart_app.h"

void APP_Handle_Error(HAL_StatusTypeDef status);

UART_HandleTypeDef	uart2_Handle = {
		.Instance = USART2
};
HAL_StatusTypeDef status;
int main(void) {
	HAL_Init();
	GPIO_LED_Onboard_Init();
	if((status = UART_Init_With_Handle(&uart2_Handle)) != HAL_OK) {

	}
	while(1) {
		HAL_Delay(1);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	}

	//return 0;
}

void APP_Handle_Error(HAL_StatusTypeDef status) {
	while(1);
}
