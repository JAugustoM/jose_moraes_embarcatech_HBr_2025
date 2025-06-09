add_library(ssd1306 STATIC
  ssd1306.c
)

target_link_libraries(ssd1306
  hardware_i2c
  pico_stdlib
  pico_binary_info
)

target_include_directories(ssd1306 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
