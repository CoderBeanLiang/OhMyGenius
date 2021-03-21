#include "configs.h"
#include "systick.h"
#include "motor.h"

int main(void)
{
	uint32_t delay_ms = 1;
	
	// Sometimes if your program runs well after download
	// but need reset manually after re-energizing,
	// then some magic delay before init maybe needed
	SysTick_Delay_ms(100);
	
	Motor_GPIO_Init();
	
	// Main loop
	while(1)
	{
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(1,0,0,0);// A
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(1,1,0,0);// AB
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(0,1,0,0);// B
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(0,1,1,0);// BC
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(0,0,1,0);// C
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(0,0,1,1);// CD
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(0,0,0,1);// D
		SysTick_Delay_ms(delay_ms);
		Motor_Drive(1,0,0,1);// DA
	}
}
