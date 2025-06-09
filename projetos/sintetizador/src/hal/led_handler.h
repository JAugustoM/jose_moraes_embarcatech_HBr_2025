#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#define GREEN_LED_PIN 11
#define RED_LED_PIN 13

extern void init_leds();
extern void led_recording();
extern void led_playing();
extern void led_idle();

#endif // !LED_HANDLER_H
