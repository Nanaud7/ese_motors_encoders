#include <BOTterfly-H/odo.h>

/*
 *
 * INITIALIZATION FUNCTIONS
 *
 */

uint8_t Odo_Init(Odo_Struct* Odo, ENC_HandleTypeDef* LeftEncoder, ENC_HandleTypeDef* RightEncoder){
	Odo->LeftEncoder = LeftEncoder;
	Odo->RightEncoder = RightEncoder;

	Odo->x = 0;
	Odo->y = 0;
	Odo->o = 0;
	return 0;
}

/*
 *
 * ODOMETRY FUNCTIONS
 *
 */

/*	@brief	Odometry function
 *	@param	Odo is a Odo_Struct structure
 *	@retval 0
 */
uint8_t Odo_Odometry(Odo_Struct* Odo){
	int16_t tickLeft = Enc_GetCnt(Odo->LeftEncoder);
	int16_t tickRight = Enc_GetCnt(Odo->RightEncoder);

	float dDistance = (tickLeft * COEFF_ENC_LEFT + tickRight * COEFF_ENC_RIGHT) / 2;
	float dAngle = (tickRight * COEFF_ENC_RIGHT - tickLeft * COEFF_ENC_LEFT) / CENTER_DISTANCE;

	Odo->x += dDistance * cos(Odo->o);
	Odo->y += dDistance * sin(Odo->o);
	Odo->o += dAngle;

	if(Odo->o > M_PI)
		Odo->o -= M_PI * 2.0f;

	if(Odo->o < (-1) * M_PI)
		Odo->o += M_PI * 2.0f;

	Enc_ResetCnt(Odo->LeftEncoder);
	Enc_ResetCnt(Odo->RightEncoder);

	return 0;
}
