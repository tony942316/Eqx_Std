module;

#include <span>

export module Eqx.Stdm.Containers.Span;

export namespace stdm
{
    // Classes
    using std::span;

    // Constants
    using std::dynamic_extent;

    // Functions
    using std::as_bytes;
    using std::as_writable_bytes;

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
