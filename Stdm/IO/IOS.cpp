module;

#include <ios>

export module Eqx.Stdm.IO.IOS;

export namespace stdm
{
    // Classes
    using std::ios_base;
    using std::basic_ios;
    using std::ios;
    using std::wios;
    using std::fpos;
    using std::io_errc;
    using std::is_error_code_enum;
    using std::streamoff;
    using std::streamsize;

    // Functions
    using std::iostream_category;
    using std::make_error_code;
    using std::make_error_condition;
    using std::boolalpha;
    using std::noboolalpha;
    using std::showbase;
    using std::noshowbase;
    using std::showpoint;
    using std::noshowpoint;
    using std::showpos;
    using std::noshowpos;
    using std::skipws;
    using std::noskipws;
    using std::uppercase;
    using std::nouppercase;
    using std::unitbuf;
    using std::nounitbuf;
    using std::internal;
    using std::left;
    using std::right;
    using std::dec;
    using std::hex;
    using std::oct;
    using std::fixed;
    using std::scientific;
    using std::hexfloat;
    using std::defaultfloat;

}
