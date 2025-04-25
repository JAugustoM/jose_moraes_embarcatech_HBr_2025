#include "app/board.h"
#include "hal/screen_handler.h"
#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  stdio_init_all();
  setup_display_oled();

  draw_screen(INIT_STATE);

  List *list = create_list();

  bool create = true;

  if (list != NULL) {

    while (true) {
      if (create)
        create_ball();
      create = !create;

      sleep_ms(1000);
      tick();
    }
  }
}
