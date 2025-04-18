/*
 * gpio_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#include "gpio_app.h"

void GPIO_Init(void) {
	/* TODO: instead of void accept a custom enum, which have pin descriptions having default values. Also accept second parameter \
	Which gives provision for changing the default settings if user want.
	*/

	// Delegate Clock initialization step in this function to GPIO_Clock_Init() function.
}

void GPIO_LED_Onboard_Init(void) {
	__HAL_RCC_GPIOD_CLK_ENABLE();
		GPIO_InitTypeDef	*gpio_Init = {0};
		gpio_Init->Pin = LED_ORANGE_ON_BOARD | LED_BLUE_ON_BOARD | LED_GREEN_ON_BOARD | LED_RED_ON_BOARD;
		gpio_Init->Mode = GPIO_MODE_OUTPUT_PP;
		gpio_Init->Pull = GPIO_NOPULL;
		gpio_Init->Speed = GPIO_SPEED_LOW;

		HAL_GPIO_Init(GPIOD, gpio_Init);
}

void GPIO_Clock_Init(GPIO_TypeDef **gpioX) {
	/*
	 * TODO: Now check if clock is enables for above ports and enable if it is not enabled.
	 * */
}

void GPIO_UART2_Init(void) {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef	gpio;
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = UART2_TX | UART2_RX;
	gpio.Alternate = GPIO_AF7_USART2;
	gpio.Pull = GPIO_PULLUP;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio);

}


