cmake_minimum_required(VERSION 3.28)

add_executable(Test_Basic_Main)
target_sources(Test_Basic_Main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Basic.cpp)
target_compile_features(Test_Basic_Main PRIVATE cxx_std_20)
target_link_libraries(Test_Basic_Main PRIVATE Eqx_Std)
set_target_properties(Test_Basic_Main PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

add_executable(Test_Basic_Main_Typical)
target_sources(Test_Basic_Main_Typical PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Basic.cpp)
target_compile_features(Test_Basic_Main_Typical PRIVATE cxx_std_20)
target_link_libraries(Test_Basic_Main_Typical PRIVATE Eqx_Std_Typical)
set_target_properties(Test_Basic_Main_Typical PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

eqx_copy_asan(Test_Basic_Main_Typical)

add_test(NAME Basic_Main
    COMMAND $<TARGET_FILE:Test_Basic_Main>)

add_test(NAME Basic_Main_Typical
    COMMAND $<TARGET_FILE:Test_Basic_Main_Typical>)
