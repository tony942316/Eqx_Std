module;

#include <istream>

export module Eqx.Stdm.IO.IStream;

// Operators
using std::operator>>;

export namespace stdm
{
    // Classes
    using std::basic_istream;
    using std::istream;
    using std::wistream;
    using std::basic_iostream;
    using std::iostream;
    using std::wiostream;

    // Manipulators
    using std::ws;
}
