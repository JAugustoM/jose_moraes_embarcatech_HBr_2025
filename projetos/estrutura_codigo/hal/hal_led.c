#include "include/hal_led.h"
#include "include/led_embutido.h"
#include <stdbool.h>

bool turned_on = false;

void hal_led_toggle() {
  if (turned_on)
    turn_off_led();
  else
    turn_on_led();

  turned_on = !turned_on;
}
