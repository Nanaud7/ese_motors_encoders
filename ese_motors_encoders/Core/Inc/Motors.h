#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

/* Comment configurer le moteur ?
 *
 * 1) Dans l'IOC, configurer 2x timers en PWM Generation à 25kHz avec un rapport cyclique de 0%.
 * Exemple : Clk = 84MHz => PSC = 84-1, ARR = 40-1 et Pulse = 20 + Fast Mode
 *
 * 2) Programme d'exemple :
 * Mot_Struct MoteurA;
 * Mot_Init_SetTimer(&MoteurA, &htim1, TIM_CHANNEL_1); 					// Initialisation Timer
 * Mot_Init_SetGPIOs(&MoteurA, GPIOC, GPIO_PIN_0, GPIOC, GPIO_PIN_1);	// Initialisation GPIOs
 * Mot_SetDirection(&MoteurA, MOTOR_FORWARD);	// Définition du sens de rotation
 * Mot_SetDutyCycle(&MoteurA, 65);
 *
 * */

#include "tim.h"

/* Structure */

// Mot_Struct contient tous les paramètres relatifs à un moteur
typedef struct Mot_Struct{
	// Enable Pin (PWM)
	TIM_HandleTypeDef* Timer;
	uint32_t Timer_Channel;

	// Inputs Pins (GPIO Out)
	GPIO_TypeDef* IN1_GPIOx;
	uint16_t IN1_GPIO_Pin;
	GPIO_TypeDef* IN2_GPIOx;
	uint16_t IN2_GPIO_Pin;

	// Sense Pins (ADC In)
} Mot_Struct;

/* Defines */
#define MOTOR_STOP 		0
#define MOTOR_FORWARD 	1
#define MOTOR_REVERSE 	2

#define COUNTER_PERIOD 40

/* Prototypes */
uint8_t Mot_Init_SetTimer(Mot_Struct* Motor, TIM_HandleTypeDef *htim, uint32_t Channel);
uint8_t Mot_Init_SetGPIOs(Mot_Struct* Motor, GPIO_TypeDef* IN1_GPIOx, uint16_t IN1_GPIO_Pin,
		GPIO_TypeDef* IN2_GPIOx, uint16_t IN2_GPIO_Pin);
uint8_t Mot_SetDirection(Mot_Struct* Motor, uint8_t direction);
uint8_t Mot_SetDutyCycle(Mot_Struct* Motor, uint8_t duty_cycle);

#endif /* INC_MOTORS_H_ */
