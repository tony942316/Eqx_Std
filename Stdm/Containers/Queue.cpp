module;

#include <queue>

export module Eqx.Stdm.Containers.Queue;

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
    using std::queue;
    using std::priority_queue;
    using std::uses_allocator;

    // Functions
    using std::swap;
}
