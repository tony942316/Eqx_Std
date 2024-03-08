cmake_minimum_required(VERSION 3.28)

project(
    Stdm
    VERSION 0.1.0
    DESCRIPTION "C++ Standard Library As Modules"
    LANGUAGES CXX)

add_library(Stdm)
target_sources(Stdm
    PUBLIC FILE_SET CXX_MODULES FILES
        Stdm/Stdm.cpp
        Stdm/Concepts.cpp
        Stdm/Containers.cpp
            Stdm/Containers/Vector.cpp
            Stdm/Containers/Deque.cpp
            Stdm/Containers/Array.cpp
            Stdm/Containers/List.cpp
            Stdm/Containers/Forward_List.cpp
            Stdm/Containers/Map.cpp
        Stdm/IO.cpp
            Stdm/IO/Iostream.cpp
        Stdm/Utils.cpp
            Stdm/Utils/Initializer_List.cpp)
target_compile_features(Stdm PUBLIC cxx_std_20)
set_target_properties(Stdm PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_executable(Hello Main.cpp)
set_target_properties(Hello PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(Hello PRIVATE Stdm)
