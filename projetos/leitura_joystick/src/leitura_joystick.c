#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/joystick_handler.h"


int main()
{
    stdio_init_all();
    setup_joystick();

    while (true) {
        uint16_t *values = read_joystick();
        printf("Eixo X: % 4u - %.2f\n", values[0], (values[0] - 17) / 4085.0);
        printf("Eixo Y: % 4u - %.2f\n", values[1], (values[1] - 17) / 4085.0);
        printf("\n");
        sleep_ms(1000);
    }
}
