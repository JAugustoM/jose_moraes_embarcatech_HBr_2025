add_library(mqtt STATIC
  mqtt.c
)

target_link_libraries(mqtt
  pico_lwip
  pico_lwip_nosys
  pico_lwip_arch
  pico_lwip_mqtt
)

target_include_directories(mqtt PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
