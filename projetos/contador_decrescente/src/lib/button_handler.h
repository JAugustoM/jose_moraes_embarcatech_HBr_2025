#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include "pico/types.h"

extern void buttons_callback(uint gpio, uint32_t events);
extern void setup_buttons();

extern volatile uint32_t clicks;

#endif
