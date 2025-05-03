add_library(leitor_temperatura STATIC
  leitor_temperatura.c
)

target_link_libraries(leitor_temperatura
  hardware_adc
)

target_include_directories(leitor_temperatura PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
