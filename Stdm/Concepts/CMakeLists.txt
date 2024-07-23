cmake_minimum_required(VERSION 3.28)

add_custom_target(HUConcepts
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/concepts.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/concepts.pcm"
    COMMENT "Build concepts Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile concepts -o concepts.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Concepts.cpp
    COMMAND_EXPAND_LISTS)
