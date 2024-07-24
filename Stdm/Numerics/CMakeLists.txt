cmake_minimum_required(VERSION 3.28)

add_custom_target(HUComplex
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/complex.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/complex.pcm"
    COMMENT "Build complex Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-implicit-float-conversion -Wno-unknown-warning-option
        -Wno-user-defined-literals -Wno-pragma-system-header-outside-header
        -xc++-system-header --precompile complex -o complex.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Complex.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUNumbers
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/numbers.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/numbers.pcm"
    COMMENT "Build numbers Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile numbers -o numbers.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Numbers.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HURandom
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/random.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/random.pcm"
    COMMENT "Build random Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile random -o random.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
    COMMAND_EXPAND_LISTS)
