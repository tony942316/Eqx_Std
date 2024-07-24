cmake_minimum_required(VERSION 3.28)

add_custom_target(HUAtomic
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/atomic.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/atomic.pcm"
    COMMENT "Build atomic Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile atomic -o atomic.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Atomic.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUBarrier
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/barrier.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/barrier.pcm"
    COMMENT "Build barrier Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile barrier -o barrier.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Barrier.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUCondition_Variable
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/condition_variable.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/condition_variable.pcm"
    COMMENT "Build condition_variable Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile condition_variable -o condition_variable.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Condition_Variable.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUFuture
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/future.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/future.pcm"
    COMMENT "Build future Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile future -o future.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Future.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HULatch
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/latch.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/latch.pcm"
    COMMENT "Build latch Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-shorten-64-to-32 -Wno-pragma-system-header-outside-header
        -xc++-system-header --precompile latch -o latch.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Latch.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUMutex
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/mutex.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/mutex.pcm"
    COMMENT "Build mutex Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile mutex -o mutex.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Mutex.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUSemaphore
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/semaphore.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/semaphore.pcm"
    COMMENT "Build semaphore Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile semaphore -o semaphore.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Semaphore.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUThread
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/thread.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/thread.pcm"
    COMMENT "Build thread Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile thread -o thread.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Thread.cpp
    COMMAND_EXPAND_LISTS)
