#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "screen_handler.h"
#include "timer_handler.h"

const uint I2C_SDA = 14;
const uint I2C_SCL = 15;

struct render_area frame_area = {
    start_column : 0,
    end_column : ssd1306_width - 1,
    start_page : 0,
    end_page : ssd1306_n_pages - 1
};

char texto[8][17] = {"               ",
                     "               ",
                     "Tempo   0s     ",
                     "               ",
                     "               ",
                     "Clicks   0     ",
                     "               ",
                     "               ",};
uint8_t* ssd;

void setup_display_oled() {
    calculate_render_area_buffer_length(&frame_area);
    ssd = malloc(sizeof(uint8_t) * ssd1306_buffer_length);

    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);
}

void draw_screen(char text[8][17]) {
    memset(ssd, 0, ssd1306_buffer_length);
    int y = 0;

    for (uint i = 0; i < 8; i++) {
        ssd1306_draw_string(ssd, 5, y, text[i]);
        y += 8;
    }

    render_on_display(ssd, &frame_area);
}

void update_line(char text[17], int line) {
    int y = 8 * line;
    ssd1306_draw_string(ssd, 5, y, text);
    render_on_display(ssd, &frame_area);
}