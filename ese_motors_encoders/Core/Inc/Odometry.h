#ifndef INC_ODOMETRY_H_
#define INC_ODOMETRY_H_

/* Includes */
#include "stdint.h"
#include "Encoders.h"

/* Structures */
typedef struct Odo_Struct{
	// Encoders
	Enc_Struct LeftEncoder;
	Enc_Struct RightEncoder;

	// Robot position
	double x;
	double y;
	double o;

} Odo_Struct;

/* Prototypes */
uint8_t Odo_Odometry();

#endif /* INC_ODOMETRY_H_ */
