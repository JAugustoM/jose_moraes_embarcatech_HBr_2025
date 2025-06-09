#include "button_handler.h"
#include "buzzer_handler.h"
#include "led_handler.h"
#include "mic_handler.h"
#include "pico/stdlib.h"
#include "screen_handler.h"
#include <stdio.h>

#define SAMPLE_RATE 8000
#define SAMPLE_TIME 5
#define TOTAL_SAMPLES SAMPLE_RATE *SAMPLE_TIME

bool init_hardware(ssd1306_t *disp) {
  bool success = init_display(disp);
  if (success) {
    init_buttons();
    init_leds();
    init_mic();
    init_buzzer();
  }

  return success;
}

int main() {
  stdio_init_all();
  ssd1306_t disp;
  if (!init_hardware(&disp)) {
    printf("Failed to init display.Exiting program\n");
    return 0;
  }

  uint8_t buffer[TOTAL_SAMPLES];
  uint32_t current_idx = 0;

  while (1) {
    if (global_state == STATE_RECORDING) {
      led_recording();
      record_audio(buffer, TOTAL_SAMPLES, &current_idx, SAMPLE_RATE, &disp);
      global_state = STATE_NOTHING;

    } else if (global_state == STATE_PLAYING) {
      led_playing();
      play_audio(buffer, current_idx, SAMPLE_RATE, &disp);
      global_state = STATE_NOTHING;
    } else {
      draw_start(&disp);
      led_idle();
    }
    sleep_ms(10);
  }
}
