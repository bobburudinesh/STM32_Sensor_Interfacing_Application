/*
 * timer_app.h
 *
 *  Created on: Apr 20, 2025
 *      Author: Dinesh Bobburu
 */

#ifndef INC_TIMER_APP_H_
#define INC_TIMER_APP_H_





void APP_Timer6_Init(TIM_HandleTypeDef *htim);
void APP_Timer2_IC_Init(TIM_HandleTypeDef *htim);
void APP_Timer2_OC_Init(TIM_HandleTypeDef *htim);
void APP_Timer2_PWM_Init(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_APP_H_ */
