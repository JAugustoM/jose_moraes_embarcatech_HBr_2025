#include "mqtt.h"
#include "pico/stdlib.h"
#include "settings.h"
#include "wifi.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  stdio_init_all();
  sleep_ms(3000);
  printf("Comunicacao serial funcionando\n");

  connect_to_wifi(SSID, PASSWORD);
  printf("Conectado ao Wifi\n");

  mqtt_setup("BitDogLab", BROKER_IP, MQTT_USER, MQTT_PASS);
  printf("Conectado ao server MQTT\n");

  char message[100];

  while (true) {
    sprintf(message, "{\"valor\":26.5,\"ts\":%lu}", time(NULL));
    mqtt_comm_publish("escola/sala1/temperatura", message, strlen(message));
    printf("Mensagem enviada\n");
    sleep_ms(1000);
  }

  return 0;
}
