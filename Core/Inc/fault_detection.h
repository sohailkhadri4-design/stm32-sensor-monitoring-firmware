#ifndef FAULT_DETECTION_H
#define FAULT_DETECTION_H

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    FAULT_NONE = 0,
    FAULT_SENSOR_DISCONNECTED,
    FAULT_I2C_COMMUNICATION,
    FAULT_SPI_COMMUNICATION,
    FAULT_INVALID_READING
} FaultType;

FaultType Fault_Check(bool communication_ok, bool reading_valid);
const char *Fault_ToString(FaultType fault);

#endif /* FAULT_DETECTION_H */
