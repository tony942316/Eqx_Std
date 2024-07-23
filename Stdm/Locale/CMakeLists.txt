cmake_minimum_required(VERSION 3.28)

add_custom_target(HULocale
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/locale.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/locale.pcm"
    COMMENT "Build locale Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile locale -o locale.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Locale.cpp
    COMMAND_EXPAND_LISTS)
