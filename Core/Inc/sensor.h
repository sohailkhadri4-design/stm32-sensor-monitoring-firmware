#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    bool valid;
    int32_t value;
} SensorReading;

bool Sensor_Init(void);
SensorReading Sensor_Read(void);

#endif /* SENSOR_H */
