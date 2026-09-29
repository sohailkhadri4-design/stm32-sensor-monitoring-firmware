#include "stm32f4xx_hal.h"
#include "app_config.h"
#include "bme280.h"
#include "max6675.h"
#include "fault_detection.h"
#include "uart.h"

I2C_HandleTypeDef hi2c1;
SPI_HandleTypeDef hspi1;
UART_HandleTypeDef huart2;

static void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_I2C1_Init();
    MX_SPI1_Init();
    MX_USART2_UART_Init();

    UART_Log(&huart2, "\r\nSTM32 Sensor Monitor\r\n");
    UART_Log(&huart2, "Reference: STM32F401RE + BME280 + MAX6675\r\n");

    const bool bme_ok = BME280_Init(&hi2c1);

    while (1)
    {
        BME280_Data bme = {0};
        int16_t thermocouple_c_x10 = 0;

        const bool i2c_ok = bme_ok && BME280_Read(&hi2c1, &bme);
        const bool spi_ok = MAX6675_Read(&hspi1, MAX6675_CS_PORT,
                                         MAX6675_CS_PIN,
                                         &thermocouple_c_x10);
        const bool valid = i2c_ok && spi_ok && (bme.pressure_pa > 0U);
        const FaultType fault = Fault_Check(i2c_ok, spi_ok, valid);

        if (fault != FAULT_NONE)
        {
            HAL_GPIO_WritePin(STATUS_LED_PORT, STATUS_LED_PIN, GPIO_PIN_SET);
            UART_LogFault(&huart2, Fault_ToString(fault));
        }
        else
        {
            HAL_GPIO_WritePin(STATUS_LED_PORT, STATUS_LED_PIN, GPIO_PIN_RESET);
            UART_LogInt(&huart2, "BME280 raw temperature", bme.temperature_c_x100);
            UART_LogInt(&huart2, "BME280 raw pressure", (int32_t)bme.pressure_pa);
            UART_LogInt(&huart2, "BME280 raw humidity", (int32_t)bme.humidity_rh_x1024);
            UART_LogInt(&huart2, "MAX6675 temperature x10 C", thermocouple_c_x10);
            UART_Log(&huart2, "STATUS: OK\r\n");
        }

        HAL_Delay(SENSOR_POLL_MS);
    }
}

/*
 * These functions are integration points for the generated STM32CubeIDE
 * initialization code. The reference pin map is documented in
 * Docs/hardware_setup.md.
 */
static void SystemClock_Config(void) {}
static void MX_GPIO_Init(void) {}
static void MX_I2C1_Init(void) {}
static void MX_SPI1_Init(void) {}
static void MX_USART2_UART_Init(void) {}
