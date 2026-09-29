#include "uart.h"
#include <stdio.h>

/*
 * Hardware integration point.
 * Replace the functions below with the actual STM32 HAL UART transmit
 * implementation from the target STM32CubeIDE project.
 */

void UART_Init(void)
{
    /* TODO: initialize or use the generated STM32 UART peripheral. */
}

void UART_Write(const char *message)
{
    (void)message;
    /* TODO: HAL_UART_Transmit(...). */
}

void UART_WriteValue(const char *label, int32_t value)
{
    char buffer[64];
    (void)snprintf(buffer, sizeof(buffer), "%s: %ld\r\n",
                   label, (long)value);
    UART_Write(buffer);
}
