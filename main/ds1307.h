#ifndef MAIN_DS1307_H__
#define MAIN_DS1307_H__

#include <time.h>
#include <stdbool.h>
#include "driver/i2c.h"

#include "i2cdev.h"

#define DS1307_ADDR 0x68 //!< I2C address

#define RAM_SIZE 56

#define TIME_REG    0
#define CONTROL_REG 7
#define RAM_REG     8

#define CH_BIT      (1 << 7)
#define HOUR12_BIT  (1 << 6)
#define PM_BIT      (1 << 5)
#define SQWE_BIT    (1 << 4)
#define OUT_BIT     (1 << 7)

#define CH_MASK      0x7f
#define SECONDS_MASK 0x7f
#define HOUR12_MASK  0x1f
#define HOUR24_MASK  0x3f
#define SQWEF_MASK   0x03
#define SQWE_MASK    0xef
#define OUT_MASK     0x7

uint8_t bcd2dec(uint8_t val);
uint8_t dec2bcd(uint8_t val);
esp_err_t update_register(i2c_dev_t *dev, uint8_t reg, uint8_t mask, uint8_t val);
esp_err_t ds1307_init_desc(i2c_dev_t *dev, i2c_port_t port, gpio_num_t sda_gpio, gpio_num_t scl_gpio);
esp_err_t ds1307_start(i2c_dev_t *dev, bool start);
esp_err_t ds1307_is_running(i2c_dev_t *dev, bool *running);
esp_err_t ds1307_get_time(i2c_dev_t *dev, struct tm *time);
esp_err_t ds1307_set_time(i2c_dev_t *dev, const struct tm *time);

#endif /* MAIN_DS1307_H__ */
