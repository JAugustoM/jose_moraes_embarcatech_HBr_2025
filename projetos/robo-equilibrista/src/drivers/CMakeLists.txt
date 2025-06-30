add_library(mpu6050 STATIC
  mpu6050_i2c.c
)

target_link_libraries(mpu6050
  pico_stdlib
  hardware_i2c
)

target_include_directories(mpu6050 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
