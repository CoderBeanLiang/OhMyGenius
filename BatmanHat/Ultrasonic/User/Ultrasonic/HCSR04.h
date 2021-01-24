#ifndef __HCSR04_H
#define __HCSR04_H

#include <stdint.h>


/**
  * @brief  Config HC-SR04 Trig/Echo with GPIO pins, and init TIM clock.
  */
void HCSR04_Init(void);

/**
  * @brief  Get the time how long Echo pin keeps 'HIGH'.
	* @retval Echo pin 'HIGH' time (us: microsecond)
  */
uint32_t HCSR04_GetEchoHighTimeUS(void);

/**
  * @brief  Get distance between HC-SR04 and the obstacle.
  * @retval Distance (mm: millimeter)
  */
uint32_t HCSR04_GetDistanceMM(void);


#endif
