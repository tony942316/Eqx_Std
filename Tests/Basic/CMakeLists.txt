# CMakeLists.txt

cmake_minimum_required(VERSION 3.28)

add_executable(Basic_Main)
target_sources(Basic_Main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)
target_compile_features(Basic_Main PRIVATE cxx_std_20)
target_link_libraries(Basic_Main PRIVATE Eqx_Std)
set_target_properties(Basic_Main PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_executable(Basic_Main_Typical)
target_sources(Basic_Main_Typical PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)
target_compile_features(Basic_Main_Typical PRIVATE cxx_std_20)
target_link_libraries(Basic_Main_Typical PRIVATE Eqx_Std_Typical)
set_target_properties(Basic_Main_Typical PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

eqx_copy_asan(Basic_Main_Typical)

add_test(NAME Basic_Main
    COMMAND $<TARGET_FILE:Basic_Main>)

add_test(NAME Basic_Main_Typical
    COMMAND $<TARGET_FILE:Basic_Main_Typical>)
