#ifndef SCREEN_HANDLER_H
#define SCREEN_HANDLER_H

#include "../drivers/ssd1306.h"
#include "pico/stdlib.h"

extern char texto[8][22];

extern void setup_display_oled();
extern void draw_screen(char text[8][22]);
extern void update_line(char text[22], int line);

#endif
