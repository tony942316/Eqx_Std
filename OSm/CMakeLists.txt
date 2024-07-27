cmake_minimum_required(VERSION 3.28)

add_library(OSm STATIC)
target_sources(OSm
    PUBLIC FILE_SET CXX_MODULES FILES
        OSm.cpp)
target_compile_features(OSm PUBLIC cxx_std_20)
target_link_libraries(OSm PUBLIC GMF)
set_target_properties(OSm PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
