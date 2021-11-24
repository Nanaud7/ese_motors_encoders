#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

/* Comment configurer un moteur ?
 *
 * 1) Dans l'IOC, configurer 1x timer en PWM Generation à 25kHz avec un rapport cyclique de 0%.
 * Exemple:	Clk = 84MHz => PSC = 0, ARR = 3360-1 et Pulse = 0
 * 2) Dans l'IOC, configurer 2x GPIO
 * 3) Dans l'IOC, configurer 1x ADC avec IT, Continuous Conversion Mode et ADC_EOC_SEQ_CONV
 *
 * 4) Programme d'exemple :
 * Mot_Struct MoteurA;
 * Mot_Init_SetTimer(&MoteurA, &htim1, TIM_CHANNEL_1); 					// Initialisation Timer
 * Mot_Init_SetGPIOs(&MoteurA, GPIOC, GPIO_PIN_0, GPIOC, GPIO_PIN_1);	// Initialisation GPIOs
 * Mot_SetDirection(&MoteurA, MOTOR_FORWARD);	// Définition du sens de rotation
 * Mot_SetDutyCycle(&MoteurA, 65);
 *
 * void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
 * 		if(hadc->Instance == ADC1){
 * 		uint32_t val = HAL_ADC_GetValue(&hadc1);
 * }
 *
 *
 * */

#include "tim.h"



/* Structure */

// Mot_Struct contient tous les paramètres relatifs à un moteur
typedef struct Mot_Struct{
	// Enable Pin (PWM)
	TIM_HandleTypeDef* Timer_Handle;
	uint32_t Timer_Channel;

	// Inputs Pins (GPIO Out)
	GPIO_TypeDef* IN1_GPIOx;
	uint16_t IN1_GPIO_Pin;
	GPIO_TypeDef* IN2_GPIOx;
	uint16_t IN2_GPIO_Pin;

	// Sense Pins (ADC In)
	ADC_HandleTypeDef* ADC_Handle;
} Mot_Struct;

/* Defines */
#define MOTOR_STOP 		0
#define MOTOR_FORWARD 	1
#define MOTOR_REVERSE 	2

#define COUNTER_PERIOD 3360

extern Mot_Struct MoteurGauche;
extern Mot_Struct MoteurDroite;

/* Prototypes */
uint8_t Mot_Init_SetTimer(Mot_Struct* Motor, TIM_HandleTypeDef *htim, uint32_t Channel);
uint8_t Mot_Init_SetGPIOs(Mot_Struct* Motor, GPIO_TypeDef* IN1_GPIOx, uint16_t IN1_GPIO_Pin,
		GPIO_TypeDef* IN2_GPIOx, uint16_t IN2_GPIO_Pin);
uint8_t Mot_SetDirection(Mot_Struct* Motor, uint8_t direction);
uint8_t Mot_SetDutyCycle(Mot_Struct* Motor, float duty_cycle);

#endif /* INC_MOTORS_H_ */
