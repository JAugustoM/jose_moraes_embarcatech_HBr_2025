#include "wifi.h"
#include "pico/cyw43_arch.h"
#include <stdint.h>
#include <stdio.h>

void connect_to_wifi(const char *ssid, const char *password) {
  // Inicializa o driver Wi-Fi (CYW43). Retorna 0 se for bem-sucedido.
  if (cyw43_arch_init()) {
    printf("Erro ao iniciar Wi-Fi\n");
    return;
  }

  cyw43_arch_enable_sta_mode();

  if (cyw43_arch_wifi_connect_timeout_ms(ssid, password,
                                         CYW43_AUTH_WPA2_MIXED_PSK, 30000)) {
    printf("Erro ao conectar\n");
  } else {
    printf("Conectado ao Wi-Fi\n");
  }
}
