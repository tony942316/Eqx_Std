module;

#include <fstream>

export module Stdm.IO.FStream;

export namespace stdm
{
    // Classes
    using std::basic_filebuf;
    using std::basic_ifstream;
    using std::basic_ofstream;
    using std::basic_fstream;
    using std::filebuf;
    using std::wfilebuf;
    using std::ifstream;
    using std::wifstream;
    using std::ofstream;
    using std::wofstream;
    using std::fstream;
    using std::wfstream;

    // Functions
    using std::swap;
}
