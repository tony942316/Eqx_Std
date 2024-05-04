module;

#include <ranges>

export module Eqx.Stdm.Ranges.Ranges;

#ifdef _MSVC_STL_UPDATE
export using std::ranges::_Pipe::operator|;
#endif // _MSVC_STL_UPDATE

#ifdef __GLIBCXX__
export using std::views::__adaptor::operator|;
#endif // __GLIBCXX__

export namespace stdm::ranges
{
    // Range Concepts
    using std::ranges::range;
    using std::ranges::borrowed_range;
    using std::ranges::sized_range;
    using std::ranges::view;
    using std::ranges::input_range;
    using std::ranges::output_range;
    using std::ranges::forward_range;
    using std::ranges::bidirectional_range;
    using std::ranges::random_access_range;
    using std::ranges::contiguous_range;
    using std::ranges::common_range;
    using std::ranges::viewable_range;

    // Range Primitives
    using std::ranges::iterator_t;
    using std::ranges::sentinel_t;
    using std::ranges::range_difference_t;
    using std::ranges::range_size_t;
    using std::ranges::range_value_t;
    using std::ranges::range_reference_t;
    using std::ranges::range_rvalue_reference_t;

    // Views
    using std::ranges::view_interface;
    using std::ranges::subrange;

    // Dangling Iterator Handling
    using std::ranges::dangling;
    using std::ranges::borrowed_iterator_t;
    using std::ranges::borrowed_subrange_t;

    // Adaptors
    using std::ranges::ref_view;
    using std::ranges::owning_view;

    // Range Access
    using std::ranges::begin;
    using std::ranges::end;
    using std::ranges::cbegin;
    using std::ranges::cend;
    using std::ranges::rbegin;
    using std::ranges::rend;
    using std::ranges::crbegin;
    using std::ranges::crend;
    using std::ranges::size;
    using std::ranges::ssize;
    using std::ranges::empty;
    using std::ranges::data;
    using std::ranges::cdata;

    // Enumerations
    using std::ranges::subrange_kind;
}


export namespace stdm::views
{
    // Factories
    using std::views::empty;
    using std::views::single;
    using std::views::iota;
    using std::views::istream;

    // Adaptors
    using std::views::all_t;
    using std::views::all;
    using std::views::filter;
    using std::views::transform;
    using std::views::take;
    using std::views::take_while;
    using std::views::drop;
    using std::views::drop_while;
    using std::views::join;
    using std::views::lazy_split;
    using std::views::split;
    using std::views::counted;
    using std::views::common;
    using std::views::reverse;
    using std::views::elements;
    using std::views::keys;
    using std::views::values;
}

export namespace stdm
{
    // Helpers
    using std::tuple_size;
    using std::tuple_element;
    using std::get;
}
