module;

#include <condition_variable>

export module Stdm.Concurrency.Condition_Variable;

export namespace stdm
{
    // Classes
    using std::condition_variable;
    using std::condition_variable_any;
    using std::cv_status;

    // Functions
    using std::notify_all_at_thread_exit;
}
