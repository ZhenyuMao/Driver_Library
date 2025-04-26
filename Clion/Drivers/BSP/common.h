//
// Created by zhenyu on 25-4-20.
//

#ifndef COMMON_H
#define COMMON_H

#include "stm32f4xx_hal.h"

void HAL_Delay_us_init(uint8_t SYSCLK);
void HAL_Delay_us(uint32_t nus);

#endif //COMMON_H
