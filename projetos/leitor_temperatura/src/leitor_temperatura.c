#include <stdio.h> 
#include "pico/stdlib.h"      
#include "hardware/adc.h"      

double adc_to_fahrenheit(uint16_t adc_value) {
    const float conversion_factor = 3.3f / (1 << 12);
    double voltage = adc_value * conversion_factor;
    double temperature = 27.0f - (voltage - 0.706f) / 0.001721f;
    return (temperature * 1.8) + 32;
}

double fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * (5.0 / 9.0);
}

const uint ADC_TEMPERATURE_CHANNEL = 4;

int main() {
    stdio_init_all();

    adc_init();

    adc_set_temp_sensor_enabled(true); 
    adc_select_input(ADC_TEMPERATURE_CHANNEL);  

    while (true) {
        double leituras = 0;
        for (int i = 0; i < 10; i++) {
            uint16_t adc_value = adc_read();
            double fahrenheit = adc_to_fahrenheit(adc_value);
            leituras += fahrenheit_to_celsius(fahrenheit);
            sleep_ms(100);
        }

        printf("Temperatura: %.2f °C\n", leituras / 10);
    }

    return 0;
}
