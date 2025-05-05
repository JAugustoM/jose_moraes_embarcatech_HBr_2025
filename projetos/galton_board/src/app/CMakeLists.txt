add_executable(${PROJECT_NAME}
  ${PROJECT_NAME}.c
)

pico_set_program_name(${PROJECT_NAME} "${PROJECT_NAME}")
pico_set_program_version(${PROJECT_NAME} "0.1")

pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)

add_library(board STATIC
  board.c
)

target_link_libraries(board
  pico_rand
  screen_handler
)

target_include_directories(board PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_library(hist STATIC
  hist.c
)

target_link_libraries(hist
  screen_handler
)

target_include_directories(hist PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
  pico_stdio
  button_handler
  screen_handler
  board
  hist
)

pico_add_extra_outputs(${PROJECT_NAME})
