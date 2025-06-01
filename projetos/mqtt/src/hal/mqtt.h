#ifndef MQTT_H
#define MQTT_H

#include <stddef.h>
#include <stdint.h>

extern void mqtt_setup(const char *client_id, const char *broker_ip,
                       const char *user, const char *pass);
extern void mqtt_comm_publish(const char *topic, const uint8_t *data,
                              size_t len);

#endif // !MQTT_H
