/* Este driver utiliza codigo do repositorio de exemplo da
 * Pico C SDK e do repositorio HumansAreWeak/rpi-pico-mpu-6050
 * com modificacoes e simplificacoes para se adaptar ao projeto
 * do robo
 */
#ifndef MPU_6050_H
#define MPU_6050_H

#include <stddef.h>
#define I2C_ADDR 0x68
#define I2C_PORT i2c1

#include <stdbool.h>
#include <stdint.h>

extern void mpu6050_reset();
extern void mpu6050_read_raw(int16_t accel[3], int16_t gyro[3], int16_t *temp);
extern uint8_t mpu6050_read_who_am_i();
extern bool mpu6050_init();

#endif // !MPU_6050_H
