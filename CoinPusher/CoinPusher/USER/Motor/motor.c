#include "configs.h"
#include "motor.h"


void Motor_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	MOTOR_GPIO_RCC_APBxClockCmd(MOTOR_GPIO_CLK, ENABLE);
	
	// A
	GPIO_InitStruct.GPIO_Pin = MOTOR_A_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_GPIO_TYPE, &GPIO_InitStruct);
	// B
	GPIO_InitStruct.GPIO_Pin = MOTOR_B_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_GPIO_TYPE, &GPIO_InitStruct);
	// C
	GPIO_InitStruct.GPIO_Pin = MOTOR_C_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_GPIO_TYPE, &GPIO_InitStruct);
	// D
	GPIO_InitStruct.GPIO_Pin = MOTOR_D_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_GPIO_TYPE, &GPIO_InitStruct);
}


void Motor_Drive(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
	GPIO_WriteBit(MOTOR_GPIO_TYPE, MOTOR_A_GPIO_PIN, a > 0 ? Bit_SET : Bit_RESET);
	GPIO_WriteBit(MOTOR_GPIO_TYPE, MOTOR_B_GPIO_PIN, b > 0 ? Bit_SET : Bit_RESET);
	GPIO_WriteBit(MOTOR_GPIO_TYPE, MOTOR_C_GPIO_PIN, c > 0 ? Bit_SET : Bit_RESET);
	GPIO_WriteBit(MOTOR_GPIO_TYPE, MOTOR_D_GPIO_PIN, d > 0 ? Bit_SET : Bit_RESET);
}
