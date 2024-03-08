module;

#include <stack>

export module Stdm.Containers.Stack;

export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    using std::stack;
    using std::uses_allocator;
    using std::swap;
}
