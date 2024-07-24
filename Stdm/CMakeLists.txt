cmake_minimum_required(VERSION 3.28)

add_library(GMF INTERFACE) # Global Module Flags

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
else ()
    add_subdirectory(Algorithms)
    add_subdirectory(Concepts)
    add_subdirectory(Concurrency)
    add_subdirectory(Containers)
    add_subdirectory(IO)
    add_subdirectory(Iterator)
    add_subdirectory(Locale)
    add_subdirectory(Meta)
    add_subdirectory(Numerics)
    add_subdirectory(Ranges)
    add_subdirectory(Strings)
    add_subdirectory(Time)
    add_subdirectory(Utils)
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
target_compile_options(Stdm PRIVATE -Wno-experimental-header-units
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Algorithms/algorithm.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Algorithms/numeric.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concepts/concepts.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/atomic.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/barrier.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/condition_variable.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/future.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/latch.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/mutex.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/semaphore.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Concurrency/thread.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/array.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/deque.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/forward_list.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/list.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/map.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/queue.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/set.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/span.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/stack.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/unordered_map.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/unordered_set.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Containers/vector.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/filesystem.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/fstream.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/iomanip.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/ios.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/iostream.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/istream.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/ostream.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/IO/sstream.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Iterator/iterator.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Locale/locale.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Meta/type_traits.pcm
    #-fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Numerics/cmath.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Numerics/complex.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Numerics/numbers.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Numerics/random.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Ranges/ranges.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Strings/string.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Strings/string_view.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Time/chrono.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/bit.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/compare.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/cstddef.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/cstdint.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/cstdlib.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/exception.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/execution.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/functional.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/initializer_list.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/limits.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/optional.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/source_location.pcm
    -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Utils/utility.pcm)
add_dependencies(Stdm
    HUAlgorithm HUNumeric
    HUConcepts
    HUAtomic HUBarrier HUCondition_Variable HUFuture HULatch HUMutex HUSemaphore
        HUThread
    HUArray HUDeque HUForward_List HUList HUMap HUQueue HUSet HUSpan HUStack
        HUUnordered_Map HUUnordered_Set HUVector
    HUFileSystem HUFStream HUIOManip HUIOS HUIOStream HUIStream HUOStream
        HUStringStream
    HUIterator
    HULocale
    HUType_Traits
    HUComplex HUNumbers HURandom
    HURanges
    HUString HUString_View
    HUChrono
    HUBit HUCompare HUCStdDef HUCStdInt HUCStdLib HUException HUExecution
        HUFunctional HUInitializer_List HULimits HUOptional HUSource_Location
        HUUtility)
endif()
