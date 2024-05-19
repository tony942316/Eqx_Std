module;

#include <vector>

#ifdef __GLIBCXX__
#include <string>
#include <algorithm>
#endif // __GLIBCXX__

export module Eqx.Stdm.Containers.Vector;

// Operators
export using std::operator==;
export using std::operator<=>;

#ifdef __GLIBCXX__
export using __gnu_cxx::operator==;

export constexpr bool operator==(const std::vector<std::string>& lhs,
    const std::vector<std::string>& rhs) noexcept
{
    return std::ranges::equal(lhs, rhs);
}
#endif // __GLIBCXX__

export namespace stdm
{
    // Classes
    using std::vector;

    // Functions
    using std::swap;
    using std::erase;
    using std::erase_if;

    // Ranges Access
    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;
}
