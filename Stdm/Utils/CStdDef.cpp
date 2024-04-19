module;

#include <cstddef>

export module Eqx.Stdm.Utils.CStdDef;

export namespace stdm
{
    // Macros
    constexpr auto c_NULL = NULL;

    // Types
    using std::size_t;
    using std::ptrdiff_t;
    using std::nullptr_t;
    using std::max_align_t;
    using std::byte;

    // Functions
    using std::to_integer;
}
