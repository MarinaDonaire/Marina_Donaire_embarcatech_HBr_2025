
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
set(sdkVersion 1.5.1)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK 
include(pico_sdk_import.cmake)

project(temperatura_tu C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()


add_executable(temperatura_tu 
    main.c 
    adc_to_celsius.c  
)

pico_set_program_name(temperatura_tu "temperatura_tu")
pico_set_program_version(temperatura_tu "0.1")


pico_enable_stdio_uart(temperatura_tu 0)
pico_enable_stdio_usb(temperatura_tu 1)


target_link_libraries(temperatura_tu
    pico_stdlib
    hardware_adc  
)

target_include_directories(temperatura_tu PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)


target_link_libraries(temperatura_tu 
    
)

pico_add_extra_outputs(temperatura_tu)
