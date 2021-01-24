#include "configs.h"
#include "systick.h"
#include "print.h"
#include "HCSR04.h"
#include "player.h"
#include "led.h"


int main(void)
{
	uint32_t distance = 0;
	
	// Sometimes if your program runs well after download
	// but need reset manually after re-energizing,
	// then some delay before init maybe a good solution
	SysTick_Delay_ms(100);
	
	//Print_Init();
	LED_Init();
	HCSR04_Init();
	WavPlayer_Init();
	
	/* Infinite loop */
	while(1)
	{
		distance = HCSR04_GetDistanceMM();
		//printf("Distance = %i mm", distance);
		
		if (distance < 300){
			PlayWav();
			// LED twinkle
			LED_ON();
			SysTick_Delay_ms(200);
			LED_OFF();
			SysTick_Delay_ms(200);
			LED_ON();
			SysTick_Delay_ms(200);
			LED_OFF();
			SysTick_Delay_ms(200);
			LED_ON();
			SysTick_Delay_ms(200);
			LED_OFF();
		}
		
		SysTick_Delay_ms(CHECK_DURATION_SEC * 1000);
	}
}
