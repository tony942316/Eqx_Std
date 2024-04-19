module;

#include <compare>

export module Eqx.Stdm.Utils.Compare;

export namespace stdm
{
    // Concepts
    using std::three_way_comparable;
    using std::three_way_comparable_with;

    // Classes
    using std::partial_ordering;
    using std::weak_ordering;
    using std::strong_ordering;
    using std::common_comparison_category;
    using std::compare_three_way_result;
    using std::compare_three_way;

    // Customization Point Objects
    using std::strong_order;
    using std::weak_order;
    using std::partial_order;
    using std::compare_strong_order_fallback;
    using std::compare_weak_order_fallback;
    using std::compare_partial_order_fallback;

    // Functions
    using std::is_eq;
    using std::is_neq;
    using std::is_lt;
    using std::is_lteq;
    using std::is_gt;
    using std::is_gteq;
}
