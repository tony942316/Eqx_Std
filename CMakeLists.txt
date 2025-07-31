cmake_minimum_required(VERSION 3.28)

project(Eqx_Std
    VERSION 0.10.0.0
    DESCRIPTION "Importable C++20 Standard Library And Operating System Headers"
    HOMEPAGE_URL "https://github.com/tony942316/Eqx_Std"
    LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    Eqx_CMakeInterfaces
    GIT_REPOSITORY https://github.com/tony942316/Eqx_CMakeInterfaces.git
    GIT_TAG main)

FetchContent_MakeAvailable(Eqx_CMakeInterfaces)

add_subdirectory(Std/)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
    add_subdirectory(Tests/)
endif()
