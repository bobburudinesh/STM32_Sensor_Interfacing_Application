/*
 * gpio_app.h
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#ifndef INC_GPIO_APP_H_
#define INC_GPIO_APP_H_
#include "main_app.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_gpio_ex.h"

/*
 * Peripheral port definitions
 * */
#define LED_PORT	GPIOD
#define UART2_PORT	GPIOA

/*
 * GPIO Port A Pin Definitions
 * */

#define UART2_TX	GPIO_PIN_2
#define UART2_RX	GPIO_PIN_3

/*
 * GPIO Port D Pin Definitions
 * */
#define LED_GREEN_ON_BOARD	GPIO_PIN_12
#define LED_ORANGE_ON_BOARD	GPIO_PIN_13
#define LED_RED_ON_BOARD	GPIO_PIN_14
#define LED_BLUE_ON_BOARD	GPIO_PIN_15



/*
 * Methods
 * */
void GPIO_Init(void);
void GPIO_LED_Onboard_Init(void);
void GPIO_Clock_Init(GPIO_TypeDef **gpioX);

void GPIO_UART2_Init(void);
#endif /* INC_GPIO_APP_H_ */
