#include <stdlib.h>
#include "hardware/adc.h"
#include "pico/stdlib.h"
#include "joystick_handler.h"

const int ADC_CHANNEL_0 = 0;
const int ADC_CHANNEL_1 = 1;

const uint JOY_X = 26;
const uint JOY_Y = 27;

void setup_joystick() {
  adc_init(); 
  adc_gpio_init(JOY_X);
  adc_gpio_init(JOY_Y);
}

uint16_t* read_joystick() {
    adc_select_input(ADC_CHANNEL_0);
    sleep_us(2);
    uint16_t x = adc_read();

    adc_select_input(ADC_CHANNEL_1);
    sleep_us(2);
    uint16_t y = adc_read();

    uint16_t *values = malloc(sizeof(uint16_t) * 2);
    values[0] = x;
    values[1] = y;

    return values;
}

