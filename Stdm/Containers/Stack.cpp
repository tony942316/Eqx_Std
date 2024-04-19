module;

#include <stack>

export module Eqx.Stdm.Containers.Stack;

// Operators
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
    using std::stack;
    using std::uses_allocator;

    // Functions
    using std::swap;
}
