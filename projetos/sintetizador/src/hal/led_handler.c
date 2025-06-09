#include "led_handler.h"
#include "pico/stdlib.h"

void init_leds() {
  gpio_init(RED_LED_PIN);
  gpio_init(GREEN_LED_PIN);
  gpio_set_dir(RED_LED_PIN, GPIO_OUT);
  gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
}

void led_recording() {
  gpio_put(RED_LED_PIN, 1);
  gpio_put(GREEN_LED_PIN, 0);
}
void led_playing() {
  gpio_put(RED_LED_PIN, 0);
  gpio_put(GREEN_LED_PIN, 1);
}
void led_idle() {
  gpio_put(RED_LED_PIN, 0);
  gpio_put(GREEN_LED_PIN, 0);
}
