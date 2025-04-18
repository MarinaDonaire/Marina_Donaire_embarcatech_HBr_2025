# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(temperatura C CXX ASM)

pico_sdk_init()

add_executable(temperatura temperatura.c )

pico_set_program_name(temperatura "temperatura")
pico_set_program_version(temperatura "0.1")

pico_enable_stdio_uart(temperatura 0)
pico_enable_stdio_usb(temperatura 1)

# Adiciona a biblioteca ADC aqui
target_link_libraries(temperatura
        pico_stdlib
        hardware_adc
)

target_include_directories(temperatura PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(temperatura)
