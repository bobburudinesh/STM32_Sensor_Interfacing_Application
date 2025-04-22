/*
 * timer_app.c
 *
 *  Created on: Apr 20, 2025
 *      Author: Dinesh Bobburu
 */

#include "main_app.h"
#include "timer_app.h"

extern TIM_HandleTypeDef tim6_handle;

const uint32_t pulse1_value_500Hz = 25000; // For Tim 2 OC 1 to produce 500Hz waveform
const uint32_t pulse2_value_1KHz = 12500; // For Tim 2 OC 1 to produce 500Hz waveform
const uint32_t pulse3_value_2KHz = 6250; // For Tim 2 OC 1 to produce 500Hz waveform
const uint32_t pulse4_value_4KHz = 3125; // For Tim 2 OC 1 to produce 500Hz waveform

void APP_Timer6_Init(TIM_HandleTypeDef *htim){
	HAL_StatusTypeDef status;
	htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	htim->Init.Prescaler = 9;
	htim->Init.Period = 50-1;
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
	tim2_IC_Config.ICPolarity = TIM_ICPOLARITY_RISING;
	tim2_IC_Config.ICPrescaler = TIM_ICPSC_DIV1;
	tim2_IC_Config.ICSelection = TIM_ICSELECTION_DIRECTTI;

	if((status = HAL_TIM_IC_ConfigChannel(htim, &tim2_IC_Config, TIM_CHANNEL_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}
}


void APP_Timer2_OC_Init(TIM_HandleTypeDef *htim){
	TIM_OC_InitTypeDef	tim2_OC_Config;
	HAL_StatusTypeDef status;
	htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	htim->Init.Prescaler = 1;
	htim->Init.Period = 0xFFFFFFFF;


	if((status = HAL_TIM_OC_Init(htim)) != HAL_OK) {
		APP_Handle_Error(status);
	}

	tim2_OC_Config.OCMode = TIM_OCMODE_TOGGLE;
	tim2_OC_Config.OCNPolarity = TIM_OCPOLARITY_HIGH;
	tim2_OC_Config.Pulse = pulse1_value_500Hz;

	if((status = HAL_TIM_OC_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	tim2_OC_Config.Pulse = pulse2_value_1KHz;

	if((status = HAL_TIM_OC_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_2)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	tim2_OC_Config.Pulse = pulse3_value_2KHz;

	if((status = HAL_TIM_OC_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_3)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	tim2_OC_Config.Pulse = pulse4_value_4KHz;

	if((status = HAL_TIM_OC_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_4)) != HAL_OK) {
		APP_Handle_Error(status);
	}
}


void APP_Timer2_PWM_Init(TIM_HandleTypeDef *htim){
	TIM_OC_InitTypeDef	tim2_OC_Config;
	HAL_StatusTypeDef status;
	htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	htim->Init.Prescaler = 1;
	htim->Init.Period = 25000-1;


	if((status = HAL_TIM_PWM_Init(htim)) != HAL_OK) {
		APP_Handle_Error(status);
	}

	tim2_OC_Config.OCMode = TIM_OCMODE_PWM1;
	tim2_OC_Config.OCNPolarity = TIM_OCPOLARITY_HIGH;
	tim2_OC_Config.Pulse = 0.25*(htim->Init.Period);

	if((status = HAL_TIM_PWM_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	tim2_OC_Config.Pulse = 0.45*(htim->Init.Period);

	if((status = HAL_TIM_PWM_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_2)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	tim2_OC_Config.Pulse = 0.75*(htim->Init.Period);

	if((status = HAL_TIM_PWM_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_3)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	tim2_OC_Config.Pulse = 0.95*(htim->Init.Period);

	if((status = HAL_TIM_PWM_ConfigChannel(htim, &tim2_OC_Config, TIM_CHANNEL_4)) != HAL_OK) {
		APP_Handle_Error(status);
	}
}
