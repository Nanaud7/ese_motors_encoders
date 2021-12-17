/**
 ******************************************************************************
 * @file	shell.h
 * @author 	Arnaud CHOBERT
 * @brief	Shell
 ******************************************************************************
 */

#ifndef INC_SHELL_H_
#define INC_SHELL_H_

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "usart.h"
#include "gpio.h"

/* Exported types ------------------------------------------------------------*/
/* End of exported types -----------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/* End of exported macros ----------------------------------------------------*/

/* External variables --------------------------------------------------------*/
extern char c;
/* End of external variables -------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
char uart_read();
int uart_write(char * s, uint16_t size);
void uart_data_ready();
void shell_char_received();
void shell_init(UART_HandleTypeDef* huart);
int shell_add(char * cmd, int (* pfunc)(int argc, char ** argv), char * description);
int shell_exec(char * cmd);
/* End of exported functions -------------------------------------------------*/

#endif /* INC_SHELL_H_ */
