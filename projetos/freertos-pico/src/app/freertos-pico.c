#include "FreeRTOS.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "projdefs.h"
#include "task.h"
#include <stdio.h>

#define BUZZER_PIN 21
#define BUZZER_FREQ 100
#define RGB_LED_G 11
#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6

TaskHandle_t led_handle;
bool led_suspended = false;

TaskHandle_t buzzer_handle;
bool buzzer_suspended = false;

void buzzer_task(void *params) {
  gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

  uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

  pwm_config config = pwm_get_default_config();
  pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQ * 4096));
  pwm_init(slice_num, &config, true);

  pwm_set_gpio_level(BUZZER_PIN, 0);

  while (true) {
    pwm_set_gpio_level(BUZZER_PIN, 2048);
    vTaskDelay(pdMS_TO_TICKS(100));
    pwm_set_gpio_level(BUZZER_PIN, 0);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void blink_task(void *params) {
  const uint LED_PIN = RGB_LED_G;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  while (true) {
    gpio_put(LED_PIN, true);
    vTaskDelay(pdMS_TO_TICKS(500));
    gpio_put(LED_PIN, false);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void button_task(void *params) {
  gpio_init(BUTTON_A_PIN);
  gpio_init(BUTTON_B_PIN);

  gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
  gpio_set_dir(BUTTON_B_PIN, GPIO_IN);

  gpio_pull_up(BUTTON_A_PIN);
  gpio_pull_up(BUTTON_B_PIN);

  while (true) {
    if (gpio_get(BUTTON_A_PIN) == 0) {
      if (led_suspended)
        vTaskResume(led_handle);
      else
        vTaskSuspend(led_handle);
      led_suspended = !led_suspended;
    }

    if (gpio_get(BUTTON_B_PIN) == 0) {
      if (buzzer_suspended)
        vTaskResume(buzzer_handle);
      else
        vTaskSuspend(buzzer_handle);
      buzzer_suspended = !buzzer_suspended;
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

int main() {
  stdio_init_all();
  xTaskCreate(blink_task, "Blink", 256, NULL, 1, &led_handle);
  xTaskCreate(buzzer_task, "Buzzer", 256, NULL, 1, &buzzer_handle);
  xTaskCreate(button_task, "Button", 256, NULL, 1, NULL);

  vTaskStartScheduler();
  while (true) {
  }
}
