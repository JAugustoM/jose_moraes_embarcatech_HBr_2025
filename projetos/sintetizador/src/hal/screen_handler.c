#include "screen_handler.h"
#include "pico/stdlib.h"

bool init_display(ssd1306_t *disp) {
  i2c_init(I2C_PORT, 400 * 1000); // 400 kHz for I2C communication
  gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
  gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
  gpio_pull_up(I2C_SDA_PIN);
  gpio_pull_up(I2C_SCL_PIN);

  disp->external_vcc = false; // Internal VCC
  bool success =
      ssd1306_init(disp, OLED_WIDTH, OLED_HEIGHT, SSD1306_I2C_ADDR, I2C_PORT);

  return success;
}

void display_waveform(ssd1306_t *disp, uint8_t *buffer, uint32_t start,
                      uint32_t end) {
  for (uint32_t x = start; x <= end; x++) {
    uint8_t h = (buffer[x] / 4);
    if (h >= 32)
      ssd1306_draw_line(disp, x - start, 32, x - start, h);
    else
      ssd1306_draw_line(disp, x - start, h, x - start, 32);
  }
}

void draw_start(ssd1306_t *disp) {
  ssd1306_clear(disp);
  ssd1306_draw_string(disp, 20, 28, 1, "(A) Gravar");
  ssd1306_draw_string(disp, 20, 38, 1, "(B) Reproduzir");
  ssd1306_show(disp);
}

void draw_progress_bar(ssd1306_t *disp, uint32_t current, uint32_t total,
                       char *text) {
  ssd1306_draw_string(disp, 0, PROGRESS_BAR_Y - 10, 1, text);
  float p = (float)(current + 1) / total;
  ssd1306_draw_line(disp, 0, PROGRESS_BAR_Y, p * 128, PROGRESS_BAR_Y);
}
