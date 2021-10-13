#include "Shell.h"

uint8_t myPrintf(UART_HandleTypeDef *huart, char *data){

	HAL_UART_Transmit(&huart2, (uint8_t*) data, 64, 50);
	return 0;
}
