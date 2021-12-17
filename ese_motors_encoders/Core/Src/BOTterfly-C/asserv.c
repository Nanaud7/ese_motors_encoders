#include <BOTterfly-H/asserv.h>

double consigne = 100;
double acc = 1; // 0

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

#define ENC_COEFF ((float)0.082826)

/*	@brief	Speed control function called with a 50Hz frequency
 *	@param	None
 *	@retval 0
 */
float Ctrl_SpeedControl(MOT_HandleTypeDef* Motor, ENC_HandleTypeDef* Encoder){
	// Récupération du nombre de ticks
	int16_t ticks = ENC_GetCnt(Encoder);
	if(ticks < 0) ticks = ticks * (-1);

	// Calcul de la vitesse du moteur
	int freq_codeuse = SPEED_CONTROL_FREQUENCY * ticks;
	//float speed = ((float)freq_codeuse * ((float)WHEEL_PERIMETER/Encoder->TicksPerRev));
	float speed = ((float)freq_codeuse * ENC_COEFF);
	// Vitesse calculée en mm/sec

	// Calcul de l'erreur
	if(acc < 1) acc+=0.01;
	else acc = 1;

	float erreur = consigne * acc - speed;
	float correcteurI = Motor->Ki * (erreur + Motor->erreurPrecedente)
			* (1/((float)SPEED_CONTROL_FREQUENCY * 2))
			+ Motor->siPrecedente;

	// Correcteur PI
	float s = Motor->Kp * erreur + correcteurI;
	if(s >= 80) 	s = 80;
	else if(s < 0) 	s = 0;

	Motor->siPrecedente = correcteurI;
	Motor->erreurPrecedente = erreur;

	MOT_SetDutyCycle(Motor,s);

	return s;
}
