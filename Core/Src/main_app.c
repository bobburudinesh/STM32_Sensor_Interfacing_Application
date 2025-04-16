/*
 * main_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */


#include <main_app.h>
#include "gpio_app.h"
void GPIO_Init(void);

int main(void) {
	HAL_Init();
	GPIO_LED_Onboard_Init();

	while(1) {
		HAL_Delay(1);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	}
	//return 0;
}
