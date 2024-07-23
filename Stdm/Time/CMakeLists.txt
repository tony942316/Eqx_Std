cmake_minimum_required(VERSION 3.28)

add_custom_target(HUChrono
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/chrono.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/chrono.pcm"
    COMMENT "Build chrono Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile chrono -o chrono.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Chrono.cpp
    COMMAND_EXPAND_LISTS)
