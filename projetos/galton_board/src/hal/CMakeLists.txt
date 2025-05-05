add_library(button_handler STATIC
  button_handler.c
)

target_link_libraries(button_handler
  pico_stdlib
  hardware_gpio
  hist
)

target_include_directories(button_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(screen_handler STATIC
  screen_handler.c
)

target_link_libraries(screen_handler
  pico_stdlib
  ssd1306_i2c
)

target_include_directories(screen_handler PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
