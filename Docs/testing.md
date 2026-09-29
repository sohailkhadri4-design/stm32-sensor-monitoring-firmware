# Firmware Verification Plan

This repository documents a reference verification plan. The tests are not claimed as physically completed because no original hardware project or laboratory results were supplied.

## Test matrix

| ID | Condition | Expected firmware behavior | Evidence |
|---|---|---|---|
| T01 | Normal startup | Startup banner and peripheral initialization | UART capture |
| T02 | BME280 at 0x76 | Chip ID accepted, sensor initialized | UART |
| T03 | BME280 disconnected | I2C transaction fails and fault is reported | UART + GPIO |
| T04 | MAX6675 connected | SPI frame received and temperature reported | UART |
| T05 | SPI interrupted | SPI communication fault reported | UART + GPIO |
| T06 | Open thermocouple | Sensor fault detected from MAX6675 status bit | UART + GPIO |
| T07 | Invalid sample | Measurement rejected | UART |
| T08 | UART at 115200 8-N-1 | Readable continuous diagnostics | Terminal screenshot |
| T09 | Fault output | PC13 changes state during fault | LED/multimeter |
| T10 | Sensor recovery | Normal STATUS: OK resumes | UART |

## Expected outputs

Normal:
    STM32 Sensor Monitor
    BME280: OK
    BME280 raw temperature: <value>
    BME280 raw pressure: <value>
    BME280 raw humidity: <value>
    MAX6675 temperature x10 C: <value>
    STATUS: OK

I2C fault:
    FAULT: I2C_COMMUNICATION

SPI fault:
    FAULT: SPI_COMMUNICATION

Invalid data:
    FAULT: INVALID_READING

## Pass criteria

A test is Pass only after the expected behavior is observed on the target hardware and evidence is recorded. Suggested evidence includes UART capture, logic-analyzer traces, wiring photographs, and STM32CubeIDE debug observations.

## Status

All tests are currently Planned. This keeps the repository technically honest and prevents simulated results from being presented as physical validation.
