# STM32 Sensor Monitoring & Communication Firmware

Embedded C firmware project for an STM32-based sensor monitoring system. The project is organized around sensor acquisition, I2C/SPI communication, UART diagnostics, GPIO control, and fault detection.

> **Project status:** This repository now contains a self-contained reference firmware design using an STM32F401RE-class target, BME280 over I2C, MAX6675 over SPI, UART diagnostics, GPIO status indication, and documented fault handling. It is a reference implementation, not a record of physical hardware testing.

## Project Overview

The goal is to build a maintainable STM32 firmware application that can:

- Acquire sensor data through I2C and SPI.
- Validate sensor readings before using them.
- Report measurements and faults through UART.
- Control GPIO-based status or actuator outputs.
- Detect communication and sensor faults.
- Keep application logic separated from hardware-specific drivers.

## Features

- Embedded C application structure
- STM32-oriented HAL integration points
- I2C sensor communication interface
- SPI sensor communication interface
- UART diagnostic logging
- GPIO control integration point
- Sensor-data validation
- Fault detection and reporting
- Test-case documentation
- System architecture documentation

## Hardware

The reference hardware configuration used by this implementation is:

| Component | Details |
|---|---|
| Microcontroller | STM32 MCU - **TODO: specify exact part/board** |
| I2C sensor | **TODO: specify sensor** |
| SPI sensor | **TODO: specify sensor** |
| UART interface | **TODO: specify peripheral and settings** |
| GPIO | **TODO: specify pins / connected device** |
| Power | **TODO: specify supply arrangement** |

## Software & Tools

- Embedded C
- STM32CubeIDE
- STM32 HAL
- Git and GitHub
- UART serial terminal
- Optional: logic analyzer / oscilloscope for communication debugging

## System Architecture

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

See [system architecture](Docs/system_architecture.md) for the detailed design.

## Firmware Flow

```text
Initialize peripherals
        |
        v
Initialize sensors
        |
        v
Read sensor data
        |
        v
Validate communication and measurement
        |
    +---+---+
    |       |
   OK     Fault
    |       |
    v       v
Report    Fault
value     handling
    |       |
    +---+---+
        |
        v
Continue monitoring
```

## I2C Communication

The I2C integration point is designed for sensor transactions such as:

1. Select the target device address.
2. Transmit the required register or command.
3. Receive sensor data.
4. Check the STM32 HAL transaction result.
5. Validate the received measurement.
6. Pass valid data to the application or report a fault.

The actual I2C peripheral instance, address, timing, and sensor register map must be documented from the target hardware.

## SPI Communication

The SPI integration follows the same separation between application logic and hardware access:

1. Configure the SPI peripheral.
2. Assert the target chip-select GPIO.
3. Transfer the required command/data.
4. Deassert chip select.
5. Check the transaction result.
6. Validate the received data.

The exact SPI mode, clock rate, chip-select pin, and sensor protocol are hardware-specific and should be filled in from the actual implementation.

## UART Logging

UART is used as a diagnostic interface for measurements and fault messages.

Example format:

```text
Sensor: 123
Sensor: 124
Fault: I2C_COMMUNICATION
Sensor: 126
```

The example above is illustrative only. Replace it with an actual serial-terminal capture after hardware testing.

## GPIO Control

GPIO can be used for:

- Status indication
- Sensor reset lines
- Chip-select signals for SPI devices
- Actuator control
- Fault indication

Actual pin assignments should be documented after importing the real STM32CubeIDE configuration.

## Fault Detection

The project includes a fault-detection interface for conditions such as:

- Sensor disconnected
- I2C communication failure
- SPI communication failure
- Invalid sensor reading

The current scaffold separates fault classification from the hardware transaction. The final implementation should map each fault to the actual peripheral return status and hardware behavior.

## Project Structure

```text
stm32-sensor-monitoring-firmware/
|
+-- Core/
|   +-- Inc/
|   |   +-- main.h
|   |   +-- sensor.h
|   |   +-- uart.h
|   |   +-- fault_detection.h
|   |
|   +-- Src/
|       +-- main.c
|       +-- sensor.c
|       +-- uart.c
|       +-- fault_detection.c
|
+-- Drivers/
|   +-- I2C/
|   +-- SPI/
|
+-- Docs/
|   +-- system_architecture.md
|   +-- testing.md
|
+-- Images/
|
+-- .gitignore
+-- LICENSE
+-- README.md
```

## Testing

The planned verification matrix covers:

| Test | Purpose |
|---|---|
| Normal sensor communication | Confirm valid data acquisition |
| Sensor disconnected | Verify fault detection |
| I2C device not responding | Verify timeout/NACK handling |
| SPI communication failure | Verify SPI fault handling |
| Invalid sensor reading | Verify data validation |
| UART communication | Verify diagnostic output |
| GPIO output | Verify configured output behavior |

Detailed procedures and result fields are available in [Docs/testing.md](Docs/testing.md).

## Development Notes

This repository deliberately avoids inventing MCU-specific details. The next implementation step is to integrate the actual STM32CubeIDE project so that generated startup code, peripheral initialization, HAL handles, sensor drivers, clock configuration, and real pin mappings match the hardware.

## Future Improvements

- Integrate the target STM32CubeIDE project.
- Add real I2C and SPI sensor drivers.
- Add configurable sensor thresholds.
- Add structured fault codes.
- Add watchdog handling.
- Add automated host-side tests where practical.
- Add UART log captures and hardware test photographs.
- Add CI checks for source formatting and static analysis.

## Author

**Syed Sohel Khadri**

Embedded Firmware | STM32 | ARM Cortex-M | Embedded C

- GitHub: [sohailkhadri4-design](https://github.com/sohailkhadri4-design)
- LinkedIn: [Syed Sohel Khadri](https://www.linkedin.com/in/syed-sohel-khadri-7b570b381/)

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE).
