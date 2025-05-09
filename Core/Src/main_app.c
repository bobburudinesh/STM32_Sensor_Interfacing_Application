/*
 * main_app.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Dinesh Bobburu
 */

#include <string.h>
#include <main_app.h>
#include "gpio_app.h"
#include "uart_app.h"
#include "clock_app.h"
#include "timer_app.h"

extern uint32_t pulse1_value_500Hz;
extern uint32_t pulse2_value_1KHz;
extern uint32_t pulse3_value_2KHz;
extern uint32_t pulse4_value_4KHz;

void Error_Handler(void);
void SystemClock_Config(void);
static void Compute_User_Signal_Frequency_Fron_Tim2_IC(void);

UART_HandleTypeDef	uart2_Handle = {
		.Instance = USART2
};

TIM_HandleTypeDef tim6_handle = {
		.Instance = TIM6,
};

TIM_HandleTypeDef tim2_handle = {
		.Instance = TIM2,
};



char *sendMessage = "Application Running\r\n";
uint8_t receivedData;
char receivedCmd[100];
uint32_t receivedCmd_Count = 0;
uint8_t uart2_receive_cmplt = FALSE;

uint32_t tim2_IC_Values[2];
uint8_t tim2_IC_count = 1;
uint32_t tim2_capture_diff = 0;
uint8_t tim2_IC_Completed = FALSE;
double tim2_count_freq = 0;
double tim2_count_resolution = 0;
double user_signal_time_period = 0;
double user_signal_frequency = 0;
uint32_t current_OC_value = 0;
HAL_StatusTypeDef status;
char print_Message[100];

int main(void) {
	HAL_Init();

	App_Clock_Init_From_PLL(clock_50Mhz, 1, 1, 1);
	APP_HSI_Clock_Init_On_MCO1();
	GPIO_LED_Onboard_Init();
	__HAL_RCC_USART2_CLK_ENABLE();
	UART_Init_With_Handle(&uart2_Handle);

	APP_Print_Clock_Log_UART();

	//APP_Timer6_Init(&tim6_handle);
	//APP_Timer2_IC_Init(&tim2_handle);
	//HAL_TIM_Base_Start_IT(&tim6_handle);
	//HAL_TIM_IC_Start_IT(&tim2_handle, TIM_CHANNEL_1);

	// Code Start for Clock generation from 4 output channels of Timer 2, of frequency 500Hz, 1KHz, 2KHz, 4KHz
	/*APP_Timer2_OC_Init(&tim2_handle);
	if((status = HAL_TIM_OC_Start_IT(&tim2_handle, TIM_CHANNEL_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_TIM_OC_Start_IT(&tim2_handle, TIM_CHANNEL_2)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_TIM_OC_Start_IT(&tim2_handle, TIM_CHANNEL_3)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_TIM_OC_Start_IT(&tim2_handle, TIM_CHANNEL_4)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	*/
	// Code Start for Clock generation from 4 output channels of Timer 2, of frequency 500Hz, 1KHz, 2KHz, 4KHz

	// Code Start for PWM generation from 4 output channels of Timer 2, of 25%, 45%, 75%, 95%
	APP_Timer2_PWM_Init(&tim2_handle);
	if((status = HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_2)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_3)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_4)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	// Code End for PWM generation from 4 output channels of Timer 2, of 25%, 45%, 75%, 95%


	HAL_UART_Transmit(&uart2_Handle, (uint8_t*) sendMessage, (uint16_t)strlen(sendMessage), HAL_MAX_DELAY);
	while(1) {
		//HAL_UART_Receive_IT(&uart2_Handle, &receivedData, 1);
		//HAL_GPIO_TogglePin(GPIOD, LED_GREEN_ON_BOARD);
//		if(tim2_IC_Completed) {
//
//			Compute_User_Signal_Frequency_Fron_Tim2_IC();
//		}
	}

	return 0;
}

void Error_Handler(void) {
	while(1);
}

void APP_Handle_Error(HAL_StatusTypeDef status) {
	while(1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(receivedData == '\r') {
		//receivedCmd[receivedCmd_Count++] = receivedData;

		uart2_receive_cmplt = TRUE;
		HAL_UART_Transmit(&uart2_Handle, (uint8_t*) receivedCmd, (uint16_t)strlen(receivedCmd), HAL_MAX_DELAY);
		memset(receivedCmd, 0, receivedCmd_Count);
		receivedCmd_Count = 0;
	} else {
		receivedCmd[receivedCmd_Count++] = receivedData;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_GPIO_TogglePin(GPIOD, LED_ORANGE_ON_BOARD);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {

	if(tim2_IC_count == 1) {
		tim2_IC_Values[0] = __HAL_TIM_GET_COMPARE(htim, TIM_CHANNEL_1);
		tim2_IC_count++;
	} if(tim2_IC_count == 2) {
		tim2_IC_Values[1] = __HAL_TIM_GET_COMPARE(htim, TIM_CHANNEL_1);
		tim2_IC_count = 1;
		tim2_IC_Completed = TRUE;
	}
}

static void Compute_User_Signal_Frequency_Fron_Tim2_IC(void) {
	if(tim2_IC_Values[1] > tim2_IC_Values[0]) {
					tim2_capture_diff = tim2_IC_Values[1] - tim2_IC_Values[0];
				} else {
					tim2_capture_diff = (0xFFFFFFFF  - tim2_IC_Values[0]) + tim2_IC_Values[1];
				}
				tim2_count_freq = APP_CLock_GET_APB1_TIM_Freq()/(tim2_handle.Init.Prescaler + 1);
				tim2_count_resolution = 1/tim2_count_freq;
				user_signal_time_period = tim2_capture_diff * tim2_count_resolution;
				user_signal_frequency = 1/user_signal_time_period;
				memset(&print_Message, 0, sizeof(print_Message));
				sprintf(print_Message,"IC Difference: %lu,cnt_freq: %f,usr_tim:%f User Signal Frequency: %f\r\n",tim2_capture_diff,tim2_count_freq,user_signal_time_period, user_signal_frequency );
				APP_Print_Log_UART(print_Message);
				tim2_IC_Completed = FALSE;
}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
		current_OC_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
		__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_1, current_OC_value + pulse1_value_500Hz);
	}
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {
		current_OC_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
		__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_2, current_OC_value + pulse2_value_1KHz);
	}
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {
		current_OC_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
		__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_3, current_OC_value + pulse3_value_2KHz);
	}
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4) {
		current_OC_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
		__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_4, current_OC_value + pulse4_value_4KHz);
	}
}
