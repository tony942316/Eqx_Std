module;

#include <array>

export module Eqx.Stdm.Containers.Array;

// Operators
export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    // Classes
    using std::array;
    using std::tuple_size;
    using std::tuple_element;

    // Functions
    using std::swap;
    using std::to_array;
    using std::get;

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
