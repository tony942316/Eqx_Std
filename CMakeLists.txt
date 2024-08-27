cmake_minimum_required(VERSION 3.28)

project(Eqx_Std
    VERSION 0.9.0
    DESCRIPTION "Importable C++20 Standard Library And Operating System Headers"
    LANGUAGES CXX)

add_library(Eqx_GMF INTERFACE) # Global Module Flags

add_subdirectory(Std)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(ProvingGrounds)
endif()
