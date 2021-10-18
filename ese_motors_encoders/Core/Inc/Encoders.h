#ifndef INC_ENCODERS_H_
#define INC_ENCODERS_H_

/* Comment configurer le codeur ?
 *
 * 1) Dans l'IOC, configurer 2x timers en Encoder Mode
 *
 * 2)
 */

#include "tim.h"

/* Structure */

// Mot_Struct contient tous les paramètres relatifs à un codeur
typedef struct Enc_Struct{
	TIM_HandleTypeDef* Timer;
	uint32_t Timer_Channel_A;
	uint32_t Timer_Channel_B;
} Enc_Struct;

/* Prototypes */
uint8_t Enc_Init_SetTimer(Enc_Struct* Encoder, TIM_HandleTypeDef *htim, uint32_t Channel_A, uint32_t Channel_B);
uint16_t Enc_GetCnt(Enc_Struct* Encoder);
uint8_t Enc_ResetCnt(Enc_Struct* Encoder);

#endif /* INC_ENCODERS_H_ */
