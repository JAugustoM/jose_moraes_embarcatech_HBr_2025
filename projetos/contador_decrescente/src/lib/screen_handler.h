#ifndef SCREEN_HANDLER_H
#define SCREEN_HANDLER_H

#include "../inc/ssd1306.h"
#include "pico/stdlib.h"

extern char texto[8][17];

extern void setup_display_oled();
extern void draw_screen(char text[8][17]);
extern void update_line(char text[17], int line);
extern void get_screen_text();
extern void change_screen_state(uint state);

#endif