#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

/* Comment configurer l'IOC ?
 *
 * 1) Configurer 2x timers en PWM Generation à 25kHz avec un rapport cyclique de 0%.
 * Exemple : Clk = 84MHz => PSC = 84-1, ARR = 40-1 et Pulse = 20 + Fast Mode
 *
 * */

#include "tim.h"

/* Defines */
#define COUNTER_PERIOD 40

/* Prototypes */
uint8_t Mot_SetDutyCycle(uint8_t duty_cycle);

#endif /* INC_MOTORS_H_ */
