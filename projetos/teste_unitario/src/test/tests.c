#include "leitor_temperatura.h"
#include "unity.h"
#include "unity_internals.h"
#include <stdio.h>

void setUp(void) {};
void tearDown(void) {};

void test_temperature_conversion(void) {
  double fahrenheit = adc_to_fahrenheit(0.706);
  double celsius = fahrenheit_to_celsius(fahrenheit);
  TEST_ASSERT_DOUBLE_WITHIN(1f, 27f, celsius);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_temperature_conversion);
  double fahrenheit = adc_to_fahrenheit(0.706);
  double celsius = fahrenheit_to_celsius(fahrenheit);

  printf("Expected: 27.0 C\n Actual: %.2lf\n", celsius);

  return UNITY_END();
}
