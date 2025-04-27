#include "include/leitor_temperatura.h"

const uint ADC_TEMPERATURE_CHANNEL = 4;

double adc_to_fahrenheit(uint16_t adc_value, double debug_voltage) {
  const float conversion_factor = 3.3f / (1 << 12);
  double voltage;
  if (debug_voltage == -1)
    voltage = adc_value * conversion_factor;
  else
    voltage = debug_voltage;
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

double read_celsius(double debug_value) {
  adc_select_input(ADC_TEMPERATURE_CHANNEL);
  double celsius = 0;

  uint16_t adc_value = 0;

  if (debug_value != -1) {
    celsius = fahrenheit_to_celsius(adc_to_fahrenheit(adc_value, debug_value));
  } else {
    for (int i = 0; i < 10; i++) {
      adc_value = adc_read();
      celsius += fahrenheit_to_celsius(adc_to_fahrenheit(adc_value, -1));
      sleep_ms(100);
    }
    celsius /= 10;
  }

  return celsius;
}
