#ifndef BME280_H
#define BME280_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    int32_t temperature_c_x100;
    uint32_t pressure_pa;
    uint32_t humidity_rh_x1024;
} BME280_Data;

bool BME280_Init(I2C_HandleTypeDef *hi2c);
bool BME280_Read(I2C_HandleTypeDef *hi2c, BME280_Data *data);

#endif /* BME280_H */
