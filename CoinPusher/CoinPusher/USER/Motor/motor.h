#ifndef __MOTOR_H
#define __MOTOR_H

#include "stdint.h"
#include "stm32f10x.h"


void Motor_GPIO_Init(void);

void Motor_Drive(uint8_t a, uint8_t b, uint8_t c, uint8_t d);


#endif
