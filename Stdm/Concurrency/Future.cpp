module;

#include <future>

export module Stdm.Concurrency.Future;

export namespace stdm
{
    // Classes
    using std::promise;
    using std::packaged_task;
    using std::future;
    using std::shared_future;
    using std::launch;
    using std::future_status;
    using std::future_error;
    using std::uses_allocator;

    // Functions
    using std::async;
    using std::future_category;
    using std::swap;
}
