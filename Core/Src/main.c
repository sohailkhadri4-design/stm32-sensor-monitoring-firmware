#include "main.h"
#include "sensor.h"
#include "uart.h"
#include "fault_detection.h"

void App_Init(void)
{
    UART_Init();
    Sensor_Init();
}

void App_Run(void)
{
    SensorReading reading = Sensor_Read();

    if (reading.valid)
    {
        UART_WriteValue("Sensor", reading.value);
    }
    else
    {
        FaultType fault = Fault_Check(true, false);
        UART_Write("Fault: ");
        UART_Write(Fault_ToString(fault));
        UART_Write("\r\n");
    }
}

/*
 * The real STM32CubeIDE project should provide the MCU startup code,
 * HAL initialization, SystemClock_Config(), peripheral initialization,
 * and the final main() function generated for the selected MCU.
 */
