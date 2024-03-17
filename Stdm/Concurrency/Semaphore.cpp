module;

#include <semaphore>

export module Stdm.Concurrency.Semaphore;

export namespace stdm
{
    // Classes
    using std::counting_semaphore;
    using std::binary_semaphore;
}
