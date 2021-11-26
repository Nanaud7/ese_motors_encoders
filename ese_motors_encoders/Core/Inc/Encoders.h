#ifndef INC_ENCODERS_H_
#define INC_ENCODERS_H_

/* Comment configurer le codeur ?
 *
 * 1) Dans l'IOC, configurer 2x timers en Encoder Mode
 *
 * 2)
 */

/* Includes */
#include "tim.h"

/* Defines */
// PPR = Pulse Per Revolution
#define ENCODER_PPR 900			// Nombre de ticks par révolution (900 mesuré)
#define WHEEL_DIAMETER 39.5		// Diamètre des roues en mm
#define WHEEL_PERIMETER ((float)WHEEL_DIAMETER * (float)3.1415)	// Périmètre de la roue en mm
#define DISTANCE_PER_TICK ((float)WHEEL_PERIMETER / (float)ENCODER_PPR)

/* Structure */
// Mot_Struct contient tous les paramètres relatifs à un codeur
typedef struct Enc_Struct{
	TIM_HandleTypeDef* Timer;
	uint32_t Timer_Channel_A;
	uint32_t Timer_Channel_B;
} Enc_Struct;

/* Variables */
//extern Enc_Struct CodeurGauche;
//extern Enc_Struct CodeurDroite;

/* Prototypes */
uint8_t Enc_Init_SetTimer(Enc_Struct* Encoder, TIM_HandleTypeDef *htim, uint32_t Channel_A, uint32_t Channel_B);
int16_t Enc_GetCnt(Enc_Struct* Encoder);
uint8_t Enc_ResetCnt(Enc_Struct* Encoder);

#endif /* INC_ENCODERS_H_ */
