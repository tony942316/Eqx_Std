# CMakeLists.txt

cmake_minimum_required(VERSION 3.28)

add_library(Test_Module STATIC)
target_sources(Test_Module PUBLIC
    FILE_SET CXX_MODULES FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Module.cpp)
target_compile_features(Test_Module PRIVATE cxx_std_20)
target_link_libraries(Test_Module PUBLIC Eqx_Std)
set_target_properties(Test_Module PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_library(Test_Module_Typical STATIC)
target_sources(Test_Module_Typical PUBLIC
    FILE_SET CXX_MODULES FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Module.cpp)
target_compile_features(Test_Module_Typical PRIVATE cxx_std_20)
target_link_libraries(Test_Module_Typical PUBLIC Eqx_Std_Typical)
set_target_properties(Test_Module_Typical PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_executable(Test_Module_Main)
target_sources(Test_Module_Main PRIVATE Main.cpp)
target_compile_features(Test_Module_Main PRIVATE cxx_std_20)
target_link_libraries(Test_Module_Main PRIVATE Test_Module)
set_target_properties(Test_Module_Main PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

add_executable(Test_Module_Main_Typical)
target_sources(Test_Module_Main_Typical PRIVATE Main.cpp)
target_compile_features(Test_Module_Main_Typical PRIVATE cxx_std_20)
target_link_libraries(Test_Module_Main_Typical PRIVATE Test_Module_Typical)
set_target_properties(Test_Module_Main_Typical PROPERTIES
    CXX_STANDARD_REQUIRED On
    EXPORT_COMPILE_COMMANDS On
    CXX_EXTENSIONS Off)

eqx_copy_asan(Test_Module_Main_Typical)

add_test(NAME Module_Main
    COMMAND $<TARGET_FILE:Test_Module_Main>)

add_test(NAME Module_Main_Typical
    COMMAND $<TARGET_FILE:Test_Module_Main_Typical>)
