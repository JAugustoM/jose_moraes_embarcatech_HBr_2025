#ifndef SCREEN_HANDLER_H
#define SCREEN_HANDLER_H

#include "pico/stdlib.h"
#include "ssd1306.h"

extern char texto[8][22];

extern void setup_display_oled();
extern void draw_screen(char text[8][22]);
extern void update_line(char *text, int line, int start_column);

#endif
