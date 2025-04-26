//
// Created by zhenyu on 25-4-20.
//

#ifndef BSP_IIC_H
#define BSP_IIC_H

#include "stm32f4xx_hal.h"
#include "common.h"

#define IIC_SCL_PORT  GPIOE
#define IIC_SCL_PIN  GPIO_PIN_0

#define IIC_SDA_PORT  GPIOE
#define IIC_SDA_PIN  GPIO_PIN_1

#define SDA(x)     do{(x) ? HAL_GPIO_WritePin(IIC_SDA_PORT,IIC_SDA_PIN,1) : HAL_GPIO_WritePin(IIC_SDA_PORT,IIC_SDA_PIN,0);}while(0)
#define SCL(x)     do{(x) ? HAL_GPIO_WritePin(IIC_SCL_PORT,IIC_SCL_PIN,1) : HAL_GPIO_WritePin(IIC_SCL_PORT,IIC_SCL_PIN,0);}while(0)



#endif //BSP_IIC_H
