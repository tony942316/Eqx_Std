module;

#include <thread>

export module Eqx.Stdm.Concurrency.Thread;

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

#ifndef _MSC_VER
    using std::this_thread::sleep_for;
    using std::this_thread::sleep_until;
#endif // _MSC_VER

#ifdef _MSC_VER
    template <class _Rep, class _Period>
    _NODISCARD auto _To_absolute_time(const std::chrono::duration<_Rep, _Period>& _Rel_time) noexcept {
    constexpr auto _Zero                 = std::chrono::duration<_Rep, _Period>::zero();
    const auto _Now                      = std::chrono::steady_clock::now();
    decltype(_Now + _Rel_time) _Abs_time = _Now; // return common type
    if (_Rel_time > _Zero) {
        constexpr auto _Forever = (std::chrono::steady_clock::time_point::max)();
        if (_Abs_time < _Forever - _Rel_time) {
            _Abs_time += _Rel_time;
        } else {
            _Abs_time = _Forever;
        }
    }
    return _Abs_time;
}
    

    template <class _Clock, class _Duration>
    void sleep_until(const std::chrono::time_point<_Clock, _Duration>& _Abs_time) 
    {
#if _HAS_CXX20
        static_assert(std::chrono::is_clock_v<_Clock>, "Clock type required");
#endif // _HAS_CXX20
        for (;;) {
            const auto _Now = _Clock::now();
            if (_Abs_time <= _Now) {
                return;
            }

            // _Clamp must be less than 2^32 - 1 (INFINITE) milliseconds, but is otherwise arbitrary.
            constexpr std::chrono::milliseconds _Clamp{std::chrono::hours{24}};

            const auto _Rel = _Abs_time - _Now;
            if (_Rel >= _Clamp) {
                _Thrd_sleep_for(static_cast<unsigned long>(_Clamp.count()));
            } else {
                const auto _Rel_ms = std::chrono::ceil<std::chrono::milliseconds>(_Rel);
                _Thrd_sleep_for(static_cast<unsigned long>(_Rel_ms.count()));
            }
        }
    }

    template <class _Rep, class _Period>
    void sleep_for(const std::chrono::duration<_Rep, _Period>& _Rel_time) {
        sleep_until(_To_absolute_time(_Rel_time));
    }
#endif // _MSC_VER
}
