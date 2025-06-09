#ifndef BUZZER_HANDLER_H
#define BUZZER_HANDLER_H

#include "screen_handler.h"

#define ADC_CLOCK_DIV 96.f
#define BUZZER_PIN 21

extern void init_buzzer();
extern void play_audio(uint8_t *buffer, uint32_t num_samples,
                       uint32_t sample_rate, ssd1306_t *disp);

#endif // !BUZZER_HANDLER_H
