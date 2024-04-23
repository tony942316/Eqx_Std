module;

#include <iomanip>

export module Eqx.Stdm.IO.IOManip;

export using std::operator<<;
export using std::operator>>;

export namespace stdm
{
    // Functions
    using std::resetiosflags;
    using std::setiosflags;
    using std::setbase;
    using std::setfill;
    using std::setprecision;
    using std::setw;
    using std::get_money;
    using std::put_money;
    using std::get_time;
    using std::put_time;
    using std::quoted;
}
