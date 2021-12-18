#include <BOTterfly-H/odo.h>

// Variables
double x = 0;
double y = 0;
double o = 0;

/*
 *
 * INITIALIZATION FUNCTIONS
 *
 */

uint8_t Odo_Init(ODO_HandleTypeDef* Odo){
	//Odo->LeftEncoder = LeftEncoder;
	//Odo->RightEncoder = RightEncoder;

	Odo->leftTicks = 0;
	Odo->rightTicks = 0;

	x = 0;
	y = 0;
	o = 0;
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
uint8_t Odo_Odometry(ODO_HandleTypeDef* Odo){
	//int16_t tickLeft = ENC_GetCnt(Odo->LeftEncoder);
	//int16_t tickRight = ENC_GetCnt(Odo->RightEncoder);

	Odo->leftTicks = Odo->leftTicks * (-1);

	float dDistance = ((float)Odo->leftTicks * (float)COEFF_ENC_LEFT
			+ (float)Odo->rightTicks * (float)COEFF_ENC_RIGHT) / 2;
	float dAngle = ((float)Odo->rightTicks * (float)COEFF_ENC_RIGHT
			- (float)Odo->leftTicks * (float)COEFF_ENC_LEFT)
			/ (float)CENTER_DISTANCE;

	x += dDistance * cos(o);
	y += dDistance * sin(o);
	o += dAngle;

	if(o > M_PI)
		o -= M_PI * 2.0f;

	if(o < (-1) * M_PI)
		o += M_PI * 2.0f;

	printf("x:%.1f\t\to:%.1f\r\n", x, o);
	//printf("left:%d\t\tright:%d\r\n", Odo->leftTicks, Odo->rightTicks);

	//ENC_ResetCnt(Odo->LeftEncoder);
	//ENC_ResetCnt(Odo->RightEncoder);

	return 0;
}
