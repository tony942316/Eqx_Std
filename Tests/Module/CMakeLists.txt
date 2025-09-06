# CMakeLists.txt

cmake_minimum_required(VERSION 3.28)

add_library(Module STATIC)
target_sources(Module PUBLIC
    FILE_SET CXX_MODULES FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Module.cpp)
target_compile_features(Module PRIVATE cxx_std_20)
target_link_libraries(Module PUBLIC Eqx_Std)
set_target_properties(Module PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_library(Module_Typical STATIC)
target_sources(Module_Typical PUBLIC
    FILE_SET CXX_MODULES FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Module.cpp)
target_compile_features(Module_Typical PRIVATE cxx_std_20)
target_link_libraries(Module_Typical PUBLIC Eqx_Std_Typical)
set_target_properties(Module_Typical PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_executable(Module_Main)
target_sources(Module_Main PRIVATE Main.cpp)
target_compile_features(Module_Main PRIVATE cxx_std_20)
target_link_libraries(Module_Main PRIVATE Module)
set_target_properties(Module_Main PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_executable(Module_Main_Typical)
target_sources(Module_Main_Typical PRIVATE Main.cpp)
target_compile_features(Module_Main_Typical PRIVATE cxx_std_20)
target_link_libraries(Module_Main_Typical PRIVATE Module_Typical)
set_target_properties(Module_Main_Typical PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

eqx_copy_asan(Module_Main_Typical)

add_test(NAME Module_Main
    COMMAND $<TARGET_FILE:Module_Main>)

add_test(NAME Module_Main_Typical
    COMMAND $<TARGET_FILE:Module_Main_Typical>)
