#ifndef UART_H
#define UART_H

#include <stdint.h>

void UART_Init(void);
void UART_Write(const char *message);
void UART_WriteValue(const char *label, int32_t value);

#endif /* UART_H */
