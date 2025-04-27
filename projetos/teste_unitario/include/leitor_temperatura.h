#ifndef LEITOR_TEMPERATURA_H_
#define LEITOR_TEMPERATURA_H_

#include "hardware/adc.h"
#include "pico/stdlib.h"

extern double adc_to_fahrenheit(uint16_t adc_value, double debug_voltage);
extern double fahrenheit_to_celsius(float fahrenheit);
extern void init_adc_temp();
extern double read_celsius(double debug_value);

#endif // INCLUDE_INCLUDE_LEITOR_TEMPERATURA_H_
