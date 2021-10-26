#ifndef INC_SHELL_H_
#define INC_SHELL_H_

#include "usart.h"
#include "string.h"

/* Variables */
extern char charReceived;

/* Structures */

typedef struct Shell_Struct{
	UART_HandleTypeDef* huart;
} Shell_Struct;

/* Prototypes */
uint8_t Shell_Init(Shell_Struct* Shell, UART_HandleTypeDef* huart);
uint8_t Shell_CharReceived(Shell_Struct* Shell, char charReceived);
uint8_t Shell_Request(Shell_Struct* Shell, char* cmd);

#endif /* INC_SHELL_H_ */
