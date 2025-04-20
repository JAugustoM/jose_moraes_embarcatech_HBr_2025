#include "lib/button_handler.h"
#include "lib/screen_handler.h"
#include "lib/timer_handler.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();
  setup_buttons();
  setup_display_oled();
  draw_screen(texto);

  while (true) {
  }
}
