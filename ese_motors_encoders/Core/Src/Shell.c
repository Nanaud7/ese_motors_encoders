#include "Shell.h"

const char shellPrompt[] = "\r\nBOTterfly: ";
char charReceived = 0;
char charArray[32] = "";
uint8_t indexSh = 0;

const char *ShellCmd[]= {
    "GET_T", // 0
    "GET_P", // 1
	0
};

uint8_t Shell_Init(Shell_Struct* Shell, UART_HandleTypeDef* huart){
	Shell->huart = huart;
	HAL_UART_Receive_IT(Shell->huart, (uint8_t*)&charReceived, 1);
	HAL_UART_Transmit(Shell->huart, (uint8_t*)shellPrompt, sizeof(shellPrompt), HAL_MAX_DELAY);
	return 0;
}

uint8_t Shell_CharReceived(Shell_Struct* Shell, char charReceived){
	if(charReceived !='\r' && indexSh<32){
		HAL_UART_Transmit(Shell->huart, (uint8_t*)&charReceived, 1, HAL_MAX_DELAY);
		charArray[indexSh] = charReceived;
		indexSh++;
	}
	else{
		Shell_Request(Shell, charArray);
		memset(charArray, 0, sizeof (charArray));
		indexSh=0;
		HAL_UART_Transmit(Shell->huart, (uint8_t*)shellPrompt, sizeof(shellPrompt), HAL_MAX_DELAY);
	}

	return 0;
}

uint8_t Shell_Request(Shell_Struct* Shell, char* cmd){

	uint8_t cmdSelected = -1;
    for (uint8_t j = 0; ShellCmd[j]; j++){
    	if(!strcmp(cmd, ShellCmd[j])) cmdSelected = j;
    }

    switch(cmdSelected){
    	case 0:
    		HAL_UART_Transmit(Shell->huart, (uint8_t*)"\r\nT=+12.50_C", 13, HAL_MAX_DELAY);
    		break;
    	default:
    		break;
    }

	return 0;
}
