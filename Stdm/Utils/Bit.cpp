module;

#include <bit>

export module Stdm.Utils.Bit;

export namespace stdm
{
    // Types
    using std::endian;

    // Functions
    using std::bit_cast;
    using std::has_single_bit;
    using std::bit_ceil;
    using std::bit_floor;
    using std::bit_width;
    using std::rotl;
    using std::rotr;
    using std::countl_zero;
    using std::countl_one;
    using std::countr_zero;
    using std::countr_one;
    using std::popcount;
}
