add_library(cp437 STATIC
  cp437.c
)

target_include_directories(cp437 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(ssd1306_i2c STATIC
  ssd1306_i2c.c
)

target_link_libraries(ssd1306_i2c
  pico_stdlib
  pico_binary_info
  hardware_i2c
  cp437
)

target_include_directories(ssd1306_i2c PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
