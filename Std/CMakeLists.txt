cmake_minimum_required(VERSION 3.28)

add_library(Eqx_Std INTERFACE)
target_sources(Eqx_Std INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp)
target_include_directories(Eqx_Std INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/)

if (Eqx_Clang)
    add_custom_command(
        OUTPUT
            ${CMAKE_CURRENT_BINARY_DIR}/std_$<CONFIG>.pcm
            ${CMAKE_CURRENT_BINARY_DIR}/os_$<CONFIG>.pcm
        COMMAND ${CMAKE_CXX_COMPILER}
            -std=c++20 -fmodule-header
            $<TARGET_PROPERTY:Eqx_Typical,INTERFACE_COMPILE_OPTIONS>
            ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp -o
            ${CMAKE_CURRENT_BINARY_DIR}/std_$<CONFIG>.pcm
        COMMAND ${CMAKE_CXX_COMPILER}
            -std=c++20 -fmodule-header
            $<TARGET_PROPERTY:Eqx_Typical,INTERFACE_COMPILE_OPTIONS>
            ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp -o
            ${CMAKE_CURRENT_BINARY_DIR}/os_$<CONFIG>.pcm
        DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp
        COMMENT "Building Std and OS modules"
        COMMAND_EXPAND_LISTS)

    add_custom_target(Eqx_PT_STD_OS DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/std_$<CONFIG>.pcm
        ${CMAKE_CURRENT_BINARY_DIR}/os_$<CONFIG>.pcm)

    target_compile_options(Eqx_Std INTERFACE
        -Wno-experimental-header-units
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/std_$<CONFIG>.pcm
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/os_$<CONFIG>.pcm)
    add_dependencies(Eqx_Std Eqx_PT_STD_OS)
elseif (Eqx_GNU)
elseif (Eqx_MSVC)
endif()
