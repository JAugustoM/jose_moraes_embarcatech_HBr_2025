#include "app/board.h"
#include "app/hist.h"
#include "hal/button_handler.h"
#include "hal/screen_handler.h"
#include "pico/stdio.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  stdio_init_all();
  setup_display_oled();
  setup_buttons();

  draw_screen(INIT_STATE);

  List *list = create_list();

  bool create = true;

  if (list != NULL) {

    while (true) {
      tick();

      if (create)
        create_ball();
      create = !create;

      if (!hist)
        draw_board();
      else
        draw_hist();
      sleep_ms(1000);
    }
  }
}
