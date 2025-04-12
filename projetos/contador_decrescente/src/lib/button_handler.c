#include "button_handler.h"
#include "timer_handler.h"
#include "screen_handler.h"
#include <stdint.h>
#include <stdio.h>

const uint BUTTON_A = 5;
const uint BUTTON_B = 6;

// volatile bool ba_state = false;
// volatile bool bb_state = false;

volatile absolute_time_t last_press_time_a = 0;
volatile absolute_time_t last_press_time_b = 0;

volatile uint32_t clicks = 0;

void buttons_callback(uint gpio, uint32_t events) {
  if (gpio == 5) {
      if (absolute_time_diff_us(last_press_time_a, get_absolute_time()) > 150000) {
      last_press_time_a = get_absolute_time();
      // printf("%d\n", last_press_time_a);

      cancel_timer();

      clicks = 0;

      char text[17];

      snprintf(text, 17, "Tempo   9s     ", time);
      update_line(text, 2);

      snprintf(text, 17, "Clicks % 3u     ", clicks);
      update_line(text, 5);

      setup_repeating_timer();
    }
  }

  if (gpio == 6 && !cancelled) {
    if (absolute_time_diff_us(last_press_time_b, get_absolute_time()) > 150000) {
      last_press_time_b = get_absolute_time();
      // printf("%d\n", last_press_time_b);
      clicks++;

      char text[17];
      snprintf(text, 17, "Clicks % 3u     ", clicks);
      update_line(text, 5);
      // printf("Clicks: % 3d\n", clicks);
    }
  }
}

void setup_buttons() {
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, buttons_callback);
    gpio_set_irq_enabled(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);

    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);
}
