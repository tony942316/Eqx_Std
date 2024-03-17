module;

#include <iterator>

export module Stdm.Iterator.Iterator;

// Operators
export using std::operator==;
export using std::operator!=;
export using std::operator<;
export using std::operator<=;
export using std::operator>;
export using std::operator>=;
export using std::operator<=>;
export using std::operator+;
export using std::operator-;

export namespace stdm
{
    // Iterator Concepts
    using std::indirectly_readable;
    using std::indirectly_writable;
    using std::weakly_incrementable;
    using std::incrementable;
    using std::input_or_output_iterator;
    using std::sentinel_for;
    using std::sized_sentinel_for;
    using std::input_iterator;
    using std::output_iterator;
    using std::forward_iterator;
    using std::bidirectional_iterator;
    using std::random_access_iterator;
    using std::contiguous_iterator;

    // Indirect Callable Concepts
    using std::indirectly_unary_invocable;
    using std::indirectly_regular_unary_invocable;
    using std::indirect_unary_predicate;
    using std::indirect_binary_predicate;
    using std::indirect_equivalence_relation;
    using std::indirect_strict_weak_order;

    // Common Algorithm Requirements
    using std::indirectly_movable;
    using std::indirectly_movable_storable;
    using std::indirectly_copyable;
    using std::indirectly_copyable_storable;
    using std::indirectly_swappable;
    using std::indirectly_comparable;
    using std::permutable;
    using std::mergeable;
    using std::sortable;

    // Algorithm Utilities
    using std::indirect_result_t;
    using std::projected;

    // Associated Types
    using std::incrementable_traits;
    using std::indirectly_readable_traits;
    using std::iter_value_t;
    using std::iter_reference_t;
    using std::iter_difference_t;
    using std::iter_rvalue_reference_t;
    using std::iter_common_reference_t;

    // Primitives
    using std::iterator_traits;
    using std::input_iterator_tag;
    using std::output_iterator;
    using std::forward_iterator_tag;
    using std::bidirectional_iterator;
    using std::random_access_iterator;
    using std::contiguous_iterator_tag;

    // Adaptors
    using std::reverse_iterator;
    using std::move_iterator;
    using std::move_sentinel;
    using std::common_iterator;
    using std::default_sentinel_t;
    using std::counted_iterator;
    using std::unreachable_sentinel_t;
    using std::back_insert_iterator;
    using std::front_insert_iterator;
    using std::insert_iterator;

    // Stream Iterator
    using std::istream_iterator;
    using std::ostream_iterator;
    using std::istreambuf_iterator;
    using std::ostreambuf_iterator;

    // Constants
    using std::unreachable_sentinel;
    using std::default_sentinel;

    // Adaptors
    using std::make_reverse_iterator;
    using std::make_move_iterator;
    using std::front_inserter;
    using std::back_inserter;
    using std::inserter;

    // Range Access
    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;
}

export namespace stdm::ranges
{
    // Customization Point Objects
    using std::ranges::iter_move;
    using std::ranges::iter_swap;

    // Operations
    using std::ranges::advance;
    using std::ranges::distance;
    using std::ranges::next;
    using std::ranges::prev;
}
