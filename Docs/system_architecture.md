# System Architecture

## Overview

This project is structured as a layered STM32 firmware application for sensor monitoring, communication, GPIO control, UART diagnostics, and fault handling.

> Hardware-specific MCU, sensor models, pin mappings, clock configuration, and peripheral instances should be documented here after the actual STM32CubeIDE project is integrated.

## Architecture

```text
                         +----------------------+
                         |      STM32 MCU       |
                         |   Application Layer  |
                         +----------+-----------+
                                    |
              +---------------------+---------------------+
              |                     |                     |
           Sensor                Fault                 GPIO
         Management            Detection              Control
              |                     |                     |
       +------+------+              |              Actuators /
       |             |              |               Status LED
      I2C           SPI             |
       |             |              |
    Sensors       Sensors           |
       +-------------+--------------+
                     |
                   UART
                     |
              PC / Serial Monitor
```

## Software layers

1. **Application layer**  
   Coordinates sensor acquisition, validation, fault handling, and reporting.

2. **Driver / peripheral layer**  
   Provides I2C, SPI, UART, and GPIO access.

3. **Fault handling layer**  
   Detects communication failures, invalid readings, and disconnected or unresponsive devices.

4. **Hardware abstraction**  
   STM32 HAL or the project's generated peripheral drivers provide MCU-specific access.

## Data flow

```text
Sensor
  |
  v
I2C / SPI transaction
  |
  v
Sensor validation
  |
  +---- invalid / timeout ----> Fault handler
  |
  v
Application state
  |
  v
UART diagnostic output
```

## Hardware mapping

Complete this section from the real hardware configuration:

| Function | Interface | MCU peripheral | Device / pin |
|---|---|---|---|
| Sensor 1 | I2C | TODO | TODO |
| Sensor 2 | SPI | TODO | TODO |
| Debug output | UART | TODO | TODO |
| Status | GPIO | TODO | TODO |

## Design goals

- Keep hardware access separated from application logic.
- Make communication failures visible through diagnostics.
- Validate sensor data before using it.
- Keep fault handling deterministic and easy to test.
