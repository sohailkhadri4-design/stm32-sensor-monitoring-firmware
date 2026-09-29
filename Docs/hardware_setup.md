# Reference Hardware Setup

This repository uses a concrete reference configuration so the firmware can be studied and built as an embedded-systems example.

## Target

- STM32F401RE Nucleo-class board
- BME280 environmental sensor over I2C
- MAX6675 thermocouple interface over SPI
- USART2 for diagnostics
- PC13 status output

## Suggested connections

### BME280

| BME280 | STM32F401RE |
|---|---|
| VCC | 3.3 V |
| GND | GND |
| SCL | PB8 / I2C1_SCL |
| SDA | PB9 / I2C1_SDA |
| Address | 0x76 reference |

### MAX6675

| MAX6675 | STM32F401RE |
|---|---|
| VCC | 3.3 V |
| GND | GND |
| SCK | PA5 / SPI1_SCK |
| SO | PA6 / SPI1_MISO |
| CS | PB6 |
| SI | Not used |

### UART

| UART | STM32F401RE |
|---|---|
| TX | PA2 / USART2_TX |
| RX | PA3 / USART2_RX |
| Format | 115200, 8-N-1 |

### Status

PC13 is used as the reference fault-status output.

## Safety and verification

This is a reference design created for the repository. It has not been presented as physically tested hardware. Before building it, verify the exact Nucleo board pin alternate functions, sensor breakout voltage requirements, pull-ups, SPI timing, and power connections against the device documentation.

## Firmware flow

1. Initialize STM32 HAL and peripherals.
2. Probe and configure the BME280.
3. Read BME280 and MAX6675 data periodically.
4. Check communication and measurement validity.
5. Print measurements or a fault code over UART.
6. Drive the status output when a fault is detected.
