// Define o número máximo de timeouts do sistema que podem estar ativos
// simultaneamente LWIP_NUM_SYS_TIMEOUT_INTERNAL é o número de timeouts usados
// internamente pelo LWIP O + 1 está adicionando um timeout extra para ser usado
// pela aplicação Timeouts são usados para várias operações como retransmissões
// TCP, tempo de espera de conexão, etc.
#define MEMP_NUM_SYS_TIMEOUT (LWIP_NUM_SYS_TIMEOUT_INTERNAL + 1)

// Define o número máximo de requisições MQTT que podem estar "em voo" (não
// confirmadas) simultaneamente Especificamente para operações de subscribe
// (inscrição em tópicos MQTT) O valor 5 significa que até 5 requisições
// simultâneas (como PUBLISH, SUBSCRIBE etc) podem ser enviadas antes de
// precisar receber as confirmações correspondentes Isso ajuda a controlar o
// fluxo de mensagens no protocolo MQTT
#define MQTT_REQ_MAX_IN_FLIGHT (5)
