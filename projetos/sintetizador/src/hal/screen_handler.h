#ifndef SCREEN_HANDLER_H
#define SCREEN_HANDLER_H

#include "ssd1306.h"

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define I2C_PORT i2c1
#define I2C_SDA_PIN 14
#define I2C_SCL_PIN 15
#define SSD1306_I2C_ADDR 0x3C
#define PROGRESS_BAR_Y 60

extern bool init_display(ssd1306_t *disp);
extern void draw_start(ssd1306_t *disp);
extern void display_waveform(ssd1306_t *disp, uint8_t *buffer, uint32_t start,
                             uint32_t end);
extern void draw_progress_bar(ssd1306_t *disp, uint32_t current, uint32_t total,
                              char *text);

#endif // !SCREEN_HANDLER_H
