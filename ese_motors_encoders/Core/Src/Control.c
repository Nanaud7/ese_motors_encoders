#include "Control.h"

/*
 *
 * INITIALIZATION FUNCTIONS
 *
 */

/*	@brief	Initialization of the motor control configuration structure with timer settings
 *	@param	Motor is a Ctrl_Struct structure
 *	@param 	htim is the TIM handle
 *	@retval 0
 */
uint8_t Ctrl_Init_SetTimer(Ctrl_Struct* Control, TIM_HandleTypeDef *htim){
	Control->Timer = htim;

	HAL_TIM_Base_Start_IT(Control->Timer);
	return 0;
}


/*
 *
 * MOTOR CONTROL FUNCTIONS
 *
 */

/*	@brief	Main motor control function
 *	@param	None
 *	@retval 0
 */
uint8_t Ctrl_MotorControl(){
	Odo_Odometry();

	return 0;
}
