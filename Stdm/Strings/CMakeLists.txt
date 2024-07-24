cmake_minimum_required(VERSION 3.28)

add_custom_target(HUString
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/string.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/string.pcm"
    COMMENT "Build string Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile string -o string.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/String.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUString_View
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/string_view.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/string_view.pcm"
    COMMENT "Build string_view Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-unknown-warning-option
        -Wno-sign-conversion -Wno-user-defined-literals
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile string_view -o string_view.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/String_View.cpp
    COMMAND_EXPAND_LISTS)
