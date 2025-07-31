cmake_minimum_required(VERSION 3.28)

add_executable(Basic)
target_sources(Basic PRIVATE Basic.cpp)
target_compile_features(Basic PRIVATE cxx_std_20)
target_link_libraries(Basic PRIVATE Eqx_Typical Eqx_Std)
set_target_properties(Basic PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_test(NAME Basic
    COMMAND $<TARGET_FILE:Basic>)
