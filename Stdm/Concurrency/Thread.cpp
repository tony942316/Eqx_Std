module;

#include <thread>

export module Stdm.Concurrency.Thread;

export using std::operator==;
export using std::operator<=>;
export using std::operator<<;

export namespace stdm
{
    // Classes
    using std::thread;
    using std::jthread;
    using std::hash;

    // Functions
    using std::swap;
}

export namespace stdm::this_thread
{
    using std::this_thread::yield;
    using std::this_thread::get_id;
    using std::this_thread::sleep_for;
    using std::this_thread::sleep_until;
}
