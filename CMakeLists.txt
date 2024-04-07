cmake_minimum_required(VERSION 3.28)

project(
    Stdm
    VERSION 0.1.0
    DESCRIPTION "C++ Standard Library As Modules"
    LANGUAGES CXX)

add_subdirectory(Stdm)
add_subdirectory(StdHeader)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(ModMain)
    target_sources(ModMain PRIVATE ModMain.cpp)
    target_compile_features(ModMain PRIVATE cxx_std_20)
    set_target_properties(ModMain PROPERTIES
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        EXPORT_COMPILE_COMMANDS On)
    target_link_libraries(ModMain PRIVATE Stdm)

    add_executable(HeaderMain)
    target_sources(HeaderMain PRIVATE HeaderMain.cpp)
    set_target_properties(HeaderMain PROPERTIES
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        EXPORT_COMPILE_COMMANDS On)
    target_link_libraries(HeaderMain PRIVATE StdHeader)
endif()
