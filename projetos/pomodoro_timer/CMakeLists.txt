# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pomodoro C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pomodoro src/pomodoro.c 
        src/inc/ssd1306_i2c.c
        src/lib/buttons_handler.c
        src/lib/joystick_handler.c
        src/lib/led_handler.c
        src/lib/screen_handler.c
        src/lib/timer_handler.c
        src/lib/buzzer_handler.c
        src/lib/memory_handler.c
        src/lib/led_matrix_handler.c)

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/lib/ws2818b.pio)

pico_set_program_name(pomodoro "pomodoro")
pico_set_program_version(pomodoro "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(pomodoro 0)
pico_enable_stdio_usb(pomodoro 1)

# Add the standard library to the build
target_link_libraries(pomodoro
        pico_stdlib
        hardware_timer
        hardware_clocks
        hardware_pwm
        hardware_adc
        hardware_i2c
        hardware_gpio
        hardware_flash
        hardware_sync
        hardware_pio)

# Add the standard include files to the build
target_include_directories(pomodoro PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(pomodoro)

set_target_properties(pomodoro PROPERTIES PICO_TARGET_LINKER_SCRIPT 
    ${CMAKE_SOURCE_DIR}/memmap_custom.ld)
