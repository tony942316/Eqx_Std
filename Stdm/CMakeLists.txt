cmake_minimum_required(VERSION 3.28)

add_library(Stdm STATIC)
target_sources(Stdm
    PUBLIC FILE_SET CXX_MODULES FILES
        Stdm.cpp
        Algorithms.cpp
            Algorithms/Algorithm.cpp
            Algorithms/Numeric.cpp
        Concepts.cpp
            Concepts/Concepts.cpp
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
            IO/Iostream.cpp
            IO/StringStream.cpp
        Iterator.cpp
            Iterator/Iterator.cpp
        Meta.cpp
            Meta/Type_Traits.cpp
        Numerics.cpp
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
            Utils/CStdDef.cpp
            Utils/CStdInt.cpp
            Utils/Functional.cpp
            Utils/Initializer_List.cpp
            Utils/Limits.cpp
            Utils/Optional.cpp
            Utils/Source_Location.cpp)
target_compile_features(Stdm PUBLIC cxx_std_20)
set_target_properties(Stdm PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
