cmake_minimum_required(VERSION 3.28)

add_library(OSHeader INTERFACE osh.hpp)
target_include_directories(OSHeader INTERFACE .)
target_compile_features(OSHeader INTERFACE cxx_std_20)
