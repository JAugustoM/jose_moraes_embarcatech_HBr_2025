#include "button_handler.h"
#include "hardware/irq.h"
#include <pico/types.h>

absolute_time_t last_press_time_a = 0;
absolute_time_t last_press_time_b = 0;
state_t global_state = STATE_NOTHING;

static void buttons_callback(uint gpio, uint32_t events) {
  if (global_state == STATE_NOTHING) {
    if (gpio == 5) {
      if (absolute_time_diff_us(last_press_time_a, get_absolute_time()) >
          200000) {
        last_press_time_a = get_absolute_time();
        global_state = STATE_RECORDING;
      }
    } else if (gpio == 6) {
      if (absolute_time_diff_us(last_press_time_b, get_absolute_time()) >
          200000) {
        last_press_time_b = get_absolute_time();
        global_state = STATE_PLAYING;
      }
    }
  }
}

void init_buttons() {
  gpio_init(BUTTON_A_PIN);
  gpio_init(BUTTON_B_PIN);

  gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
  gpio_set_dir(BUTTON_B_PIN, GPIO_IN);

  gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true,
                                     buttons_callback);
  gpio_set_irq_enabled(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true);

  gpio_pull_up(BUTTON_A_PIN);
  gpio_pull_up(BUTTON_B_PIN);
}
