cmake_minimum_required(VERSION 3.28)

add_library(StdHeader INTERFACE stdh.hpp)
target_include_directories(StdHeader INTERFACE .)
target_compile_features(StdHeader INTERFACE cxx_std_20)
