module;

#include <utility>

export module Stdm.Utils.Utility;

// Operators
export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    // Functions
    using std::swap;
    using std::exchange;
    using std::forward;
    using std::move;
    using std::move_if_noexcept;
    using std::as_const;
    using std::declval;
    using std::cmp_equal;
    using std::cmp_not_equal;
    using std::cmp_less;
    using std::cmp_greater;
    using std::cmp_less_equal;
    using std::cmp_greater_equal;
    using std::in_range;
    using std::make_pair;
    using std::get;

    // Classes
    using std::pair;
    using std::tuple_size;
    using std::tuple_element;
    using std::integer_sequence;

    // Tags
    using std::piecewise_construct;
    using std::piecewise_construct_t;
    using std::in_place;
    using std::in_place_type;
    using std::in_place_index;
    using std::in_place_t;
    using std::in_place_type_t;
    using std::in_place_index_t;
}
