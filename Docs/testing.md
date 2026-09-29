# Firmware Testing

This document defines the planned and implemented verification cases for the sensor-monitoring firmware.

## Test matrix

| ID | Test | Setup | Expected behavior | Result |
|---|---|---|---|---|
| T01 | Normal sensor communication | Sensor connected and responding | Valid data is acquired and reported | TODO |
| T02 | Sensor disconnected | Disconnect target sensor | Communication error is detected and reported | TODO |
| T03 | I2C device not responding | Use an unavailable I2C address / disconnected device | Timeout or NACK is handled without uncontrolled behavior | TODO |
| T04 | SPI communication failure | Interrupt or remove SPI device connection | SPI transaction failure is detected | TODO |
| T05 | Invalid sensor reading | Provide an out-of-range or invalid value | Reading is rejected or flagged | TODO |
| T06 | UART verification | Connect serial monitor | Diagnostic messages are readable and correctly formatted | TODO |
| T07 | GPIO verification | Observe configured GPIO output | Output changes according to firmware state | TODO |

## Fault-handling expectations

The firmware should:

- Detect communication timeouts or failed transactions.
- Avoid treating invalid data as a valid measurement.
- Report useful fault information through UART.
- Continue operating safely where the hardware and application design permit.
- Keep fault states distinguishable from normal sensor data.

## UART verification

Record the actual configuration from STM32CubeIDE after hardware integration:

- Baud rate: TODO
- Data bits: TODO
- Stop bits: TODO
- Parity: TODO
- Flow control: TODO

## Evidence

Add screenshots, serial-terminal captures, logic-analyzer traces, or photographs of the test setup under `Images/` when available.

## Important

The repository currently contains documentation and firmware scaffolding. Test results marked `TODO` must be replaced with measured results from the real hardware before presenting them as completed tests.
