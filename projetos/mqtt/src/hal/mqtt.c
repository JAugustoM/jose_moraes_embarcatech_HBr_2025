#include "lwip/apps/mqtt.h"
#include "lwipopts.h"
#include "mqtt.h"
#include <stdio.h>

static mqtt_client_t *client;
static uint32_t ultima_timestamp_recebida = 0;

static void mqtt_connection_cb(mqtt_client_t *client, void *arg,
                               mqtt_connection_status_t status) {
  if (status == MQTT_CONNECT_ACCEPTED) {
    printf("Conectado ao broker MQTT com sucesso!\n");
  } else {
    printf("Falha ao conectar ao broker, código: %d\n", status);
  }
}

void mqtt_setup(const char *client_id, const char *broker_ip, const char *user,
                const char *pass) {
  ip_addr_t broker_addr; // Estrutura para armazenar o IP do broker

  if (!ip4addr_aton(broker_ip, &broker_addr)) {
    printf("Erro no IP\n");
    return;
  }

  client = mqtt_client_new();
  if (client == NULL) {
    printf("Falha ao criar o cliente MQTT\n");
    return;
  }

  struct mqtt_connect_client_info_t ci = {
      .client_id = client_id, // ID do cliente
      .client_user = user,    // Usuário (opcional)
      .client_pass = pass     // Senha (opcional)
  };

  mqtt_client_connect(client, &broker_addr, 1883, mqtt_connection_cb, NULL,
                      &ci);
}

static void mqtt_pub_request_cb(void *arg, err_t result) {
  if (result == ERR_OK) {
    printf("Publicação MQTT enviada com sucesso!\n");
  } else {
    printf("Erro ao publicar via MQTT: %d\n", result);
  }
}

void xor_encrypt(const uint8_t *input, uint8_t *output, size_t len,
                 uint8_t key) {
  for (size_t i = 0; i < len; ++i) {
    output[i] = input[i] ^ key;
  }
}

void mqtt_comm_publish(const char *topic, const uint8_t *data, size_t len) {
  uint8_t message[len];

  xor_encrypt(data, message, len, 42);

  err_t status =
      mqtt_publish(client, topic, data, len, 0, 0, mqtt_pub_request_cb, NULL);

  if (status != ERR_OK) {
    printf("mqtt_publish falhou ao ser enviada: %d\n", status);
  }
}

void on_message(char *topic, char *msg) {
  uint32_t nova_timestamp;
  float valor;
  if (sscanf(msg, "{\"valor\":%f,\"ts\":%lu}", &valor, &nova_timestamp) != 2) {
    printf("Erro no parse da mensagem!\n");
    return;
  }

  if (nova_timestamp > ultima_timestamp_recebida) {
    ultima_timestamp_recebida = nova_timestamp;
    printf("Nova leitura: %.2f (ts: %lu)\n", valor, nova_timestamp);
  } else {
    printf("Replay detectado (ts: %lu <= %lu)\n", nova_timestamp,
           ultima_timestamp_recebida);
  }
}
