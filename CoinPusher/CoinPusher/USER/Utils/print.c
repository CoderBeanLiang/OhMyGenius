#include <stdio.h>
#include "configs.h"


void Print_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;

  // USART clock Config
  PRINT_GPIO_RCC_APBxClockCmd(PRINT_GPIO_CLK, ENABLE);
  PRINT_USART_RCC_APBxClockCmd(PRINT_USART_CLK, ENABLE);

	// USART GPIO config
	GPIO_InitStruct.GPIO_Pin= PRINT_TX_PIN;
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PRINT_GPIO_TYPE, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin= PRINT_RX_PIN;
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	GPIO_Init(PRINT_GPIO_TYPE, &GPIO_InitStruct);

	// USART mode config
	USART_InitStruct.USART_BaudRate = PRINT_USART_BAUDRATE;
	USART_InitStruct.USART_WordLength = PRINT_USART_WORDLEN;
	USART_InitStruct.USART_StopBits = PRINT_USART_STOPBITS;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(PRINT_USART, &USART_InitStruct);
	USART_Cmd(PRINT_USART, ENABLE);
}


/**
	* Redirect 'printf()' to serial port
  */
int fputc(int ch, FILE *f)
{
	USART_SendData(PRINT_USART, (uint8_t) ch);
	while (USART_GetFlagStatus(PRINT_USART, USART_FLAG_TC) == RESET);
	return ch;
}
