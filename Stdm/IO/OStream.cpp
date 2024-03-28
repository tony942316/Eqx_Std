module;

#include <ostream>

export module Stdm.IO.OStream;

// Operators
using std::operator<<;

export namespace stdm
{
    // Classes
    using std::basic_ostream;
    using std::ostream;
    using std::wostream;

    // Manipulators
    using std::endl;
    using std::ends;
    using std::flush;
    using std::emit_on_flush;
    using std::noemit_on_flush;
    using std::flush_emit;
}
