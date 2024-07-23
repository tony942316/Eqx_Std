cmake_minimum_required(VERSION 3.28)

add_custom_target(HUBit
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/bit.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/bit.pcm"
    COMMENT "Build bit Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile bit -o bit.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Bit.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUCompare
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/compare.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/compare.pcm"
    COMMENT "Build compare Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile compare -o compare.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Compare.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUException
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/exception.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/exception.pcm"
    COMMENT "Build exception Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile exception -o exception.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Exception.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUExecution
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/execution.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/execution.pcm"
    COMMENT "Build execution Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile execution -o execution.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Execution.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUFunctional
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/functional.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/functional.pcm"
    COMMENT "Build functional Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile functional -o functional.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Functional.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUInitializer_List
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/initializer_list.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/initializer_list.pcm"
    COMMENT "Build initializer_list Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile initializer_list -o initializer_list.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Initializer_List.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HULimits
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/limits.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/limits.pcm"
    COMMENT "Build limits Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile limits -o limits.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Limits.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUOptional
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/optional.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/optional.pcm"
    COMMENT "Build optional Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile optional -o optional.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Optional.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUSource_Location
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/source_location.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/source_location.pcm"
    COMMENT "Build source_location Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile source_location -o source_location.pcm
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source_Location.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUUtility
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/utility.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/utility.pcm"
    COMMENT "Build utility Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile utility -o utility.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Utility.cpp
    COMMAND_EXPAND_LISTS)
