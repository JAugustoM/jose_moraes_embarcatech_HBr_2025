add_library(screen_handler STATIC
  screen_handler.c
)

target_link_libraries(screen_handler
  pico_stdlib
  ssd1306
)

target_include_directories(screen_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(mic_handler STATIC
  mic_handler.c
)

target_link_libraries(mic_handler
  screen_handler
  hardware_adc
)

target_include_directories(mic_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(buzzer_handler STATIC
  buzzer_handler.c
)

target_link_libraries(buzzer_handler
  screen_handler
  hardware_pwm
)

target_include_directories(buzzer_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(button_handler STATIC
  button_handler.c
)

target_link_libraries(button_handler
  pico_stdlib
  hardware_irq
)

target_include_directories(button_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(led_handler STATIC
  led_handler.c
)

target_link_libraries(led_handler
  pico_stdlib
)

target_include_directories(led_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
