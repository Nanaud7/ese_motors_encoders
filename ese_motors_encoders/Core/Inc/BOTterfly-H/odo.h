#ifndef INC_ODOMETRY_H_
#define INC_ODOMETRY_H_

/* Includes */
#include <BOTterfly-H/encoder.h>
#include "stdint.h"
#include "math.h"

/* Structures */
typedef struct Odo_Struct{
	// Encoders
	struct ENC_HandleTypeDef *LeftEncoder;
	struct ENC_HandleTypeDef *RightEncoder;

	// Robot position
	double x;
	double y;
	double o;

} Odo_Struct;

/* Defines */
#define COEFF_ENC_LEFT	1
#define COEFF_ENC_RIGHT	1
#define CENTER_DISTANCE 1 	// Entraxe

/* Prototypes */
uint8_t Odo_Init(Odo_Struct* Odo, struct ENC_HandleTypeDef* LeftEncoder, struct ENC_HandleTypeDef* RightEncoder);
uint8_t Odo_Odometry(Odo_Struct* Odo);

#endif /* INC_ODOMETRY_H_ */
