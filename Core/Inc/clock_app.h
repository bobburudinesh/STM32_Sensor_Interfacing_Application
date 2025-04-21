/*
 * clock_app.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Dinesh Bobburu
 */

#ifndef INC_CLOCK_APP_H_
#define INC_CLOCK_APP_H_

#include "stm32f4xx_hal.h"
/*
 * This enum have contains different clock frequency options
 * */
typedef enum {
	clock_16Mhz = 16,
	clock_32Mhz = 32,
	clock_50Mhz = 50,
	clock_84Mhz = 84,
	clock_100Mhz = 100,
	clock_120Mhz = 120,
	clock_180Mhz = 180
}Clock_Frequency_Mhz;

/*
 * This enum contains different options for Oscillator sources
 * */
typedef enum {
	HSE,
	HSI,
	LSE,
	LSI
}Oscillator_Source;

/*
 * This enum contains different clock types
 * */

typedef enum {
	SYSCLK,
	HCLK,
	PCLK1,
	PCLK2
}Clock_Type;

/*
 * Methods related to Clock
 * */
void App_Clock_Init_From_PLL(Clock_Frequency_Mhz clock_Frequency, uint32_t ahb_prescaler, uint32_t apb1_prescaler, uint32_t apb2_prescaler);
void APP_Print_Clock_Log_UART(void);
void APP_HSI_Clock_Init_On_MCO1(void); // LSE will output on MCO1(PA8)


/*
 * HELPER FUNCTIONS
 * */
uint32_t APP_CLock_GET_APB1_TIM_Freq(void);
uint32_t APP_CLock_GET_APB2_TIM_Freq(void);


#endif /* INC_CLOCK_APP_H_ */
