#include "leitor_temperatura.h"
#include <hardware/adc.h>

const uint ADC_TEMPERATURE_CHANNEL = 4;

double get_voltage() {
  const float conversion_factor = 3.3f / (1 << 12);

  adc_select_input(ADC_TEMPERATURE_CHANNEL);
  uint16_t adc_value = adc_read();
  return adc_value * conversion_factor;
}

double adc_to_fahrenheit(double voltage) {
  double temperature = 27.0f - (voltage - 0.706f) / 0.001721f;
  return (temperature * 1.8) + 32;
}

double fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32) * (5.0 / 9.0);
}

void init_adc_temp() {
  adc_init();

  adc_set_temp_sensor_enabled(true);
}
