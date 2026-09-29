#include "max6675.h"

bool MAX6675_Read(SPI_HandleTypeDef *hspi, GPIO_TypeDef *cs_port,
                  uint16_t cs_pin, int16_t *temperature_c_x10)
{
    uint8_t rx[2] = {0};
    uint16_t raw;

    if (temperature_c_x10 == NULL)
        return false;

    HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);

    const HAL_StatusTypeDef status =
        HAL_SPI_Receive(hspi, rx, sizeof(rx), 100);

    HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);

    if (status != HAL_OK)
        return false;

    raw = ((uint16_t)rx[0] << 8) | rx[1];

    /* MAX6675 bit D2 indicates an open thermocouple. */
    if ((raw & 0x0004U) != 0U)
        return false;

    /* Bits D14..D3 represent temperature in 0.25 C increments. */
    *temperature_c_x10 = (int16_t)(((raw >> 3) * 25) / 10);

    return true;
}
