#include "Motors.h"

/*	@brief	Set the PWM Duty Cycle
 *	@param	duty_cycle : value between 0 and 100
 */
uint8_t Mot_SetDutyCycle(uint8_t duty_cycle){
	if(duty_cycle > 100) duty_cycle = 100;

	float pulse = ((float)duty_cycle / 100) * (float)COUNTER_PERIOD;

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (uint32_t)pulse);
	return 0;
}
