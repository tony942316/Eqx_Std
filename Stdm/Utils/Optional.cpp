module;

#include <optional>

export module Eqx.Stdm.Utils.Optional;

// Operations
export using std::operator==;
export using std::operator!=;
export using std::operator<;
export using std::operator<=;
export using std::operator>;
export using std::operator>=;
export using std::operator<=>;

export namespace stdm
{
    // Classes
    using std::optional;
    using std::bad_optional_access;
    using std::hash;
    using std::nullopt_t;

    // Constants
    using std::nullopt;

    // Specialized Algorithms
    using std::swap;
    using std::make_optional;
}
