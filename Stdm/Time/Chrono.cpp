module;

#include <chrono>

export module Eqx.Stdm.Time.Chrono;

// Operators
export using std::chrono::operator+;
export using std::chrono::operator-;
export using std::chrono::operator*;
export using std::chrono::operator/;
export using std::chrono::operator%;

export using std::chrono::operator==;
export using std::chrono::operator<;
export using std::chrono::operator<=;
export using std::chrono::operator>;
export using std::chrono::operator>=;
export using std::chrono::operator<=>;

export using std::chrono::operator<<;

#ifdef __GLIBCXX__
export template <typename CharT, typename Traits, typename Rep, typename Period>
std::basic_stringstream<CharT, Traits>
    operator<< (const std::basic_stringstream<CharT, Traits>& sos,
    const std::chrono::duration<Rep, Period>& dur) noexcept
{
    //NOLINTBEGIN(cppcoreguidelines-pro-type-const-cast)
    return std::move(const_cast<std::basic_stringstream<CharT, Traits>&>(sos))
        << dur;
    //NOLINTEND(cppcoreguidelines-pro-type-const-cast)
}
#endif // __GLIBCXX__

export using std::chrono::operator""h;
export using std::chrono::operator""min;
export using std::chrono::operator""s;
export using std::chrono::operator""ms;
export using std::chrono::operator""us;
export using std::chrono::operator""ns;
export using std::chrono::operator""d;
export using std::chrono::operator""y;

export namespace stdm::chrono
{
    // Duration
    using std::chrono::duration;
    using std::chrono::treat_as_floating_point;
    using std::chrono::duration_values;

    // Convenience Duration Typedefs
    using std::chrono::nanoseconds;
    using std::chrono::microseconds;
    using std::chrono::milliseconds;
    using std::chrono::seconds;
    using std::chrono::minutes;
    using std::chrono::hours;
    using std::chrono::days;
    using std::chrono::weeks;
    using std::chrono::months;
    using std::chrono::years;

    // Time Point
    using std::chrono::time_point;
    // using std::chrono::clock_time_conversion;

    // Clocks
    using std::chrono::is_clock;
    using std::chrono::is_clock_v;
    using std::chrono::system_clock;
    using std::chrono::steady_clock;
    using std::chrono::high_resolution_clock;
    using std::chrono::utc_clock;
    using std::chrono::tai_clock;
    using std::chrono::gps_clock;
    using std::chrono::file_clock;
    using std::chrono::local_t;

    // Calendar
    using std::chrono::last_spec;
    using std::chrono::day;
    using std::chrono::month;
    using std::chrono::year;
    using std::chrono::weekday;
    using std::chrono::weekday_indexed;
    using std::chrono::weekday_last;
    using std::chrono::month_day;
    using std::chrono::month_day_last;
    using std::chrono::month_weekday;
    using std::chrono::month_weekday_last;
    using std::chrono::year_month;
    using std::chrono::year_month_day;
    using std::chrono::year_month_day_last;
    using std::chrono::year_month_weekday;
    using std::chrono::year_month_weekday_last;

    // Time Of Day
    using std::chrono::hh_mm_ss;

    // Time Zone
#ifdef _WIN32
    using std::chrono::tzdb;
    using std::chrono::tzdb_list;
    using std::chrono::time_zone;
    using std::chrono::sys_info;
    using std::chrono::local_info;
    using std::chrono::choose;
    using std::chrono::zoned_traits;
    using std::chrono::zoned_time;
    using std::chrono::time_zone_link;
    using std::chrono::nonexistent_local_time;
    using std::chrono::ambiguous_local_time;
#endif // _WIN32

    // Leap Second
#ifdef _WIN32
    using std::chrono::leap_second;
#endif // _WIN32
    using std::chrono::leap_second_info;

    // Specializations
    using std::common_type;
#ifdef _WIN32
    using std::formatter;
#endif // _WIN32
    using std::hash;

    // Duration
    using std::chrono::duration_cast;
    using std::chrono::floor;
    using std::chrono::ceil;
    using std::chrono::round;
    using std::chrono::abs;

    // Time Point
    using std::chrono::time_point_cast;
#ifdef _WIN32
    using std::chrono::from_stream;
    using std::chrono::clock_cast;
#endif // _WIN32

    // Time Of Day
    using std::chrono::is_am;
    using std::chrono::is_pm;
    using std::chrono::make12;
    using std::chrono::make24;

    // Time Zone
#ifdef _WIN32
    using std::chrono::get_tzdb;
    using std::chrono::get_tzdb_list;
    using std::chrono::reload_tzdb;
    using std::chrono::remote_version;
    using std::chrono::locate_zone;
#endif // _WIN32

    // Leap Second
#ifdef _WIN32
    using std::chrono::get_leap_second_info;
#endif // _WIN32

    // I/O
#ifdef _WIN32
    using std::chrono::from_stream;
    using std::chrono::parse;
#endif // _WIN32
}
