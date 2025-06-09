#ifndef MIC_HANDLER_H
#define MIC_HANDLER_H

#include "screen_handler.h"

#define MIC_CHANNEL 2
#define MIC_PIN (26 + MIC_CHANNEL)

extern void init_mic();
extern void record_audio(uint8_t *buffer, uint32_t max_size,
                         uint32_t *current_idx, uint32_t sample_rate,
                         ssd1306_t *disp);

#endif // !MIC_HANDLER_H
