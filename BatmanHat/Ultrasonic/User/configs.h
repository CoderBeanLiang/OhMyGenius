#ifndef __CONFIGS_H
#define __CONFIGS_H


#include "stm32f10x.h"
#include "core_cm3.h"


/* Main Configs */
// How many seconds between checks in main loop
#define CHECK_DURATION_SEC			3
// Which mode to use


/* HC-SR04 Configs */
// GPIO used for HC-SR04 Trig/Echo pins
#define HCSR04_GPIO_RCC_APBxClockCmd 		RCC_APB2PeriphClockCmd
#define HCSR04_GPIO_CLK 				RCC_APB2Periph_GPIOB
#define HCSR04_GPIO_TYPE 				GPIOB
#define HCSR04_TRIG_PIN  				GPIO_Pin_8
#define HCSR04_ECHO_PIN  				GPIO_Pin_9
// TIM used for HC-SR04 timing
#define HCSR04_TIM_RCC_APBxClockCmd			RCC_APB1PeriphClockCmd
#define HCSR04_TIM_CLK 					RCC_APB1Periph_TIM2
#define HCSR04_TIM 							TIM2


/* WavPlayer Configs */
// TIM used to output pwm
#define PLAYER_TIM_RCC_APBxClockCmd			RCC_APB1PeriphClockCmd
#define PLAYER_TIM_CLK					RCC_APB1Periph_TIM4
#define PLAYER_TIM_PERIOD				256-1 // 8bit
#define PLAYER_TIM_PRESCALER		18-1 	// 72MHz/16KHz/256=17.578125
#define PLAYER_TIM							TIM4
#define PLAYER_TIM_NVIC_IRQ     TIM4_IRQn
#define PLAYER_TIM_IRQ_HANDLER	TIM4_IRQHandler
#define PLAYER_TIM_OCxInit     	TIM_OC1Init // CHx
#define PLAYER_TIM_OCxPLC    		TIM_OC1PreloadConfig
#define PLAYER_TIM_SET_OCx			TIM_SetCompare1
// GPIO used for sound tracks (Depend on TIMx and CHx)
#define PLAYER_GPIO_RCC_APBxClockCmd		RCC_APB2PeriphClockCmd
#define PLAYER_GPIO_CLK 				RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO
#define PLAYER_GPIO_TYPE 				GPIOB
#define PLAYER_GPIO_PIN					GPIO_Pin_6


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
