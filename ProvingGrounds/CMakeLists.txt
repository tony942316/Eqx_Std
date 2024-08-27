cmake_minimum_required(VERSION 3.28)

message("Compiler is: ${CMAKE_CXX_COMPILER_ID}")

add_library(Tests STATIC)
target_sources(Tests
    PUBLIC FILE_SET CXX_MODULES FILES
        Tests.cpp)
target_compile_features(Tests PUBLIC cxx_std_20)
set_target_properties(Tests PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(Tests PRIVATE Eqx_Std)

add_executable(ProvingGrounds)
target_sources(ProvingGrounds PRIVATE Main.cpp)
target_compile_features(ProvingGrounds PRIVATE cxx_std_20)
set_target_properties(ProvingGrounds PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(ProvingGrounds PRIVATE Eqx_Std Tests)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Eqx_GMF INTERFACE
        /W4 /WX
        /GR-)
else ()
    target_compile_options(Eqx_GMF INTERFACE
        -Wall -Wextra -Wpedantic -Wconversion
        -Werror
        -fno-rtti)
endif()
