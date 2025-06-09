#include "mic_handler.h"
#include "hardware/adc.h"

void init_mic() {
  adc_init();
  adc_gpio_init(28);
  adc_select_input(2);
}

void record_audio(uint8_t *buffer, uint32_t max_size, uint32_t *current_idx,
                  uint32_t sample_rate, ssd1306_t *disp) {
  uint32_t delay_us = 1000000 / sample_rate;

  *current_idx = 0;

  uint64_t start_time_us = time_us_64();

  while (*current_idx < max_size) {
    uint16_t raw_adc = adc_read();
    uint16_t processed_adc = raw_adc;
    processed_adc /= 16;

    if (processed_adc < 0)
      processed_adc = 0;
    if (processed_adc > 255)
      processed_adc = 255;

    buffer[*current_idx] = (uint8_t)processed_adc;
    (*current_idx)++;

    uint64_t elapsed_us = time_us_64() - start_time_us;
    uint64_t target_time_us = (*current_idx) * delay_us;
    if (elapsed_us < target_time_us) {
      sleep_us(target_time_us - elapsed_us);
    }

    if (((*current_idx) % 4096 == 0) && (*current_idx) > 0) {
      ssd1306_clear(disp);
      draw_progress_bar(disp, *current_idx, max_size, "Gravando: ");
      display_waveform(disp, buffer, (*current_idx) - 128, (*current_idx) - 1);
      ssd1306_show(disp);
    }
  }
}
