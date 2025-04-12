#include <math.h>
#include <stdio.h>
#include <string.h>
#include "timer_handler.h"
#include "button_handler.h"
#include "screen_handler.h"

struct repeating_timer timer;
volatile bool cancelled = true;
volatile uint8_t time = 0;

bool repeating_timer_callback(__unused struct repeating_timer *t) {
    // printf("Tempo: %ds | Clicks: % 3d\n", time, clicks);
    char text[17];

    if (time > 0) {
        time--;

        snprintf(text, 17, "Tempo   %us     ", time);
        update_line(text, 2);
        if (time == 0) {
            cancelled = true;
            return false;
        }
        
        return true;
    }

    cancelled = true;
    return false;
}

void setup_repeating_timer() {
    cancelled = false; 
    time = 9;
    add_repeating_timer_ms(1000, repeating_timer_callback, NULL, &timer);
}

void cancel_timer() {
    cancelled = true;
    cancel_repeating_timer(&timer);
}
