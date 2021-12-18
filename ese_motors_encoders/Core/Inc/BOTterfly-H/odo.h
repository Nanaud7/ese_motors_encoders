#ifndef INC_ODOMETRY_H_
#define INC_ODOMETRY_H_

/* Includes */
#include <BOTterfly-H/encoder.h>
#include "stdint.h"
#include "math.h"

/* Structures */
typedef struct ODO_HandleTypeDef{
	// Encoders
	//struct ENC_HandleTypeDef *LeftEncoder;
	//struct ENC_HandleTypeDef *RightEncoder;

	// Robot position
	//double x;
	//double y;
	//double o;

	// Last encoders ticks
	int32_t leftTicks;
	int32_t rightTicks;

} ODO_HandleTypeDef;

/* Defines */
#define COEFF_ENC_LEFT	0.085003
#define COEFF_ENC_RIGHT	0.084198
#define CENTER_DISTANCE 183 	// Entraxe

/* Prototypes */
//uint8_t Odo_Init(ODO_HandleTypeDef* Odo, struct ENC_HandleTypeDef* LeftEncoder, struct ENC_HandleTypeDef* RightEncoder);
uint8_t Odo_Init(ODO_HandleTypeDef* Odo);
uint8_t Odo_Odometry(ODO_HandleTypeDef* Odo);

#endif /* INC_ODOMETRY_H_ */
