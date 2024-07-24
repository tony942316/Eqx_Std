cmake_minimum_required(VERSION 3.28)

add_custom_target(HUType_Traits
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/type_traits.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/type_traits.pcm"
    COMMENT "Build type_traits Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-deprecated-builtins -Wno-pragma-system-header-outside-header
        -Wno-keyword-compat -xc++-system-header
        --precompile type_traits -o type_traits.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Type_Traits.cpp
    COMMAND_EXPAND_LISTS)
