#include "leitor_temperatura.h"
#include "pico/stdlib.h"
#include "unity.h"
#include "unity_internals.h"
#include <pico/stdio.h>
#include <pico/time.h>
#include <stdio.h>

void setUp(void) {};
void tearDown(void) {};

void test_temperature_conversion(void) {
  double fahrenheit = adc_to_fahrenheit(0.706);
  double celsius = fahrenheit_to_celsius(fahrenheit);
  char str[100];
  snprintf(str, 100, "Expected value: 27.0 C\nActual value: %.1lf C\n",
           celsius);
  TEST_ASSERT_FLOAT_WITHIN_MESSAGE(1, 27, celsius, str);
}

int main(void) {
  stdio_init_all();
  sleep_ms(10000);

  UNITY_BEGIN();
  RUN_TEST(test_temperature_conversion);

  int result = UNITY_END();

  while (true) {
    sleep_ms(1000);
  }
}
