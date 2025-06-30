#include "mpu6050_i2c.h"
#include "pico/stdio.h"
#include "pico/time.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
  stdio_init_all();
  int16_t accel[3], gyro[3], temp;

  sleep_ms(1000);

  while (true) {
    mpu6050_read_raw(accel, gyro, &temp);

    printf("Acc. X = %d, Y = %d, Z = %d\n", accel[0], accel[1], accel[2]);
    printf("Gyro. X = %d, Y = %d, Z = %d\n", gyro[0], gyro[1], gyro[2]);
    printf("Temp. = %f\n", (temp / 340.0) + 36.53);

    sleep_ms(100);
  }

  return 0;
}
