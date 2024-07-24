cmake_minimum_required(VERSION 3.28)

add_custom_target(HURanges
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/ranges.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/ranges.pcm"
    COMMENT "Build ranges Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-unknown-warning-option -Wno-pragma-system-header-outside-header
        -xc++-system-header --precompile ranges -o ranges.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Ranges.cpp
    COMMAND_EXPAND_LISTS)
