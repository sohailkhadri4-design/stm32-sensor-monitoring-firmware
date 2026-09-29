#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
    GPIO_InitTypeDef g = {0};
    if (hi2c->Instance == I2C1) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_I2C1_CLK_ENABLE();
        g.Pin = GPIO_PIN_8 | GPIO_PIN_9;
        g.Mode = GPIO_MODE_AF_OD;
        g.Pull = GPIO_PULLUP;
        g.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        g.Alternate = GPIO_AF4_I2C1;
        HAL_GPIO_Init(GPIOB, &g);
    }
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
    GPIO_InitTypeDef g = {0};
    if (hspi->Instance == SPI1) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_SPI1_CLK_ENABLE();
        g.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
        g.Mode = GPIO_MODE_AF_PP;
        g.Pull = GPIO_NOPULL;
        g.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        g.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(GPIOA, &g);
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef g = {0};
    if (huart->Instance == USART2) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_USART2_CLK_ENABLE();
        g.Pin = GPIO_PIN_2 | GPIO_PIN_3;
        g.Mode = GPIO_MODE_AF_PP;
        g.Pull = GPIO_PULLUP;
        g.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        g.Alternate = GPIO_AF7_USART2;
        HAL_GPIO_Init(GPIOA, &g);
    }
}
