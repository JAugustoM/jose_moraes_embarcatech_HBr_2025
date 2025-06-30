#include "hardware/i2c.h"
#include "haw/MPU6050.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include <hardware/gpio.h>
#include <pico/time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
  stdio_init_all();

  i2c_init(i2c_default, 400 * 1000);
  gpio_init(0);
  gpio_init(1);
  gpio_set_function(0, GPIO_FUNC_I2C);
  gpio_set_function(1, GPIO_FUNC_I2C);
  gpio_pull_up(0);
  gpio_pull_up(1);
  bi_decl(bi_2pins_with_func(0, 1, GPIO_FUNC_I2C));

  mpu6050_t mpu6050 = mpu6050_init(i2c_default, MPU6050_ADDRESS_A0_GND);

  if (!mpu6050_begin(&mpu6050)) { // Set scale of gyroscope
    mpu6050_set_scale(&mpu6050, MPU6050_SCALE_2000DPS);
    // Set range of accelerometer
    mpu6050_set_range(&mpu6050, MPU6050_RANGE_16G);

    // Enable temperature, gyroscope and accelerometer readings
    mpu6050_set_temperature_measuring(&mpu6050, true);
    mpu6050_set_gyroscope_measuring(&mpu6050, true);
    mpu6050_set_accelerometer_measuring(&mpu6050, true);

    // Enable free fall, motion and zero motion interrupt flags
    mpu6050_set_int_free_fall(&mpu6050, false);
    mpu6050_set_int_motion(&mpu6050, true);
    mpu6050_set_int_zero_motion(&mpu6050, false);

    // Set motion detection threshold and duration
    mpu6050_set_motion_detection_threshold(&mpu6050, 2);
    mpu6050_set_motion_detection_duration(&mpu6050, 5);

    // Set zero motion detection threshold and duration
    mpu6050_set_zero_motion_detection_threshold(&mpu6050, 4);
    mpu6050_set_zero_motion_detection_duration(&mpu6050, 2);
  }

  while (1) {
    // Fetch all data from the sensor | I2C is only used here
    mpu6050_event(&mpu6050);

    // Pointers to float vectors with all the results
    mpu6050_vectorf_t *accel = mpu6050_get_accelerometer(&mpu6050);
    mpu6050_vectorf_t *gyro = mpu6050_get_gyroscope(&mpu6050);

    // Rough temperatures as float -- Keep in mind, this is not a temperature
    // sensor!!!
    float tempC = mpu6050_get_temperature_c(&mpu6050);
    float tempF = mpu6050_get_temperature_f(&mpu6050);

    // Print all the measurements
    printf("Accelerometer: %f, %f, %f - Gyroscope: %f, %f, %f - Temperature: "
           "%f°C - Temperature: %f°F\n",
           accel->x, accel->y, accel->z, gyro->x, gyro->y, gyro->z, tempC,
           tempF);

    sleep_ms(500);
  }

  return 0;
}
