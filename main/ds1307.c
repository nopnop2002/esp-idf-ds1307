#include <string.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "ds1307.h"

#define CHECK_ARG(ARG) do { if (!ARG) return ESP_ERR_INVALID_ARG; } while (0)

uint8_t bcd2dec(uint8_t val)
{
    return (val >> 4) * 10 + (val & 0x0f);
}

uint8_t dec2bcd(uint8_t val)
{
    return ((val / 10) << 4) + (val % 10);
}

esp_err_t update_register(i2c_dev_t *dev, uint8_t reg, uint8_t mask, uint8_t val)
{
    CHECK_ARG(dev);

    uint8_t old;

    i2c_dev_read_reg(dev, reg, &old, 1);
    uint8_t buf = (old & mask) | val;
    esp_err_t res = i2c_dev_write_reg(dev, reg, &buf, 1);

    return res;
}

esp_err_t ds1307_init_desc(i2c_dev_t *dev, i2c_port_t port, gpio_num_t sda_gpio, gpio_num_t scl_gpio)
{
    CHECK_ARG(dev);

    dev->port = port;
    dev->addr = DS1307_ADDR;
    dev->sda_io_num = sda_gpio;
    dev->scl_io_num = scl_gpio;
    dev->clk_speed = I2C_FREQ_HZ;
    return i2c_master_init(port, sda_gpio, scl_gpio);
}

esp_err_t ds1307_start(i2c_dev_t *dev, bool start)
{
    return update_register(dev, TIME_REG, CH_MASK, start ? 0 : CH_BIT);
}

esp_err_t ds1307_is_running(i2c_dev_t *dev, bool *running)
{
    CHECK_ARG(dev);
    CHECK_ARG(running);

    uint8_t val;

    i2c_dev_read_reg(dev, TIME_REG, &val, 1);

    *running = val & CH_BIT;

    return ESP_OK;
}

esp_err_t ds1307_get_time(i2c_dev_t *dev, struct tm *time)
{
    CHECK_ARG(dev);
    CHECK_ARG(time);

    uint8_t buf[7];

    i2c_dev_read_reg(dev, TIME_REG, buf, 7);

    time->tm_sec = bcd2dec(buf[0] & SECONDS_MASK);
    time->tm_min = bcd2dec(buf[1]);
    if (buf[2] & HOUR12_BIT)
    {
        // RTC in 12-hour mode
        time->tm_hour = bcd2dec(buf[2] & HOUR12_MASK) - 1;
        if (buf[2] & PM_BIT)
            time->tm_hour += 12;
    }
    else
        time->tm_hour = bcd2dec(buf[2] & HOUR24_MASK);
    time->tm_wday = bcd2dec(buf[3]) - 1;
    time->tm_mday = bcd2dec(buf[4]);
    time->tm_mon  = bcd2dec(buf[5]) - 1;
    time->tm_year = bcd2dec(buf[6]) + 2000;

    return ESP_OK;
}

esp_err_t ds1307_set_time(i2c_dev_t *dev, const struct tm *time)
{
    CHECK_ARG(dev);
    CHECK_ARG(time);

    uint8_t buf[7] = {
        dec2bcd(time->tm_sec),
        dec2bcd(time->tm_min),
        dec2bcd(time->tm_hour),
        dec2bcd(time->tm_wday + 1),
        dec2bcd(time->tm_mday),
        dec2bcd(time->tm_mon + 1),
        dec2bcd(time->tm_year - 2000)
    };

    i2c_dev_write_reg(dev, TIME_REG, buf, sizeof(buf));

    return ESP_OK;
}

