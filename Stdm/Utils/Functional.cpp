module;

#include <functional>

export module Stdm.Utils.Functional;

export namespace stdm
{
    // Wrappers
    using std::function;
    using std::mem_fn;
    using std::reference_wrapper;
    using std::unwrap_reference;
    using std::unwrap_ref_decay;

    // Helper Classes
    using std::bad_function_call;
    using std::is_bind_expression;
    using std::is_placeholder;

    // Arithmetic Operations
    using std::plus;
    using std::minus;
    using std::multiplies;
    using std::divides;
    using std::modulus;
    using std::negate;

    // Concept-Constrained Comparisons
    using std::compare_three_way;

    // Logical Operations
    using std::logical_and;
    using std::logical_or;
    using std::logical_not;

    // Bitwise Operations
    using std::bit_and;
    using std::bit_or;
    using std::bit_xor;
    using std::bit_not;

    // Negators
    using std::not_fn;

    // Identites
    using std::identity;

    // Searchers
    using std::default_searcher;
    using std::boyer_moore_searcher;
    using std::boyer_moore_horspool_searcher;

    // Hashing
    using std::hash;

    // Functions
    using std::bind_front;
    using std::bind;
    using std::ref;
    using std::cref;
    using std::invoke;
}

export namespace stdm::ranges
{
    // Concept-Constrained Comparisons
    using std::ranges::equal_to;
    using std::ranges::not_equal_to;
    using std::ranges::greater;
    using std::ranges::less;
    using std::ranges::greater_equal;
    using std::ranges::less_equal;
}

export namespace stdm::placeholders
{
    // Constants
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    using std::placeholders::_4;
    using std::placeholders::_5;
    using std::placeholders::_6;
    using std::placeholders::_7;
    using std::placeholders::_8;
    using std::placeholders::_9;
    using std::placeholders::_10;
}
