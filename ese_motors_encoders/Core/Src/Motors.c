#include "Motors.h"

/*	@brief	Initialization of the motor configuration structure
 *	@param	motor : Mot_Struct structure
 */
uint8_t Mot_Init_SetTimer(Mot_Struct Motor, TIM_HandleTypeDef *htim, uint32_t Channel){
	Motor.Timer_PWM = htim;
	Motor.Timer_Channel = Channel;
	return 0;
}

/*	@brief	Set the PWM Duty Cycle
 *	@param	duty_cycle : value between 0 and 100
 */
uint8_t Mot_SetDutyCycle(uint8_t duty_cycle){
	if(duty_cycle > 100) duty_cycle = 100;

	float pulse = ((float)duty_cycle / 100) * (float)COUNTER_PERIOD;

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (uint32_t)pulse);
	return 0;
}
