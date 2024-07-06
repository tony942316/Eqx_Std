module;

#include <concepts>

export module Eqx.Stdm.Concepts.Concepts;

export namespace stdm
{
    // Core Language
    template <typename T, typename U>
    concept same_as = std::same_as<T, U>;
    template <typename T, typename U>
    concept derived_from = std::derived_from<T, U>;
    template <typename T, typename U>
    concept convertible_to = std::convertible_to<T, U>;
    template <typename T, typename U>
    concept common_reference_with = std::common_reference_with<T, U>;
    template <typename T, typename U>
    concept common_with = std::common_with<T, U>;
    template <typename T>
    concept integral = std::integral<T>;
    template <typename T>
    concept signed_integral = std::signed_integral<T>;
    template <typename T>
    concept unsigned_integral = std::unsigned_integral<T>;
    template <typename T>
    concept floating_point = std::floating_point<T>;
    template <typename T, typename U>
    concept assignable_from = std::assignable_from<T, U>;
    template <typename T>
    concept swappable = std::swappable<T>;
    template <typename T, typename U>
    concept swappable_with = std::swappable_with<T, U>;
    template <typename T>
    concept destructible = std::destructible<T>;
    template <typename T, typename... Us>
    concept constructible_from = std::constructible_from<T, Us...>;
    template <typename T>
    concept default_initializable = std::default_initializable<T>;
    template <typename T>
    concept move_constructible = std::move_constructible<T>;
    template <typename T>
    concept copy_constructible = std::copy_constructible<T>;

    // Comparison
    template <typename T>
    concept equality_comparable = std::equality_comparable<T>;
    template <typename T, typename U>
    concept equality_comparable_with = std::equality_comparable_with<T, U>;
    template <typename T>
    concept totally_ordered = std::totally_ordered<T>;
    template <typename T, typename U>
    concept totally_ordered_with = std::totally_ordered_with<T, U>;

    // Object
    template <typename T>
    concept movable = std::movable<T>;
    template <typename T>
    concept copyable = std::copyable<T>;
    template <typename T>
    concept semiregular = std::semiregular<T>;
    template <typename T>
    concept regular = std::regular<T>;

    // Callable
    template <typename T, typename... Us>
    concept invocable = std::invocable<T, Us...>;
    template <typename T, typename... Us>
    concept regular_invocable = std::regular_invocable<T, Us...>;
    template <typename T, typename U, typename V>
    concept predicate = std::predicate<T, U, V>;
    template <typename T, typename U, typename V>
    concept relation = std::relation<T, U, V>;
    template <typename T, typename U, typename V>
    concept equivalence_relation = std::equivalence_relation<T, U, V>;
    template <typename T, typename U, typename V>
    concept strict_weak_order = std::strict_weak_order<T, U, V>;

    // Customization Point Objects
    using std::ranges::swap;
}
