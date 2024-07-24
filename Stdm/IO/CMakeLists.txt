cmake_minimum_required(VERSION 3.28)

add_custom_target(HUFileSystem
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/filesystem.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/filesystem.pcm"
    COMMENT "Build filesystem Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile filesystem -o filesystem.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/FileSystem.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUFStream
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/fstream.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/fstream.pcm"
    COMMENT "Build fstream Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile fstream -o fstream.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/FStream.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUIOManip
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/iomanip.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/iomanip.pcm"
    COMMENT "Build iomanip Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile iomanip -o iomanip.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/IOManip.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUIOS
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/ios.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/ios.pcm"
    COMMENT "Build ios Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile ios -o ios.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/IOS.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUIOStream
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/iostream.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/iostream.pcm"
    COMMENT "Build iostream Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile iostream -o iostream.pcm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/IOStream.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUIStream
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/istream.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/istream.pcm"
    COMMENT "Build istream Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile istream -o istream.pcm
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/IStream.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUOStream
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/ostream.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/ostream.pcm"
    COMMENT "Build ostream Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header -xc++-system-header
        --precompile ostream -o ostream.pcm
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/OStream.cpp
    COMMAND_EXPAND_LISTS)

add_custom_target(HUStringStream
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/sstream.pcm")

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/sstream.pcm"
    COMMENT "Build sstream Header Unit"
    COMMAND clang++ -std=c++20 $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
        -Wno-pragma-system-header-outside-header
        -Wno-inline-namespace-reopened-noninline -xc++-system-header
        --precompile sstream -o sstream.pcm
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/StringStream.cpp
    COMMAND_EXPAND_LISTS)
