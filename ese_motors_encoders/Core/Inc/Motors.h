#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

/* Comment configurer l'IOC ?
 *
 * 1) Configurer 2x timers en PWM Generation à 25kHz avec un rapport cyclique de 0%.
 * Exemple : Clk = 84MHz => PSC = 84-1, ARR = 40-1 et Pulse = 20 + Fast Mode
 *
 * */

#include "tim.h"

/* Structure */

// Mot_Struct contient tous les paramètres relatifs à un moteur
typedef struct Mot_Struct{
	// Enable Pin (PWM)
	TIM_HandleTypeDef* Timer_PWM;
	uint32_t Timer_Channel;

	// Inputs Pins (GPIO Out)
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;

	// Sense Pins (ADC In)
} Mot_Struct;

/* Defines */
#define COUNTER_PERIOD 40

/* Prototypes */
uint8_t Mot_Init_SetTimer(Mot_Struct Motor, TIM_HandleTypeDef *htim, uint32_t Channel);
uint8_t Mot_SetDutyCycle(uint8_t duty_cycle);

#endif /* INC_MOTORS_H_ */
