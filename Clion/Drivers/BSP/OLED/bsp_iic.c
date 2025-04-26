//
// Created by zhenyu on 25-4-20.
//

#include "bsp_iic.h"

void BSP_IIC_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    __HAL_RCC_GPIOE_CLK_ENABLE();  //注意开启的GPIO时钟，这里都是GPIOE所以只有一个

    GPIO_InitStructure.Pin = IIC_SCL_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(IIC_SCL_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = IIC_SDA_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(IIC_SDA_PORT, &GPIO_InitStructure);
}

void BSP_IIC_Delay(void)
{
    HAL_Delay_us(5);//注意初始化us延时函数
}

void BSP_IIC_Start(void)
{
    SCL(1);
    SDA(1);
    BSP_IIC_Delay();
    SDA(0);
    BSP_IIC_Delay();
    SCL(0);
    BSP_IIC_Delay();
}

void BSP_IIC_Stop(void)
{
    SCL(0);
    SCL(1);
    BSP_IIC_Delay();
    SDA(1);
    BSP_IIC_Delay();
}

void BSP_IIC_Ack(void)
{
    SCL(0);
    BSP_IIC_Delay();
    SDA(0);
    BSP_IIC_Delay();
    SCL(1);
    BSP_IIC_Delay();
    SCL(0);
    BSP_IIC_Delay();
    SDA(1);
    BSP_IIC_Delay();
}

void BSP_IIC_NAck(void)
{
    SDA(1);
    BSP_IIC_Delay();
    SCL(1);
    BSP_IIC_Delay();
    SCL(0);
    BSP_IIC_Delay();
}

uint8_t BSP_IIC_WaitAck(void)
{
    uint8_t ret = 0;
    SDA(1);
    BSP_IIC_Delay();
    SCL(1);
    BSP_IIC_Delay();
    if(HAL_GPIO_ReadPin(IIC_SDA_PORT,IIC_SDA_PIN) == GPIO_PIN_SET)
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    SCL(0);
    BSP_IIC_Delay();
    return ret;
}