/*
 * gpio_app.h
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#ifndef INC_GPIO_APP_H_
#define INC_GPIO_APP_H_
#include "main_app.h"

/*
 * Peripheral port definitions
 * */
#define LED_PORT	GPIOD

/*
 * GPIO D Pin Definitions
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
#endif /* INC_GPIO_APP_H_ */
