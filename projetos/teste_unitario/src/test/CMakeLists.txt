add_executable(tests tests.c)

target_link_libraries(tests
  pico_stdlib
  leitor_temperatura
  unity
)

add_test(
  NAME unit_test
  COMMAND tests.bin
  WORKING_DIRECTORY src/test
)

