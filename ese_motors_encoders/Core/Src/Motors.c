#include "Motors.h"

/*
 *
 * INITIALIZATION FUNCTIONS
 *
 */

/*	@brief	Initialization of the motor configuration structure with timer settings
 *	@param	Motor is a Mot_Struct structure
 *	@param 	htim is the TIM handle
 *  @param  Channel is the TIM Channels
 *	@retval 0
 */
uint8_t Mot_Init_SetTimer(Mot_Struct* Motor, TIM_HandleTypeDef *htim, uint32_t Channel){
	Motor->Timer = htim;
	Motor->Timer_Channel = Channel;

	HAL_TIM_PWM_Start(Motor->Timer, Motor->Timer_Channel);
	return 0;
}

/*	@brief	Initialization of the motor configuration structure with GPIOs settings
 *	@param	Motor is a Mot_Struct structure
 *	@param 	IN1_GPIOx is a GPIOx where x can be (A..K) to select the GPIO peripheral for STM32
 *  @param  IN1_GPIO_Pin specifies the port bit
 *	@param 	IN2_GPIOx is a GPIOx where x can be (A..K) to select the GPIO peripheral for STM32
 *  @param  IN2_GPIO_Pin specifies the port bit
 *	@retval 0
 */
uint8_t Mot_Init_SetGPIOs(Mot_Struct* Motor, GPIO_TypeDef* IN1_GPIOx, uint16_t IN1_GPIO_Pin,
		GPIO_TypeDef* IN2_GPIOx, uint16_t IN2_GPIO_Pin){
	Motor->IN1_GPIOx = IN1_GPIOx;
	Motor->IN1_GPIO_Pin = IN1_GPIO_Pin;
	Motor->IN2_GPIOx = IN2_GPIOx;
	Motor->IN2_GPIO_Pin = IN2_GPIO_Pin;
	return 0;
}


/*
 *
 * DRIVER FUNCTIONS
 *
 */

/*	@brief	Set the direction of the motor
 *	@param	Motor is a Mot_Struct structure
 *	@param	direction specifies the function applied to the motor
 *		@arg	MOTOR_STOP
 *		@arg 	MOTOR_FORWARD
 *		@arg 	MOTOR_REVERSE
 *	@retval 0
 */

uint8_t Mot_SetDirection(Mot_Struct* Motor, uint8_t direction){
	switch(direction){

	case MOTOR_STOP:
		HAL_GPIO_WritePin(Motor->IN1_GPIOx, Motor->IN1_GPIO_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Motor->IN2_GPIOx, Motor->IN2_GPIO_Pin, GPIO_PIN_RESET);
		break;

	case MOTOR_FORWARD:
		HAL_GPIO_WritePin(Motor->IN1_GPIOx, Motor->IN1_GPIO_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Motor->IN2_GPIOx, Motor->IN2_GPIO_Pin, GPIO_PIN_RESET);
		break;

	case MOTOR_REVERSE:
		HAL_GPIO_WritePin(Motor->IN1_GPIOx, Motor->IN1_GPIO_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Motor->IN2_GPIOx, Motor->IN2_GPIO_Pin, GPIO_PIN_SET);
		break;

	default:
		HAL_GPIO_WritePin(Motor->IN1_GPIOx, Motor->IN1_GPIO_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Motor->IN2_GPIOx, Motor->IN2_GPIO_Pin, GPIO_PIN_RESET);
	}
}

/*	@brief	Set the PWM Duty Cycle
 *	@param	Motor is a Mot_Struct structure
 *	@param	duty_cycle is value between 0 and 100
 *	@retval 0
 */
uint8_t Mot_SetDutyCycle(Mot_Struct* Motor, uint8_t duty_cycle){
	if(duty_cycle > 100) duty_cycle = 100;

	float pulse = ((float)duty_cycle / 100) * (float)COUNTER_PERIOD;

	__HAL_TIM_SET_COMPARE(Motor->Timer, Motor->Timer_Channel, (uint32_t)pulse);
	return 0;
}
