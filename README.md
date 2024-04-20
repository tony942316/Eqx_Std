# Stdm

## Contents

1. [Summary](#summary)
2. [Features](#features)
3. [Usage](#usage)

## Summary <a name="summary"></a>

Stdm is the entire c++20 standard library exposed as c++20 modules, given that
`import std;` is a c++23 feature and c++23 has yet to be implemented by the
major compilers it became convenient to give c++20 projects the compilation time
benefits of modules. Compiling c++20 modules by hand is tedious so it is
recommended to use CMake 3.28+ to handle the compiliation.

Basic Example ->
```cmake
#CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_subdirectory(path/to/Stdm)

add_executable(Main)
target_sources(Main PRIVATE Main.cpp)
target_compile_features(cxx_std_20)
target_link_libraries(Main PRIVATE Stdm)
set_target_properties(Main PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)

# Modules need to be compiled with the same flags as the executables they are
# linked to, the GMF (Global Module Flags) target is made available to allow
# for both Stdm and Main to be compiled with the -fno-rtti flag
target_compile_options(GMF INTERFACE -fno-rtti)
```
```c++
// Main.cpp
import Eqx.Stdm

int main()
{
    stdm::cout << "Hello" << stdm::endl;
    return 0;
}
```

## Features <a name="features"></a>

Stdm is organized into various submodules, the structure is as follows:

- Stdm
    - Algorithms
        - Algorithm
        - Numeric
    - Concepts
        - Concepts
    - Concurrency
        - Atomic
        - Barrier
        - Condition_Variable
        - Future
        - Latch
        - Mutex
        - Semaphore
        - Thread

Importing a submodules is performed like so `import Eqx.Stdm.Concurrency.Latch`,
you can also import the entire library `import Eqx.Stdm` or a sub library of
the standard library `import Eqx.Stdm.Concurrency`. Stdm is exposed under the
namespace `stdm` instead of `std`, this is to avoid affecting the `std`
namespace.

## Usage <a name="usage"></a>


