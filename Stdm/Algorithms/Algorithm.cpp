module;

#include <algorithm>

export module Stdm.Algorithms.Algorithm;

export namespace stdm
{
    // Comparision Operations
    using std::lexicographical_compare_three_way;
}

export namespace stdm::ranges
{
    // Return Types
    using std::ranges::in_fun_result;
    using std::ranges::in_in_result;
    using std::ranges::in_out_result;
    using std::ranges::in_in_out_result;
    using std::ranges::in_out_out_result;
    using std::ranges::min_max_result;
    using std::ranges::in_found_result;

    // Non-Modifying Sequence Operations
    using std::ranges::all_of;
    using std::ranges::any_of;
    using std::ranges::none_of;
    using std::ranges::for_each;
    using std::ranges::for_each_n;
    using std::ranges::count;
    using std::ranges::count_if;
    using std::ranges::mismatch;
    using std::ranges::find;
    using std::ranges::find_if;
    using std::ranges::find_if_not;
    using std::ranges::find_end;
    using std::ranges::find_first_of;
    using std::ranges::adjacent_find;
    using std::ranges::search;
    using std::ranges::search_n;

    // Modifying Sequence Operations
    using std::ranges::copy;
    using std::ranges::copy_if;
    using std::ranges::copy_n;
    using std::ranges::copy_backward;
    using std::ranges::move;
    using std::ranges::move_backward;
    using std::ranges::fill;
    using std::ranges::fill_n;
    using std::ranges::transform;
    using std::ranges::generate;
    using std::ranges::generate_n;
    using std::ranges::remove;
    using std::ranges::remove_if;
    using std::ranges::remove_copy;
    using std::ranges::remove_copy_if;
    using std::ranges::replace;
    using std::ranges::replace_if;
    using std::ranges::replace_copy;
    using std::ranges::replace_copy_if;
    using std::ranges::swap_ranges;
    using std::ranges::reverse;
    using std::ranges::reverse_copy;
    using std::ranges::rotate;
    using std::ranges::rotate_copy;
    using std::ranges::sample;
    using std::ranges::shuffle;
    using std::ranges::unique;
    using std::ranges::unique_copy;

    // Partitioning Operations
    using std::ranges::is_partitioned;
    using std::ranges::partition;
    using std::ranges::partition_copy;
    using std::ranges::stable_partition;
    using std::ranges::partition_point;

    // Sorting Operations
    using std::ranges::is_sorted;
    using std::ranges::is_sorted_until;
    using std::ranges::sort;
    using std::ranges::partial_sort;
    using std::ranges::partial_sort_copy;
    using std::ranges::stable_sort;
    using std::ranges::nth_element;

    // Binary Search Operations (On Sorted Ranges)
    using std::ranges::lower_bound;
    using std::ranges::upper_bound;
    using std::ranges::binary_search;
    using std::ranges::equal_range;

    // Other Operations On Sorted Ranges
    using std::ranges::merge;
    using std::ranges::inplace_merge;

    // Set Operations (On Sorted Ranges)
    using std::ranges::includes;
    using std::ranges::set_difference;
    using std::ranges::set_intersection;
    using std::ranges::set_symmetric_difference;
    using std::ranges::set_union;

    // Heap Operations
    using std::ranges::is_heap;
    using std::ranges::is_heap_until;
    using std::ranges::make_heap;
    using std::ranges::push_heap;
    using std::ranges::pop_heap;
    using std::ranges::sort_heap;

    // Minimum/Maximum Operations
    using std::ranges::max;
    using std::ranges::max_element;
    using std::ranges::min;
    using std::ranges::min_element;
    using std::ranges::minmax;
    using std::ranges::minmax_element;
    using std::ranges::clamp;

    // Comparision Operations
    using std::ranges::equal;
    using std::ranges::lexicographical_compare;

    // Permutation Operations
    using std::ranges::is_permutation;
    using std::ranges::next_permutation;
    using std::ranges::prev_permutation;
}
