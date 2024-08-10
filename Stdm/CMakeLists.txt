cmake_minimum_required(VERSION 3.28)

add_library(GMF INTERFACE) # Global Module Flags

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
    function(makeht arg1 arg2)
        add_custom_target("CT_${arg1}"
            DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${arg1}.pcm")

        add_custom_command(
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${arg1}.pcm"
            COMMENT "Build ${arg1} Header Unit"
            COMMAND clang++ -std=c++20
                $<TARGET_PROPERTY:GMF,INTERFACE_COMPILE_OPTIONS>
                -Wno-user-defined-literals
                -Wno-implicit-int-conversion
                -Wno-shorten-64-to-32
                -Wno-sign-conversion
                -Wno-unknown-warning-option
                -Wno-inline-namespace-reopened-noninline
                -Wno-deprecated-builtins
                -Wno-implicit-float-conversion
                -Wno-keyword-compat
                -Wno-gnu-include-next
                -Wno-ambiguous-ellipsis
                -Wno-pragma-system-header-outside-header

                -xc++-system-header --precompile ${arg1}
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${arg2}"
            COMMAND_EXPAND_LISTS)

        add_library(HU${arg1} INTERFACE)
        add_dependencies(HU${arg1} CT_${arg1})
        target_compile_options(HU${arg1} INTERFACE
            -Wno-experimental-header-units
            -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/${arg1}.pcm)
    endfunction()

    makeht(algorithm Algorithms/Algorithm.cpp)
    makeht(numeric Algorithms/Numeric.cpp)

    makeht(concepts Concepts/Concepts.cpp)

    makeht(atomic Concurrency/Atomic.cpp)
    #makeht(barrier Basic.cpp)
    makeht(condition_variable Concurrency/Condition_Variable.cpp)
    makeht(future Concurrency/Future.cpp)
    makeht(latch Concurrency/Latch.cpp)
    makeht(mutex Concurrency/Mutex.cpp)
    #makeht(semaphore Basic.cpp)
    makeht(thread Concurrency/Thread.cpp)

    makeht(array Containers/Array.cpp)
    makeht(deque Containers/Deque.cpp)
    makeht(forward_list Containers/Forward_List.cpp)
    makeht(list Containers/List.cpp)
    makeht(map Containers/Map.cpp)
    makeht(queue Containers/Queue.cpp)
    makeht(set Containers/Set.cpp)
    makeht(span Containers/Span.cpp)
    makeht(stack Containers/Stack.cpp)
    makeht(unordered_map Containers/Unordered_Map.cpp)
    makeht(unordered_set Containers/Unordered_Set.cpp)
    makeht(vector Containers/Vector.cpp)

    makeht(filesystem IO/FileSystem.cpp)
    makeht(fstream IO/FStream.cpp)
    makeht(iomanip IO/IOManip.cpp)
    makeht(ios IO/IOS.cpp)
    makeht(iostream IO/IOStream.cpp)
    makeht(istream IO/IStream.cpp)
    makeht(ostream IO/OStream.cpp)
    makeht(sstream IO/StringStream.cpp)

    makeht(iterator Iterator/Iterator.cpp)

    makeht(locale Locale/Locale.cpp)

    makeht(type_traits Meta/Type_Traits.cpp)

    #makeht(cmath Basic.cpp)
    makeht(complex Numerics/Complex.cpp)
    makeht(numbers Numerics/Numbers.cpp)
    makeht(random Numerics/Random.cpp)

    makeht(ranges Ranges/Ranges.cpp)

    makeht(string Strings/String.cpp)
    makeht(string_view Strings/String_View.cpp)

    makeht(chrono Time/Chrono.cpp)

    makeht(bit Utils/Bit.cpp)
    makeht(compare Utils/Compare.cpp)
    makeht(cstddef Utils/CStdDef.cpp)
    makeht(cstdint Utils/CStdInt.cpp)
    makeht(cstdlib Utils/CStdLib.cpp)
    makeht(exception Utils/Exception.cpp)
    makeht(execution Utils/Execution.cpp)
    makeht(functional Utils/Functional.cpp)
    makeht(initializer_list Utils/Initializer_List.cpp)
    makeht(limits Utils/Limits.cpp)
    makeht(optional Utils/Optional.cpp)
    makeht(source_location Utils/Source_Location.cpp)
    makeht(utility Utils/Utility.cpp)
endif()

add_library(Stdm STATIC)
target_sources(Stdm
    PUBLIC FILE_SET CXX_MODULES FILES
        Stdm.cpp
        Algorithms.cpp
            Algorithms/Algorithm.cpp
            Algorithms/Numeric.cpp
        Concepts.cpp
            Concepts/Concepts.cpp
        Concurrency.cpp
            Concurrency/Atomic.cpp
            Concurrency/Barrier.cpp
            Concurrency/Condition_Variable.cpp
            Concurrency/Future.cpp
            Concurrency/Latch.cpp
            Concurrency/Mutex.cpp
            Concurrency/Semaphore.cpp
            Concurrency/Thread.cpp
        Containers.cpp
            Containers/Array.cpp
            Containers/Deque.cpp
            Containers/Forward_List.cpp
            Containers/List.cpp
            Containers/Map.cpp
            Containers/Queue.cpp
            Containers/Set.cpp
            Containers/Span.cpp
            Containers/Stack.cpp
            Containers/Unordered_Map.cpp
            Containers/Unordered_Set.cpp
            Containers/Vector.cpp
        IO.cpp
            IO/FileSystem.cpp
            IO/FStream.cpp
            IO/IOManip.cpp
            IO/IOS.cpp
            IO/IOStream.cpp
            IO/IStream.cpp
            IO/OStream.cpp
            IO/StringStream.cpp
        Iterator.cpp
            Iterator/Iterator.cpp
        Locale.cpp
            Locale/Locale.cpp
        Meta.cpp
            Meta/Type_Traits.cpp
        Numerics.cpp
            Numerics/CMath.cpp
            Numerics/Complex.cpp
            Numerics/Numbers.cpp
            Numerics/Random.cpp
        Ranges.cpp
            Ranges/Ranges.cpp
        Strings.cpp
            Strings/String.cpp
            Strings/String_View.cpp
        Time.cpp
            Time/Chrono.cpp
        Utils.cpp
            Utils/Bit.cpp
            Utils/Compare.cpp
            Utils/CStdDef.cpp
            Utils/CStdInt.cpp
            Utils/CStdLib.cpp
            Utils/Exception.cpp
            Utils/Execution.cpp
            Utils/Functional.cpp
            Utils/Initializer_List.cpp
            Utils/Limits.cpp
            Utils/Optional.cpp
            Utils/Source_Location.cpp
            Utils/Utility.cpp)
target_compile_features(Stdm PUBLIC cxx_std_20)
target_link_libraries(Stdm PUBLIC GMF)

set_target_properties(Stdm PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
target_link_libraries(Stdm PRIVATE
    HUalgorithm HUnumeric
    HUconcepts
    HUatomic HUcondition_variable HUfuture HUlatch HUmutex HUthread
    HUarray HUdeque HUforward_list HUlist HUmap HUqueue HUset HUspan HUstack
        HUunordered_map HUunordered_set HUvector
    HUfilesystem HUfstream HUiomanip HUios HUiostream HUistream HUostream
        HUsstream
    HUiterator
    HUlocale
    HUtype_traits
    HUcomplex HUnumbers HUrandom
    HUranges
    HUstring HUstring_view
    HUchrono
    HUbit HUcompare HUcstddef HUcstdint HUcstdlib HUexception HUexecution
        HUfunctional HUinitializer_list HUlimits HUoptional HUsource_location
        HUutility)
endif()
