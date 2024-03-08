module;

#include <map>

export module Stdm.Containers.Map;

export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    using std::map;
    using std::multimap;
    using std::swap;
    using std::erase_if;
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
