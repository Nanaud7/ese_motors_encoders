#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

/* Comment configurer le moteur ?
 *
 * 1) Dans l'IOC, configurer 1x timers ayant une fréquence de 50Hz, avec interruptions.
 * Exemple :	Clk = 84MHz => PSC = 8400-1, ARR = 200-1
 * 				Utilisation d'un timer basique fortement conseillée.
 *
 * 2) Programme d'exemple :
 *
 * */

#include "CONFIG.h"
#include "ENCODERS.h"
#include "MOTORS.h"
#include "math.h"
#include "tim.h"

/* Defines */
#define SPEED_CONTROL_FREQUENCY 50
#define SPEED_CONTROL_PERIOD (1/(float)SPEED_CONTROL_FREQUENCY)

/* Structure */
// Mot_Struct contient tous les paramètres relatifs à un moteur
typedef struct Ctrl_Struct{
	// Timer
	TIM_HandleTypeDef* Timer;
	// Odometry
	struct Odo_Struct *Odo;
	// Motors
	struct Mot_Struct *MotorLeft;
	struct Mot_Struct *MotorRight;
} Ctrl_Struct;

uint8_t Ctrl_Init_SetTimer(Ctrl_Struct* Control, TIM_HandleTypeDef *htim);
uint8_t Ctrl_Set_Consigne(double new_Consigne);
uint8_t Ctrl_Set_Kp(float new_Kp);
uint8_t Ctrl_Set_Ki(float new_Ki);
float Ctrl_Get_Kp();
float Ctrl_Get_Ki();
float Ctrl_SpeedControl();

#endif /* INC_CONTROL_H_ */
