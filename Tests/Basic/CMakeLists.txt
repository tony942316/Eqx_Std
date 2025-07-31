cmake_minimum_required(VERSION 3.28)

add_executable(Basic)
target_sources(Basic PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Basic.cpp)
target_compile_features(Basic PRIVATE cxx_std_20)
target_link_libraries(Basic PRIVATE Eqx_Typical Eqx_Std)
set_target_properties(Basic PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

if (Eqx_MSVC)
    add_custom_command(TARGET Basic POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/clang_rt.asan_dynamic-x86_64.dll
            $<TARGET_FILE_DIR:Basic>)
elseif (Eqx_Clang OR Eqx_GNU)

else()
    message(FATAL_ERROR "Invalid Configuration!")
endif()

add_test(NAME Basic
    COMMAND $<TARGET_FILE:Basic>)
