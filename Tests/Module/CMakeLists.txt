cmake_minimum_required(VERSION 3.28)

add_library(Module STATIC)
target_sources(Module PUBLIC
    FILE_SET CXX_MODULES FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Module.cpp)
target_compile_features(Module PRIVATE cxx_std_20)
target_link_libraries(Module PUBLIC Eqx_Std)
set_target_properties(Module PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_executable(Main)
target_sources(Main PRIVATE Main.cpp)
target_compile_features(Main PRIVATE cxx_std_20)
target_link_libraries(Main PRIVATE Module)
set_target_properties(Main PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_test(NAME Module_Smoke
    COMMAND $<TARGET_FILE:Main>)
