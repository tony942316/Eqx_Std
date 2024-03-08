module;

#include <deque>

export module Stdm.Containers.Deque;

export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    using std::deque;
    using std::swap;
    using std::erase;
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
