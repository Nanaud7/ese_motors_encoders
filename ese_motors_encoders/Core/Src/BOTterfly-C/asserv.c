#include <BOTterfly-H/asserv.h>

double consigne = 100;
double acc = 0; // 0

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
int32_t Ctrl_SpeedControl(MOT_HandleTypeDef* Motor, ENC_HandleTypeDef* Encoder){
	// Récupération du nombre de ticks
	int32_t ticks = ENC_GetCnt(Encoder);
	int32_t ticksMem = ticks;
	if(ticks < 0) ticks = ticks * (-1);

	// Calcul de la vitesse du moteur
	int freq_codeuse = SPEED_CONTROL_FREQUENCY * ticks;
	//float speed = ((float)freq_codeuse * ((float)WHEEL_PERIMETER/Encoder->TicksPerRev));
	float speed = ((float)freq_codeuse * Encoder->TicksCoeff);
	// Vitesse calculée en mm/sec

	// Calcul de l'erreur
	if(acc < 1) acc+=0.01;
	else acc = 1;

	float erreur = acc * consigne - speed;
	float uI = Motor->uI_moins1 + Motor->Kp * (SPEED_CONTROL_PERIOD / SPEED_CONTROL_PERIOD)
			* Motor->erreur_moins1;

	// Correcteur PI
	float u = Motor->Kp * erreur + uI;
	if(u >= 80) 	u = 80;
	else if(u < 0) 	u = 0;

	Motor->uI_moins1 = uI;
	Motor->erreur_moins1 = erreur;

	MOT_SetDutyCycle(Motor,u);

	return ticksMem;
}
