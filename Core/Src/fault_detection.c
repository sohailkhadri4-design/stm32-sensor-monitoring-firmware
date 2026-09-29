#include "fault_detection.h"

FaultType Fault_Check(bool communication_ok, bool reading_valid)
{
    if (!communication_ok)
    {
        return FAULT_I2C_COMMUNICATION;
    }

    if (!reading_valid)
    {
        return FAULT_INVALID_READING;
    }

    return FAULT_NONE;
}

const char *Fault_ToString(FaultType fault)
{
    switch (fault)
    {
        case FAULT_SENSOR_DISCONNECTED:
            return "SENSOR_DISCONNECTED";
        case FAULT_I2C_COMMUNICATION:
            return "I2C_COMMUNICATION";
        case FAULT_SPI_COMMUNICATION:
            return "SPI_COMMUNICATION";
        case FAULT_INVALID_READING:
            return "INVALID_READING";
        case FAULT_NONE:
        default:
            return "NONE";
    }
}
