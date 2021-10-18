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

#include "tim.h"
#include "Odometry.h"

/* Structure */

// Mot_Struct contient tous les paramètres relatifs à un moteur
typedef struct Ctrl_Struct{
	TIM_HandleTypeDef* Timer;

} Ctrl_Struct;

uint8_t Ctrl_Init_SetTimer(Ctrl_Struct* Control, TIM_HandleTypeDef *htim);
uint8_t Ctrl_MotorControl();

#endif /* INC_CONTROL_H_ */
