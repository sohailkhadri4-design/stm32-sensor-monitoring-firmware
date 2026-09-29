#ifndef FAULT_DETECTION_H
#define FAULT_DETECTION_H

#include <stdbool.h>

typedef enum
{
    FAULT_NONE = 0,
    FAULT_I2C_COMMUNICATION,
    FAULT_SPI_COMMUNICATION,
    FAULT_SENSOR_DISCONNECTED,
    FAULT_INVALID_READING
} FaultType;

FaultType Fault_Check(bool i2c_ok, bool spi_ok, bool readings_valid);
const char *Fault_ToString(FaultType fault);

#endif /* FAULT_DETECTION_H */
