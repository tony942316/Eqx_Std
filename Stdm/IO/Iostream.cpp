module;

#include <iostream>

export module Stdm.IO.Iostream;

export
{
    using std::operator<<;
    using std::operator>>;
    namespace stdm
    {
        using std::cout;
        using std::cerr;
        using std::clog;
        using std::cin;
        using std::endl;
        using std::flush;
    }
}

