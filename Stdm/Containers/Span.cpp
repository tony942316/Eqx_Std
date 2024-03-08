module;

#include <span>

export module Stdm.Containers.Span;

export namespace stdm
{
    using std::span;
    using std::dynamic_extent;
    using std::as_bytes;
    using std::as_writable_bytes;
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
