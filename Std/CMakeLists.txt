cmake_minimum_required(VERSION 3.28)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Eqx_GMF INTERFACE /wd5105 /wd5244)
    target_compile_definitions(Eqx_GMF INTERFACE
        WIN32_LEAN_AND_MEAN
        NOGDICAPMASKS
        NOSYSMETRICS
        NOMENUS
        NOICONS
        NOSYSCOMMANDS
        NORASTEROPS
        OEMRESOURCE
        NOATOM
        NOCLIPBOARD
        NOCOLOR
        NOCTLMGR
        NODRAWTEXT
        NOKERNEL
        NONLS
        NOMEMMGR
        NOMETAFILE
        NOOPENFILE
        NOSCROLL
        NOSERVICE
        NOSOUND
        NOTEXTMETRIC
        NOWH
        NOCOMM
        NOKANJI
        NOHELP
        NOPROFILER
        NODEFERWINDOWPOS
        NOMCX
        NORPC
        NOPROXYSTUB
        NOIMAGE
        NOTAPE
        NOMINMAX)
    target_link_libraries(Eqx_GMF INTERFACE wsock32 ws2_32)
else ()
    add_custom_target(P_EQX_CT_STD
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/std.pcm")

    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/std.pcm"
        COMMENT "Build std Header Unit"
        COMMAND clang++ -std=c++20
            $<TARGET_PROPERTY:Eqx_GMF,INTERFACE_COMPILE_OPTIONS>
            -Wno-user-defined-literals
            -Wno-implicit-int-conversion
            -Wno-shorten-64-to-32
            -Wno-sign-conversion
            -Wno-unknown-warning-option
            -Wno-inline-namespace-reopened-noninline
            -Wno-deprecated-builtins
            -Wno-implicit-float-conversion
            -Wno-keyword-compat
            -Wno-gnu-include-next
            -Wno-ambiguous-ellipsis
            -Wno-pragma-system-header-outside-header

            -I${CMAKE_CURRENT_SOURCE_DIR}/include
            -xc++-system-header --precompile Eqx/std.hpp
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp"
        COMMAND_EXPAND_LISTS)

    add_library(P_EQX_HU_STD INTERFACE)
    add_dependencies(P_EQX_HU_STD P_EQX_CT_STD)
    target_compile_options(P_EQX_HU_STD INTERFACE
        -Wno-experimental-header-units
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/std.pcm)

    add_custom_target(P_EQX_CT_OS
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/os.pcm")

    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/os.pcm"
        COMMENT "Build os Header Unit"
        COMMAND clang++ -std=c++20
            $<TARGET_PROPERTY:Eqx_GMF,INTERFACE_COMPILE_OPTIONS>
            -Wno-user-defined-literals
            -Wno-implicit-int-conversion
            -Wno-shorten-64-to-32
            -Wno-sign-conversion
            -Wno-unknown-warning-option
            -Wno-inline-namespace-reopened-noninline
            -Wno-deprecated-builtins
            -Wno-implicit-float-conversion
            -Wno-keyword-compat
            -Wno-gnu-include-next
            -Wno-ambiguous-ellipsis
            -Wno-pragma-system-header-outside-header

            -I${CMAKE_CURRENT_SOURCE_DIR}/include
            -xc++-system-header --precompile Eqx/os.hpp
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp"
        COMMAND_EXPAND_LISTS)

    add_library(P_EQX_HU_OS INTERFACE)
    add_dependencies(P_EQX_HU_OS P_EQX_CT_OS)
    target_compile_options(P_EQX_HU_OS INTERFACE
        -Wno-experimental-header-units
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/os.pcm)

    target_compile_options(Eqx_GMF INTERFACE
        -fretain-comments-from-system-headers)
endif()

add_library(Eqx_Std INTERFACE)
target_sources(Eqx_Std INTERFACE include/Eqx/std.hpp include/Eqx/os.hpp)
target_compile_features(Eqx_Std INTERFACE cxx_std_20)
target_include_directories(Eqx_Std INTERFACE include)
target_link_libraries(Eqx_Std INTERFACE Eqx_GMF)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
    target_link_libraries(Eqx_Std INTERFACE P_EQX_HU_STD P_EQX_HU_OS)
endif()
