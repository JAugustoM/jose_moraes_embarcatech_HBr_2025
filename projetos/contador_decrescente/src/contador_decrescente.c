#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/button_handler.h"
#include "lib/timer_handler.h"
#include "lib/screen_handler.h"



int main()
{
    stdio_init_all();
    setup_buttons();
    setup_display_oled();
    draw_screen(texto);

    while (true) {
    }
}
