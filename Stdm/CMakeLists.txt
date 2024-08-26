cmake_minimum_required(VERSION 3.28)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(GMF INTERFACE /wd5244)
else ()
    add_custom_target(CT_stdc++
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/stdc++.pcm")

    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/stdc++.pcm"
        COMMENT "Build stdc++ Header Unit"
        COMMAND clang++ -std=c++20
            $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
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

            -xc++-system-header --precompile bits/stdc++.h
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp"
        COMMAND_EXPAND_LISTS)

    add_library(HUstdc++ INTERFACE)
    add_dependencies(HUstdc++ CT_stdc++)
    target_compile_options(HUstdc++ INTERFACE
        -Wno-experimental-header-units
        -Wno-include-angled-in-module-purview
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/stdc++.pcm)

    add_custom_target(CT_osc++
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/unistd.pcm")

    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/unistd.pcm"
        COMMENT "Build unistd Header Unit"
        COMMAND clang++ -std=c++20
            $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
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

            -xc++-system-header --precompile unistd.h sys/types.h sys/socket.h
                netinet/in.h netdb.h arpa/inet.h
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp"
        COMMAND_EXPAND_LISTS)

    add_library(HUosc++ INTERFACE)
    add_dependencies(HUosc++ CT_osc++)
    target_compile_options(HUosc++ INTERFACE
        -Wno-experimental-header-units
        -Wno-include-angled-in-module-purview
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/unistd.pcm
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/types.pcm
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/socket.pcm
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/in.pcm
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/netdb.pcm
        -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/inet.pcm)

    target_compile_options(GMF INTERFACE -fretain-comments-from-system-headers)
endif()

add_library(Stdm INTERFACE)
target_sources(Stdm INTERFACE include/Eqx/std.hpp include/Eqx/os.hpp)
target_compile_features(Stdm INTERFACE cxx_std_20)
target_include_directories(Stdm INTERFACE include)
target_link_libraries(Stdm INTERFACE GMF)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
    target_link_libraries(Stdm INTERFACE HUstdc++ HUosc++)
endif()
