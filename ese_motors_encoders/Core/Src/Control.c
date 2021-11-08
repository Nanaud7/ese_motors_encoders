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

/*	@brief	Speed control function called with a 50Hz frequency
 *	@param	None
 *	@retval 0
 */
float Ctrl_SpeedControl(){
	// Nombre de ticks du compteur depuis le dernier appel
	int16_t ticks = Enc_GetCnt(&CodeurGauche);
	//printf("%d\r\n",ticks);

	// Calcul de la distance
	//float distance = 0;
	//if(ticks >= 0) distance = (float)ticks * (float)DISTANCE_PER_TICK;
	//else distance = (-1) * (float)ticks * (float)DISTANCE_PER_TICK;
	//printf("%f\r\n",distance);

	// Calcul de la vitesse
	float speed = (ticks / (float)ENCODER_PPR) * 50;
	//printf("%f\r\n",(float)SPEED_CONTROL_PERIOD);
	printf("%f tr/s\r\n",speed);

	return speed;
}
