#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include "pico/stdlib.h"

extern void buttons_callback(uint gpio, uint32_t events);
extern void setup_buttons();

#endif
