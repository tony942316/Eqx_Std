cmake_minimum_required(VERSION 3.28)

add_custom_target(HUAlgorithm
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/algorithm.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/algorithm.pcm"
    COMMENT "Build algorithm Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile algorithm -o algorithm.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Algorithm.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUNumeric
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/numeric.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/numeric.pcm"
    COMMENT "Build numeric Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile numeric -o numeric.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Numeric.cpp
    COMMAND_EXPAND_LISTS)
