# Eqx_Std

[![G++-14](https://github.com/tony942316/Eqx_Std/actions/workflows/ci_gcc_14.yml/badge.svg?branch=main)](https://github.com/tony942316/Eqx_Std/actions/workflows/ci_gcc_14.yml)
[![Clang-18](https://github.com/tony942316/Eqx_Std/actions/workflows/ci_clang_18.yml/badge.svg?branch=main)](https://github.com/tony942316/Eqx_Std/actions/workflows/ci_clang_18.yml)
[![CL](https://github.com/tony942316/Eqx_Std/actions/workflows/ci_cl.yml/badge.svg?branch=main)](https://github.com/tony942316/Eqx_Std/actions/workflows/ci_cl.yml)

**Eqx_Std** provides a portable, compiler-agnostic way to import the C++20
standard library and common operating system libraries as a header unit.
`import std;` support is uneven across compilers and build systems, and lacks
common macros such as `EXIT_SUCCESS`, `assert`, and `errno`, so **Eqx_Std**
seeks to fill this gap.
