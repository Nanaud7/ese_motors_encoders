#include "Control.h"

double consigne = 20;
double sommeErreur = 0;

// Coefficients du correcteur PI
float Kp = 1.00;
float Ki = 0.02;

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
	// Réception du nombre de ticks du codeur
	uint16_t ticks = Enc_GetCnt(&CodeurGauche);

	// Calcul de la vitesse à part
	//int freq_codeuse = SPEED_CONTROL_FREQUENCY * ticks;
	//float speed = (float)freq_codeuse/(float)ENCODER_PPR;

	// Erreur entre la consigne et la vitesse calculée
	//double erreur = consigne - speed;
	float erreur = consigne - ticks;
	sommeErreur += erreur;

	// Correcteur PI


	float cmd = 50 + erreur * Kp + sommeErreur * Ki;
	if(cmd >= 80) 		cmd = 80;
	else if(cmd < 0) 	cmd = 0;

	Mot_SetDutyCycle(&MoteurGauche,cmd);

	return ticks;
}
