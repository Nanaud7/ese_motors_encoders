
#ifndef INC_CONFIG_H_
#define INC_CONFIG_H

#include <BOTterfly-H/motor.h>
#include <BOTterfly-H/encoder.h>
#include <BOTterfly-H/odo.h>

/* MOTORS */
struct MOT_HandleTypeDef MoteurGauche;
struct MOT_HandleTypeDef MoteurDroite;

/* ENCODERS */
struct ENC_HandleTypeDef CodeurGauche;
struct ENC_HandleTypeDef CodeurDroite;

/* ASSERVISSEMENT / CONTROL */
struct ASSERV_HandleTypeDef Asserv;
struct ODO_HandleTypeDef Odometry;

#endif /* INC_CONFIG_H_ */
