# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TARGET_GROUP production CACHE STRING "Group to build")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(teste_unitario C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(src/hal)

if(TARGET_GROUP STREQUAL production)
  add_subdirectory(src/app)
elseif(TARGET_GROUP STREQUAL test)
  include(CTest)
  add_subdirectory(Unity)
  add_subdirectory(src/test)
else()
  message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()


