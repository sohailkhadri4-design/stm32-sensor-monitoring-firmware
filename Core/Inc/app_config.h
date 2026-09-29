#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/* Reference hardware: STM32F401RE Nucleo + BME280 + MAX6675. */

#define BME280_I2C_ADDRESS      (0x76U << 1)
#define MAX6675_CS_PORT         GPIOB
#define MAX6675_CS_PIN          GPIO_PIN_6

#define STATUS_LED_PORT         GPIOC
#define STATUS_LED_PIN          GPIO_PIN_13

#define SENSOR_POLL_MS          1000U

#endif /* APP_CONFIG_H */
