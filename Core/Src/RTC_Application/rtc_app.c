/*
 * rtc_app.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Dinesh Bobburu
 */

#include "main_app.h"
#include "rtc_app.h"


void APP_RTC_Init(RTC_HandleTypeDef *rtc_handle) {
	HAL_StatusTypeDef status;
	rtc_handle->Init.HourFormat = RTC_HOURFORMAT_12;
	rtc_handle->Init.AsynchPrediv = 0x7F;
	rtc_handle->Init.SynchPrediv = 0xFF;
	rtc_handle->Init.OutPut = RTC_OUTPUT_DISABLE;
	rtc_handle->Init.OutPutPolarity = RTC_OUTPUT_POLARITY_LOW;
	rtc_handle->Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	if((status = HAL_RTC_Init(rtc_handle)) != HAL_OK) {
		APP_Handle_Error(status);
	}

}

void APP_RTC_Calender_Config(RTC_HandleTypeDef *rtc_handle) {
	HAL_StatusTypeDef status;
	RTC_TimeTypeDef	rtc_Time_Init;
	RTC_DateTypeDef rtc_Date_Init;

	rtc_Time_Init.Hours = 10;
	rtc_Time_Init.Minutes = 42;
	rtc_Time_Init.Seconds = 0;
	rtc_Time_Init.TimeFormat = RTC_HOURFORMAT12_PM;

	if((status = HAL_RTC_SetTime(rtc_handle, &rtc_Time_Init, RTC_FORMAT_BIN)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	rtc_Date_Init.Date = 22;
	rtc_Date_Init.Month = RTC_MONTH_APRIL;
	rtc_Date_Init.WeekDay = RTC_WEEKDAY_TUESDAY;
	rtc_Date_Init.Year = 25;

	if((status = HAL_RTC_SetDate(rtc_handle, &rtc_Date_Init, RTC_FORMAT_BIN)) != HAL_OK) {
		APP_Handle_Error(status);
	}


}
