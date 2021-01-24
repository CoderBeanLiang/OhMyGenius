#include "configs.h"
#include "systick.h"
#include "print.h"

int waiting;

/**
  * @brief  Config HC-SR04 Trig/Echo with GPIO pins, and init TIM clock.
  * @param  None
  * @retval None
  */
void HCSR04_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	HCSR04_GPIO_RCC_APBxClockCmd(HCSR04_GPIO_CLK, ENABLE);
	
	// Trig
	GPIO_InitStruct.GPIO_Pin = HCSR04_TRIG_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HCSR04_GPIO_TYPE, &GPIO_InitStruct);
	
	// Echo
	GPIO_InitStruct.GPIO_Pin = HCSR04_ECHO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(HCSR04_GPIO_TYPE, &GPIO_InitStruct);
	
	// Init TIM
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	HCSR04_TIM_RCC_APBxClockCmd(HCSR04_TIM_CLK, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Period=65535;
	TIM_TimeBaseInitStruct.TIM_Prescaler=72-1;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;

	TIM_DeInit(HCSR04_TIM);
	TIM_TimeBaseInit(HCSR04_TIM, &TIM_TimeBaseInitStruct);
	TIM_ClearFlag(HCSR04_TIM, TIM_FLAG_Update);
	TIM_Cmd(HCSR04_TIM, DISABLE);
}


/**
  * @brief  Use TIM to count how long Echo 'HIGH' last for.
  * @param  None
	* @retval Echo pin 'HIGH' time (us: microsecond)
  */
uint32_t HCSR04_GetEchoHighTimeUS(void)
{
	// Send 'HIGH' to Trig pin last for over 10us, then set to 'LOW'
	GPIO_ResetBits(HCSR04_GPIO_TYPE, HCSR04_TRIG_PIN);
	GPIO_SetBits(HCSR04_GPIO_TYPE, HCSR04_TRIG_PIN);
	SysTick_Delay_us(20);
	GPIO_ResetBits(HCSR04_GPIO_TYPE, HCSR04_TRIG_PIN);
	
	// Wait for ECHO to 'HIGH', then start timing
	while(GPIO_ReadInputDataBit(HCSR04_GPIO_TYPE, HCSR04_ECHO_PIN) != 1);
	TIM_Cmd(HCSR04_TIM, ENABLE);
	HCSR04_TIM->CNT = 0;
	
	// Wait for ECHO to 'LOW', then get the 'HIGH' time
	while(GPIO_ReadInputDataBit(HCSR04_GPIO_TYPE, HCSR04_ECHO_PIN) != 0);
	TIM_Cmd(HCSR04_TIM, DISABLE);
	uint32_t time = TIM_GetCounter(HCSR04_TIM);
	TIM_SetCounter(HCSR04_TIM, 0);
	return time;
}

/**
  * @brief  Calculate distance between HC-SR04 and the obstacle.
						Dis(mm) = 340000(mm/s) * time(s) / 2 = 0.17(mm/us) * time(us)
  * @param  None
  * @retval Distance (mm: millimeter)
  */
uint32_t HCSR04_GetDistanceMM(void)
{
	uint32_t time = HCSR04_GetEchoHighTimeUS();
	return 170 * time / 1000;
}
