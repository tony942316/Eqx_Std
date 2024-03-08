module;

#include <array>

export module Stdm.Containers.Array;

export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    using std::array;
    using std::tuple_size;
    using std::tuple_element;
    using std::swap;
    using std::to_array;
    using std::get;
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
