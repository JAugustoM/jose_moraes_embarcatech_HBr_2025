#include "buzzer_handler.h"
#include "hardware/pwm.h"

void init_buzzer() {
  gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
  uint channel_num = pwm_gpio_to_channel(BUZZER_PIN);

  pwm_set_wrap(slice_num, 255);
  pwm_set_clkdiv(slice_num, 1.0f);
  pwm_set_chan_level(slice_num, channel_num, 0);
  pwm_set_enabled(slice_num, true);
}

void play_audio(uint8_t *buffer, uint32_t num_samples, uint32_t sample_rate,
                ssd1306_t *disp) {
  uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
  uint channel_num = pwm_gpio_to_channel(BUZZER_PIN);

  uint32_t delay_us = 1000000 / sample_rate;

  uint64_t start_time_us = time_us_64();
  for (uint32_t i = 0; i < num_samples; ++i) {
    pwm_set_chan_level(slice_num, channel_num, buffer[i]);

    uint64_t elapsed_us = time_us_64() - start_time_us;
    uint64_t target_time_us = (i + 1) * delay_us;
    if (elapsed_us < target_time_us) {
      sleep_us(target_time_us - elapsed_us);
    }
    if ((i % 4096 == 0) && i > 0) {
      ssd1306_clear(disp);
      draw_progress_bar(disp, i, num_samples, "Reproduzindo: ");
      display_waveform(disp, buffer, i - 128, i - 1);
      ssd1306_show(disp);
    }
  }
  pwm_set_chan_level(slice_num, channel_num, 0);
}
