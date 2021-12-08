#include <BOTterfly-H/asserv.h>

double consigne = 0.125;

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
uint8_t Ctrl_Init_SetTimer(ASSERV_HandleTypeDef* Control, TIM_HandleTypeDef *htim){
	Control->Timer = htim;

	HAL_TIM_Base_Start_IT(Control->Timer);
	return 0;
}

uint8_t Ctrl_Set_Consigne(double new_Consigne){
	consigne = new_Consigne;
	printf("New consigne = %f\r\n",consigne);
	return 0;
}

/*
uint8_t Ctrl_Set_Kp(float new_Kp){
	Kp = new_Kp;
	return 0;
}

uint8_t Ctrl_Set_Ki(float new_Ki){
	Ki = new_Ki;
	return 0;
}

float Ctrl_Get_Kp(){
	return Kp;
}

float Ctrl_Get_Ki(){
	return Ki;
}
*/


/*
 *
 * MOTOR CONTROL FUNCTIONS
 *
 */

/*	@brief	Speed control function called with a 50Hz frequency
 *	@param	None
 *	@retval 0
 */
float Ctrl_SpeedControl(MOT_HandleTypeDef* Motor, ENC_HandleTypeDef* Encoder){
	//static double sommeErreur = 0;

	// Réception du nombre de ticks du codeur
	int16_t ticks = ENC_GetCnt(Encoder);
	if(ticks < 0) ticks = abs(ticks);

	// Calcul de la vitesse à part
	int freq_codeuse = SPEED_CONTROL_FREQUENCY * ticks;
	//float speed = (float)freq_codeuse/(float)ENCODER_PPR; 				// Vitesse en tour/min
	//float speed = (float)freq_codeuse * (float)DISTANCE_PER_TICK;			// Vitesse en mm/sec
	float speed = ((float)freq_codeuse * ((float)WHEEL_PERIMETER/Encoder->TicksPerRev)) / 1000;	// Vitesse en m/sec

	// Erreur entre la consigne et la vitesse calculée
	//double erreur = consigne - speed;
	float erreur = consigne - speed;
	Motor->sommeErreur += erreur;

	// Correcteur PI
	float cmd = 60 + erreur * Motor->Kp + Motor->sommeErreur * Motor->Ki;
	if(cmd >= 80) 		cmd = 80;
	else if(cmd < 0) 	cmd = 0;

	MOT_SetDutyCycle(Motor,cmd);

	return speed;
}
