#ifndef LEITOR_TEMPERATURA_H_
#define LEITOR_TEMPERATURA_H_

#include <stdint.h>

extern double get_voltage();
extern double adc_to_fahrenheit(double voltage);
extern double fahrenheit_to_celsius(float fahrenheit);
extern void init_adc_temp();

#endif // INCLUDE_INCLUDE_LEITOR_TEMPERATURA_H_
