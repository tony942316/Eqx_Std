module;

#include <cstdlib>

export module Stdm.Utils.CStdLib;

export namespace stdm
{
    // Types
    using std::div_t;
    using std::ldiv_t;
    using std::lldiv_t;
    using std::size_t;

    // Macro Constants
    inline constexpr auto Exit_Success = EXIT_SUCCESS;
    inline constexpr auto Exit_Failure = EXIT_FAILURE;
    inline constexpr auto Null = NULL;
    inline constexpr auto Rand_Max = RAND_MAX;

    // Process Control
    using std::abort;
    using std::exit;
    using std::quick_exit;
    using std::_Exit; // NOLINT
    using std::atexit;
    using std::at_quick_exit;
    using std::system;
    using std::getenv;

    // Memory Management
    using std::malloc;
#ifndef _WIN32
    using std::aligned_alloc;
#endif // _WIN32
    using std::calloc;
    using std::realloc;
    using std::free;

    // Numeric String Conversion
    using std::atof;
    using std::atoi;
    using std::atol;
    using std::atoll;
    using std::strtol;
    using std::strtoll;
    using std::strtoul;
    using std::strtoull;
    using std::strtof;
    using std::strtod;
    using std::strtold;

    // Wide String Manipulation
    using std::mblen;
    using std::mbtowc;
    using std::wctomb;
    using std::mbstowcs;
    using std::wcstombs;

    // Miscellaneous Algorithms And Math
    using std::rand;
    using std::srand;
    using std::qsort;
    using std::bsearch;
    using std::abs;
    using std::labs;
    using std::llabs;
    using std::div;
    using std::ldiv;
    using std::lldiv;
}
