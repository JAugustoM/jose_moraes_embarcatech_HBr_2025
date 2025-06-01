add_library(wifi STATIC
  wifi.c
)

target_link_libraries(wifi
  pico_stdlib
  pico_lwip
  pico_cyw43_arch_lwip_poll
)

target_include_directories(wifi PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
