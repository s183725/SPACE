#ifndef _CLOCK_H_
#define _CLOCK_H_

#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001

#include "stm32f30x_conf.h"

void timerINIT();

void TIM2_IRQHandler(void);

#endif
