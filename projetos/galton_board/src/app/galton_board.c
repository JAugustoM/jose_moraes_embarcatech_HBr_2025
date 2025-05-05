#include "board.h"
#include "button_handler.h"
#include "hist.h"
#include "pico/stdio.h"
#include "screen_handler.h"
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
