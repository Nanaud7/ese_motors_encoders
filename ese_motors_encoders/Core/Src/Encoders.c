#include "Encoders.h"

/*
 *
 * INITIALIZATION FUNCTIONS
 *
 */

/*	@brief	Initialization of the encoder configuration structure with timer settings
 *	@param	Encoder is a Enc_Struct structure
 *	@param 	htim is the TIM handle
 *  @param  Channel_A is the TIM Channels
 *  @param  Channel_B is the TIM Channels
 *	@retval 0
 */
uint8_t Enc_Init_SetTimer(Enc_Struct* Encoder, TIM_HandleTypeDef *htim, uint32_t Channel_A, uint32_t Channel_B){
	Encoder->Timer = htim;
	Encoder->Timer_Channel_A = Channel_A;
	Encoder->Timer_Channel_B = Channel_B;

	HAL_TIM_Encoder_Start(Encoder->Timer, Encoder->Timer_Channel_A & Encoder->Timer_Channel_B);
	return 0;
}


/*
 *
 * ENCODER FUNCTIONS
 *
 */

/*	@brief	Get the counter value of the timer
 *	@param	Encoder is a Enc_Struct structure
 *	@retval CNT value of the timer
 */
uint16_t Enc_GetTick(Enc_Struct* Encoder){
	//uint16_t ticks = __HAL_TIM_GET_COUNTER(Encoder->Timer);
	uint16_t ticks = Encoder->Timer->Instance->CNT;

	return ticks;
}
