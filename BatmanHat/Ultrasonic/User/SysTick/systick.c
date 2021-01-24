#include "systick.h"

void SysTick_Delay_us(uint32_t us)
{
	SysTick_Config(72);
	for(uint32_t i=0; i<us; i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Delay_ms(uint32_t ms)
{
	SysTick_Config(72000);
	for(uint32_t i=0; i<ms; i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


/* Used for tic and toc */
uint16_t OverFlowTimes = 0;

void SysTick_Handler(void)
{
	OverFlowTimes++;
}


/**
	* Start timing
	*/
void SysTick_TIC(void)
{
	SysTick->CTRL |= (1<<2);   // Chose clock, HCLK
	SysTick->CTRL |= (1<<1);   // INT Enable
	SysTick->VAL = 0X00;
	SysTick->LOAD = 0XFFFFFF;
	SysTick->CTRL |= (1<<0);   // Start count-down
}


/**
  * Stop timing and get the value
	*/
float SysTick_TOC(void)
{
	float elaspTime;
	uint32_t clkNum;
	SysTick->CTRL &= ~(1<<0);		// Stop count-down
	clkNum = SysTick->VAL;			// Read value
	elaspTime = (OverFlowTimes * ((float)0xffffff/SystemCoreClock) + (float)(0xffffff-clkNum)/SystemCoreClock);
	OverFlowTimes = 0;
	return elaspTime;
}
