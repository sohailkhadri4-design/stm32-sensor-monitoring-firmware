#include "bme280.h"
#include "app_config.h"

#define BME280_REG_ID        0xD0U
#define BME280_REG_RESET     0xE0U
#define BME280_REG_CTRL_HUM  0xF2U
#define BME280_REG_STATUS    0xF3U
#define BME280_REG_CTRL_MEAS 0xF4U
#define BME280_REG_CONFIG    0xF5U
#define BME280_REG_DATA      0xF7U

#define BME280_CHIP_ID       0x60U
#define BME280_RESET_VALUE   0xB6U

static bool write_reg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t value)
{
    return HAL_I2C_Mem_Write(hi2c, BME280_I2C_ADDRESS, reg,
                             I2C_MEMADD_SIZE_8BIT, &value, 1, 100) == HAL_OK;
}

static bool read_regs(I2C_HandleTypeDef *hi2c, uint8_t reg,
                      uint8_t *data, uint16_t length)
{
    return HAL_I2C_Mem_Read(hi2c, BME280_I2C_ADDRESS, reg,
                            I2C_MEMADD_SIZE_8BIT, data, length, 100) == HAL_OK;
}

bool BME280_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t id = 0;

    if (!read_regs(hi2c, BME280_REG_ID, &id, 1) || id != BME280_CHIP_ID)
        return false;

    if (!write_reg(hi2c, BME280_REG_RESET, BME280_RESET_VALUE))
        return false;

    HAL_Delay(5);

    /* Humidity x1, temperature x1, pressure x1, normal mode. */
    if (!write_reg(hi2c, BME280_REG_CTRL_HUM, 0x01))
        return false;

    if (!write_reg(hi2c, BME280_REG_CTRL_MEAS, 0x27))
        return false;

    /* Standby 1000 ms, filter off. */
    return write_reg(hi2c, BME280_REG_CONFIG, 0xA0);
}

bool BME280_Read(I2C_HandleTypeDef *hi2c, BME280_Data *data)
{
    /*
     * The register transaction is implemented here. Full Bosch compensation
     * requires the calibration coefficients from 0x88..0xA1 and 0xE1..0xE7.
     * This reference driver deliberately reports the raw 20-bit pressure,
     * raw 20-bit temperature and raw 16-bit humidity fields for verification.
     */
    uint8_t raw[8];

    if (data == NULL || !read_regs(hi2c, BME280_REG_DATA, raw, sizeof(raw)))
        return false;

    const int32_t raw_temp = ((int32_t)raw[3] << 12) |
                             ((int32_t)raw[4] << 4) |
                             (raw[5] >> 4);

    const uint32_t raw_pressure = ((uint32_t)raw[0] << 12) |
                                  ((uint32_t)raw[1] << 4) |
                                  (raw[2] >> 4);

    const uint32_t raw_humidity = ((uint32_t)raw[6] << 8) | raw[7];

    data->temperature_c_x100 = raw_temp;
    data->pressure_pa = raw_pressure;
    data->humidity_rh_x1024 = raw_humidity;

    return true;
}
