#include "mpu6050_i2c.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "pico/time.h"
#include <stdint.h>

void mpu6050_reset() {
  uint8_t buf[] = {0x68, 0x80};
  i2c_write_blocking(i2c_default, I2C_ADDR, buf, 2, false);
  sleep_ms(100);

  buf[1] = 0x00;
  i2c_write_blocking(i2c_default, I2C_ADDR, buf, 2, false);
  sleep_ms(10);
}

void mpu6050_read_raw(int16_t accel[3], int16_t gyro[3], int16_t *temp) {
  uint8_t buffer[6];

  uint8_t val = 0x3B;
  i2c_write_blocking(i2c_default, I2C_ADDR, &val, 1, true);
  i2c_read_blocking(i2c_default, I2C_ADDR, buffer, 6, false);

  for (int i = 0; i < 3; i++) {
    accel[i] = (buffer[i * 2] << 8 | buffer[(i * 2) + 1]);
  }

  val = 0x43;
  i2c_write_blocking(i2c_default, I2C_ADDR, &val, 1, true);
  i2c_read_blocking(i2c_default, I2C_ADDR, buffer, 6, false);

  for (int i = 0; i < 3; i++) {
    gyro[i] = (buffer[i * 2] << 8 | buffer[(i * 2) + 1]);
  }

  val = 0x41;
  i2c_write_blocking(i2c_default, I2C_ADDR, &val, 1, true);
  i2c_read_blocking(i2c_default, I2C_ADDR, buffer, 2, false);
  *temp = buffer[0] << 8 | buffer[1];
}

uint8_t mpu6050_read_who_am_i() {
  uint8_t val = 0x75, who_am_i;
  i2c_write_blocking(i2c_default, I2C_ADDR, &val, 1, true);
  i2c_read_blocking(i2c_default, I2C_ADDR, &who_am_i, 6, false);
  return who_am_i;
}

bool mpu6050_init() {
  i2c_init(i2c_default, 400 * 1000);
  gpio_set_function(0, GPIO_FUNC_I2C);
  gpio_set_function(1, GPIO_FUNC_I2C);
  gpio_pull_up(0);
  gpio_pull_up(1);

  mpu6050_reset();

  if (mpu6050_read_who_am_i() != 0x68)
    return false;
  return true;
}
