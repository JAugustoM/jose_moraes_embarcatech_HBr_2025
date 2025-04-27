#include "include/leitor_temperatura.h"
#include "pico/stdlib.h"
#include <math.h>
#include <pico/time.h>
#include <stdio.h>

int main() {
  stdio_init_all();
  double celsius = read_celsius(0.706);

  if (ceil(celsius) == 27) {
    while (true) {
      printf("Valor correto lido\n");
      sleep_ms(1000);
    }
  } else {
    while (true) {
      printf("Valor incorreto calculado\n");
      printf("%lf\n", celsius);
      sleep_ms(1000);
    }
  }
}
