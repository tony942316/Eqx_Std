cmake_minimum_required(VERSION 3.28)

add_custom_target(HUIterator
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/iterator.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/iterator.pcm"
    COMMENT "Build iterator Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile iterator -o iterator.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Iterator.cpp
    COMMAND_EXPAND_LISTS)
