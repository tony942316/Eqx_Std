module;

#include <mutex>

export module Stdm.Concurrency.Mutex;

export namespace stdm
{
    // Classes
    using std::mutex;
    using std::timed_mutex;
    using std::recursive_mutex;
    using std::lock_guard;
    using std::unique_lock;
    using std::scoped_lock;
    using std::defer_lock_t;
    using std::try_to_lock_t;
    using std::adopt_lock_t;
    using std::once_flag;

    // Constants
    using std::defer_lock;
    using std::try_to_lock;
    using std::adopt_lock;

    // Functions
    using std::try_lock;
    using std::lock;
    using std::call_once;
    using std::swap;
}
