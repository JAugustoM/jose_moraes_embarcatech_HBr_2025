#ifndef TIMER_HANDLER_H
#define TIMER_HANDLER_H

#include "hardware/timer.h"
#include "pico/stdlib.h"

extern struct repeating_timer timer;
extern volatile bool cancelled;
extern volatile uint8_t time;

extern bool repeating_timer_callback(__unused struct repeating_timer *t);

extern void setup_repeating_timer();
extern void cancel_timer();

#endif