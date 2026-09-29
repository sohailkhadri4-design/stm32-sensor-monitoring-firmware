#include "sensor.h"

/*
 * Hardware integration point.
 *
 * Replace this implementation with the actual STM32 HAL I2C/SPI
 * transaction used by the target sensor.
 */

bool Sensor_Init(void)
{
    return true;
}

SensorReading Sensor_Read(void)
{
    SensorReading reading = {
        .valid = false,
        .value = 0
    };

    /*
     * TODO:
     * 1. Read the real sensor over I2C or SPI.
     * 2. Check the peripheral return status.
     * 3. Validate the received measurement.
     * 4. Set reading.valid and reading.value.
     */

    return reading;
}
