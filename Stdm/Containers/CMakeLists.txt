cmake_minimum_required(VERSION 3.28)

add_custom_target(HUArray
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/array.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/array.pcm"
    COMMENT "Build array Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile array -o array.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Array.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUDeque
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/deque.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/deque.pcm"
    COMMENT "Build deque Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile deque -o deque.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Deque.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUForward_List
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/forward_list.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/forward_list.pcm"
    COMMENT "Build forward_list Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile forward_list -o forward_list.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Forward_List.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUList
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/list.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/list.pcm"
    COMMENT "Build list Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile list -o list.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/List.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUMap
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/map.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/map.pcm"
    COMMENT "Build map Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile map -o map.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUQueue
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/queue.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/queue.pcm"
    COMMENT "Build queue Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile queue -o queue.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Queue.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUSet
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/set.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/set.pcm"
    COMMENT "Build set Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile set -o set.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Set.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUSpan
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/span.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/span.pcm"
    COMMENT "Build span Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile span -o span.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Span.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUStack
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/stack.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/stack.pcm"
    COMMENT "Build stack Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile stack -o stack.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Stack.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUUnordered_Map
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/unordered_map.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/unordered_map.pcm"
    COMMENT "Build unordered_map Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile unordered_map -o unordered_map.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Unordered_Map.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUUnordered_Set
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/unordered_set.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/unordered_set.pcm"
    COMMENT "Build unordered_set Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile unordered_set -o unordered_set.pcm
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Unordered_Set.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUVector
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/vector.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/vector.pcm"
    COMMENT "Build vector Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile vector -o vector.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
    COMMAND_EXPAND_LISTS)
