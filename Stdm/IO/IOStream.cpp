module;

#include <iostream>

export module Stdm.IO.IOStream;

export using std::operator<<;
export using std::operator>>;

export namespace stdm
{
    using std::cout;
    using std::cerr;
    using std::clog;
    using std::cin;
    using std::endl;
    using std::flush;
}

