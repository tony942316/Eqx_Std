cmake_minimum_required(VERSION 3.28)

project(
    Stdm
    VERSION 0.1.0
    DESCRIPTION "C++ Standard Library As Modules"
    LANGUAGES CXX)

add_library(Stdm STATIC)
target_sources(Stdm
    PUBLIC FILE_SET CXX_MODULES FILES
        Stdm/Stdm.cpp
        Stdm/Concepts.cpp
        Stdm/Containers.cpp
            Stdm/Containers/Array.cpp
            Stdm/Containers/Deque.cpp
            Stdm/Containers/Forward_List.cpp
            Stdm/Containers/List.cpp
            Stdm/Containers/Map.cpp
            Stdm/Containers/Queue.cpp
            Stdm/Containers/Set.cpp
            Stdm/Containers/Span.cpp
            Stdm/Containers/Stack.cpp
            Stdm/Containers/Unordered_Map.cpp
            Stdm/Containers/Unordered_Set.cpp
            Stdm/Containers/Vector.cpp
        Stdm/IO.cpp
            Stdm/IO/Iostream.cpp
        Stdm/Utils.cpp
            Stdm/Utils/Initializer_List.cpp)
target_compile_features(Stdm PUBLIC cxx_std_20)
set_target_properties(Stdm PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_library(StdHeader INTERFACE StdHeader/stdh.hpp)
target_include_directories(StdHeader INTERFACE StdHeader)
target_compile_features(StdHeader INTERFACE cxx_std_20)

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
