module;

#include <unordered_map>

export module Eqx.Stdm.Containers.Unordered_Map;

// Operators
export using std::operator==;

export namespace stdm
{
    // Classes
    using std::unordered_map;
    using std::unordered_multimap;

    // Functions
    using std::swap;
    using std::erase_if;

    // Range Access
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
