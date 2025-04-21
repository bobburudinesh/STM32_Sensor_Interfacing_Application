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

void APP_Timer2_IC_Init(TIM_HandleTypeDef *htim){
	TIM_IC_InitTypeDef	tim2_IC_Config;
	HAL_StatusTypeDef status;
	htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	htim->Init.Prescaler = 1;
	htim->Init.Period = 0xFFFFFFFF;

	if((status = HAL_TIM_IC_Init(htim)) != HAL_OK) {
		APP_Handle_Error(status);
	}

	tim2_IC_Config.ICFilter = 0;
	tim2_IC_Config.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	tim2_IC_Config.ICPrescaler = TIM_ICPSC_DIV1;
	tim2_IC_Config.ICSelection = TIM_ICSELECTION_DIRECTTI;

	if((status = HAL_TIM_IC_ConfigChannel(htim, &tim2_IC_Config, TIM_CHANNEL_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}
}


