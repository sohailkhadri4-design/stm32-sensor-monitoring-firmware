#ifndef UART_H
#define UART_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

void UART_Log(UART_HandleTypeDef *huart, const char *message);
void UART_LogInt(UART_HandleTypeDef *huart, const char *label, int32_t value);
void UART_LogFault(UART_HandleTypeDef *huart, const char *fault);

#endif /* UART_H */
