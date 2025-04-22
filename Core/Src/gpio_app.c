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
		GPIO_InitTypeDef	gpio_Init;
		gpio_Init.Pin = LED_ORANGE_ON_BOARD | LED_BLUE_ON_BOARD | LED_GREEN_ON_BOARD | LED_RED_ON_BOARD;
		gpio_Init.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_Init.Pull = GPIO_NOPULL;
		gpio_Init.Speed = GPIO_SPEED_LOW;

		HAL_GPIO_Init(GPIOD, &gpio_Init);
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


void APP_GPIO_TIM2_CH1_Init(void) {
	/*
	* CH1 -> PA0
	*/
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef	gpio_tim2;
	gpio_tim2.Mode = GPIO_MODE_AF_PP;
	//gpio_tim2.Pull = GPIO_PULLDOWN;
	gpio_tim2.Alternate = GPIO_AF1_TIM2;
	gpio_tim2.Pin = TIM2_CH1;
	HAL_GPIO_Init(GPIOA, &gpio_tim2);
}

void APP_GPIO_TIM2_OC_CH1_To_4_Init(void) {
	/*
	 * CH1 -> PA0
	 * CH2 -> PA1
	 * CH3 -> PB10
	 * CH4 -> PB11
	 * */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef	gpio_tim2;
	gpio_tim2.Mode = GPIO_MODE_AF_PP;
	gpio_tim2.Pull = GPIO_NOPULL;
	gpio_tim2.Alternate = GPIO_AF1_TIM2;
	gpio_tim2.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_tim2.Pin = TIM2_CH1 | TIM2_CH2;
	HAL_GPIO_Init(GPIOA, &gpio_tim2);

	gpio_tim2.Pin = TIM2_CH3 | TIM2_CH4;
	HAL_GPIO_Init(GPIOB, &gpio_tim2);
}

void APP_GPIO_TIM2_PWM_CH1_To_4_Init(void) {
	/*
	 * CH1 -> PA0
	 * CH2 -> PA1
	 * CH3 -> PB10
	 * CH4 -> PB11
	 * */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef	gpio_tim2;
	gpio_tim2.Mode = GPIO_MODE_AF_PP;
	gpio_tim2.Pull = GPIO_PULLDOWN;
	gpio_tim2.Alternate = GPIO_AF1_TIM2;
	gpio_tim2.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_tim2.Pin = TIM2_CH1 | TIM2_CH2;
	HAL_GPIO_Init(GPIOA, &gpio_tim2);

	gpio_tim2.Pin = TIM2_CH3 | TIM2_CH4;
	HAL_GPIO_Init(GPIOB, &gpio_tim2);
}
