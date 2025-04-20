/*
 * timer_app.c
 *
 *  Created on: Apr 20, 2025
 *      Author: Dinesh Bobburu
 */

#include "main_app.h"
#include "timer_app.h"

extern TIM_HandleTypeDef tim6_handle;

void APP_Timer6_Init(TIM_HandleTypeDef *htim){
	HAL_StatusTypeDef status;
	htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	htim->Init.Prescaler = 49;
	htim->Init.Period = 64000-1;
	if((status = HAL_TIM_Base_Init(htim)) != HAL_OK) {
		APP_Handle_Error(status);
	}
}

