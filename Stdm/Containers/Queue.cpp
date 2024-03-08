module;

#include <queue>

export module Stdm.Containers.Queue;

export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    using std::queue;
    using std::priority_queue;
    using std::uses_allocator;
    using std::swap;
}
