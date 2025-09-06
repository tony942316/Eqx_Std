cmake_minimum_required(VERSION 3.28)

eqx_add_headerunit(Eqx_Std_cxx)
target_sources(Eqx_Std_cxx INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp)
target_include_directories(Eqx_Std_cxx INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/)

eqx_add_headerunit(Eqx_Std_cxx_Typical)
target_sources(Eqx_Std_cxx_Typical INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/std.hpp)
target_include_directories(Eqx_Std_cxx_Typical INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(Eqx_Std_cxx_Typical_PRIVATE INTERFACE Eqx_Typical)
target_link_libraries(Eqx_Std_cxx_Typical INTERFACE Eqx_Typical)

eqx_add_headerunit(Eqx_Std_os)
target_sources(Eqx_Std_os INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp)
target_include_directories(Eqx_Std_os INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/)

eqx_add_headerunit(Eqx_Std_os_Typical)
target_sources(Eqx_Std_os_Typical INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Eqx/os.hpp)
target_include_directories(Eqx_Std_os_Typical INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(Eqx_Std_os_Typical_PRIVATE INTERFACE Eqx_Typical)
target_link_libraries(Eqx_Std_os_Typical INTERFACE Eqx_Typical)

add_library(Eqx_Std INTERFACE)
target_link_libraries(Eqx_Std INTERFACE
    Eqx_Std_os Eqx_Std_cxx)

add_library(Eqx_Std_Typical INTERFACE)
target_link_libraries(Eqx_Std_Typical INTERFACE
    Eqx_Std_os_Typical Eqx_Std_cxx_Typical)
