cmake_minimum_required(VERSION 3.28)

project(
    Stdm
    VERSION 0.1.0
    DESCRIPTION "C++ Standard Library As Modules"
    LANGUAGES CXX)

add_subdirectory(Stdm)
add_subdirectory(StdHeader)

add_executable(ModMain ModMain.cpp)
set_target_properties(ModMain PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(ModMain PRIVATE Stdm)

add_executable(HeaderMain HeaderMain.cpp)
set_target_properties(HeaderMain PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(HeaderMain PRIVATE StdHeader)
