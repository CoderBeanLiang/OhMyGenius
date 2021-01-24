#include "led.h"
#include "configs.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	LED_RCC_APBxClockCmd(LED_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED_GPIO_TYPE, &GPIO_InitStruct);
}


void LED_ON(void)
{
	GPIO_SetBits(LED_GPIO_TYPE, LED_GPIO_PIN);
}


void LED_OFF(void)
{
	GPIO_ResetBits(LED_GPIO_TYPE, LED_GPIO_PIN);
}
