cmake_minimum_required(VERSION 3.28)

add_library(Tests STATIC)
target_sources(Tests
    PUBLIC FILE_SET CXX_MODULES FILES
        Tests.cpp
        TestStdm/TestContainers/TestArray.cpp)
target_compile_features(Tests PUBLIC cxx_std_20)
set_target_properties(Tests PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(Tests PUBLIC Stdm)

add_executable(ProvingGrounds)
target_sources(ProvingGrounds PRIVATE ProvingGrounds.cpp)
target_compile_features(ProvingGrounds PRIVATE cxx_std_20)
set_target_properties(ProvingGrounds PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(ProvingGrounds PRIVATE Tests)
