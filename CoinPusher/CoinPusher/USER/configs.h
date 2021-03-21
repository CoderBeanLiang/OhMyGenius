#ifndef __CONFIGS_H
#define __CONFIGS_H


#include "stm32f10x.h"
#include "core_cm3.h"



/* Motor GPIO Pins */
#define MOTOR_GPIO_RCC_APBxClockCmd		RCC_APB2PeriphClockCmd
#define MOTOR_GPIO_CLK					RCC_APB2Periph_GPIOB
#define MOTOR_GPIO_TYPE					GPIOB
#define MOTOR_A_GPIO_PIN				GPIO_Pin_6
#define MOTOR_B_GPIO_PIN				GPIO_Pin_7
#define MOTOR_C_GPIO_PIN				GPIO_Pin_8
#define MOTOR_D_GPIO_PIN				GPIO_Pin_9


/* LED Configs */
// GPIO used for LED
#define LED_RCC_APBxClockCmd		RCC_APB2PeriphClockCmd
#define LED_GPIO_CLK 						RCC_APB2Periph_GPIOB
#define LED_GPIO_TYPE 					GPIOB
#define LED_GPIO_PIN  					GPIO_Pin_11


/* Printf Debug Configs */
// GPIO(Usart) used for redirect printf
#define PRINT_GPIO_RCC_APBxClockCmd			RCC_APB2PeriphClockCmd
#define PRINT_GPIO_CLK 					RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO
#define PRINT_GPIO_TYPE 				GPIOA
#define PRINT_TX_PIN  					GPIO_Pin_2
#define PRINT_RX_PIN  					GPIO_Pin_3
// Usart init params
#define PRINT_USART_RCC_APBxClockCmd		RCC_APB1PeriphClockCmd
#define PRINT_USART_CLK 				RCC_APB1Periph_USART2
#define PRINT_USART							USART2
#define PRINT_USART_BAUDRATE		115200
#define PRINT_USART_WORDLEN			USART_WordLength_8b
#define PRINT_USART_STOPBITS		USART_StopBits_1


#endif /* __CONFIGS_H */
