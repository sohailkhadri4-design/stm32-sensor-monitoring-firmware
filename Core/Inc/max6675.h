#ifndef MAX6675_H
#define MAX6675_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

bool MAX6675_Read(SPI_HandleTypeDef *hspi, GPIO_TypeDef *cs_port,
                  uint16_t cs_pin, int16_t *temperature_c_x10);

#endif /* MAX6675_H */
