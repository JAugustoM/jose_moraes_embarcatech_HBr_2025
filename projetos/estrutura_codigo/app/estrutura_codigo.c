#include "include/hal_led.h"
#include "pico/stdlib.h"

int main() {

  while (true) {
    hal_led_toggle();
    sleep_ms(1000);
  }
}
