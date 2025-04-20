/*
 * clock_app.c
 *
 *  Created on: Apr 18, 2025
 *      Author: Dinesh Bobburu
 */


#include "main_app.h"
#include "clock_app.h"
#include "uart_app.h"



void App_Clock_Init_From_PLL(Clock_Frequency_Mhz clock_Frequency, uint32_t ahb_prescaler, uint32_t apb1_prescaler, uint32_t apb2_prescaler){
	HAL_StatusTypeDef status;
	RCC_OscInitTypeDef	osc_init = {0};
	RCC_ClkInitTypeDef clk_init = {0};
	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	osc_init.HSIState = RCC_HSI_ON;
	osc_init.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	osc_init.PLL.PLLState = RCC_PLL_ON;
	osc_init.PLL.PLLM = 16;  // keeping this factor 16 helps in getting VCO(voltage controlled oscillator) inout frequency between 1-2Mhz(this is strict requirement.)

	clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

	switch(clock_Frequency) {
	case clock_16Mhz:
		osc_init.PLL.PLLN = 64;
		osc_init.PLL.PLLP = 4;
		osc_init.PLL.PLLQ = 2;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
		break;
	case clock_32Mhz:
		osc_init.PLL.PLLN = 64;
		osc_init.PLL.PLLP = 2;
		osc_init.PLL.PLLQ = 2;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
		break;
	case clock_50Mhz:
		osc_init.PLL.PLLN = 100;
		osc_init.PLL.PLLP = 2;
		osc_init.PLL.PLLQ = 7;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
		break;
	case clock_84Mhz:
		osc_init.PLL.PLLN = 168;
		osc_init.PLL.PLLP = 2;
		osc_init.PLL.PLLQ = 4;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
		break;
	case clock_100Mhz:
		osc_init.PLL.PLLN = 200;
		osc_init.PLL.PLLP = 2;
		osc_init.PLL.PLLQ = 4;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV4;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
		break;
	case clock_120Mhz:
		osc_init.PLL.PLLN = 240;
		osc_init.PLL.PLLP = 2;
		osc_init.PLL.PLLQ = 4;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV4;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
		break;
	case clock_180Mhz:
		osc_init.PLL.PLLN = 360;
		osc_init.PLL.PLLP = 2;
		osc_init.PLL.PLLQ = 4;
		clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;
		clk_init.APB1CLKDivider = RCC_HCLK_DIV4;
		clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
		break;
	default:
		break;


	}

	if((status = HAL_RCC_OscConfig(&osc_init)) != HAL_OK) {
		APP_Handle_Error(status);
	}
	if((status = HAL_RCC_ClockConfig(&clk_init, FLASH_LATENCY_1)) != HAL_OK) {
		APP_Handle_Error(status);
	}



	HAL_SYSTICK_Config(HAL_RCC_GetSysClockFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);



}

void APP_Print_Clock_Log_UART(void) {
	char print_Message[100];
	memset(&print_Message, 0, sizeof(print_Message));
	sprintf(print_Message, "SYSCLK Freq: %ld\r\n",HAL_RCC_GetSysClockFreq());
	APP_Print_Log_UART(print_Message);

	memset(&print_Message, 0, sizeof(print_Message));
	sprintf(print_Message, "HCLK Freq: %ld\r\n",HAL_RCC_GetHCLKFreq());
	APP_Print_Log_UART(print_Message);

	memset(&print_Message, 0, sizeof(print_Message));
	sprintf(print_Message, "PCLK1 Freq: %ld\r\n",HAL_RCC_GetPCLK1Freq());
	APP_Print_Log_UART(print_Message);

	memset(&print_Message, 0, sizeof(print_Message));
	sprintf(print_Message, "PCLK2 Freq: %ld\r\n",HAL_RCC_GetPCLK2Freq());
	APP_Print_Log_UART(print_Message);
}

