#include "wav03.h"
#include "configs.h"
#include "player.h"
#include "stm32f10x.h"

void WavPlayer_Init(void)
{
	// Init GPIO (Depend on TIMx and CHx you chose)
	PLAYER_GPIO_RCC_APBxClockCmd(PLAYER_GPIO_CLK, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = PLAYER_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PLAYER_GPIO_TYPE, &GPIO_InitStruct);
	
	
	// Init TIM Base (16KHz 8bit pcm format wav)
	PLAYER_TIM_RCC_APBxClockCmd(PLAYER_TIM_CLK, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_Period=PLAYER_TIM_PERIOD;// 8bit
	TIM_TimeBaseInitStruct.TIM_Prescaler=PLAYER_TIM_PRESCALER;// 72MHz/16KHz/256=17.578125
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(PLAYER_TIM, &TIM_TimeBaseInitStruct);
	
	// Init TIM PWM
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	PLAYER_TIM_OCxInit(PLAYER_TIM, &TIM_OCInitStruct);// Use CHx
	PLAYER_TIM_OCxPLC(PLAYER_TIM, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(PLAYER_TIM, ENABLE);
	
	// Init TIM INT
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStruct.NVIC_IRQChannel = PLAYER_TIM_NVIC_IRQ;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_ITConfig(PLAYER_TIM, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(PLAYER_TIM, DISABLE);
}


int32_t audioDataIndex = 0;


void PLAYER_TIM_IRQ_HANDLER(void)
{
	if (TIM_GetITStatus(PLAYER_TIM, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(PLAYER_TIM, TIM_IT_Update);
		
		if (audioDataIndex < AudioDataStartIndex)
		{
			audioDataIndex = AudioDataStartIndex;
		}
		else if (audioDataIndex >= AudioDataEndIndex)
		{
			TIM_Cmd(PLAYER_TIM, DISABLE);
			GPIO_ResetBits(PLAYER_GPIO_TYPE, PLAYER_GPIO_PIN);
			audioDataIndex  = 0;
		}
		else
		{
			// If default sound volume is too loud, then use '>>'/'<<' to half/double
			PLAYER_TIM_SET_OCx(PLAYER_TIM, AudioData[audioDataIndex]>>1);
			audioDataIndex++;
		}
	}
}


void PlayWav(void)
{
	audioDataIndex = AudioDataStartIndex;
	TIM_Cmd(PLAYER_TIM, ENABLE);
}
