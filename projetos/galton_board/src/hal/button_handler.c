#include "button_handler.h"
#include "../app/hist.h"
#include "hardware/gpio.h"

const uint BUTTON_A = 5;
const uint BUTTON_B = 6;

// volatile bool ba_state = false;
// volatile bool bb_state = false;

volatile absolute_time_t last_press_time_a = 0;

void buttons_callback(uint gpio, uint32_t events) {
  if (gpio == 5) {
    if (absolute_time_diff_us(last_press_time_a, get_absolute_time()) >
        150000) {
      last_press_time_a = get_absolute_time();
      hist = !hist;
    }
  }
}

void setup_buttons() {
  gpio_init(BUTTON_A);
  gpio_set_dir(BUTTON_A, GPIO_IN);

  gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true,
                                     buttons_callback);
  gpio_pull_up(BUTTON_A);
}
