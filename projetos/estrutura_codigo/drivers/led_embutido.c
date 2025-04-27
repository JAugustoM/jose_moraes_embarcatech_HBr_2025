#include "include/led_embutido.h"
#include <stdbool.h>

bool init = false;

void init_driver() {
  if (!cyw43_arch_init())
    init = true;
}

void turn_on_led() {
  if (init)
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
  else {
    init_driver();
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
  }
}

void turn_off_led() {
  if (init)
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
  else {
    init_driver();
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
  }
}
