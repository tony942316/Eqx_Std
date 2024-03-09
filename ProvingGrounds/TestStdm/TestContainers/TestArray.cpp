export module TestArray;

import Stdm.Containers.Array;

export namespace Test::Array
{
    consteval void ImplicitMembers() noexcept
    {
        constexpr auto arr1 = stdm::array<int, 3>();
        static_assert(arr1[0] == 0 && arr1[1] == 0 && arr1[2] == 0);

        constexpr auto arr2 = stdm::array<int, 3>({ 1, 2, 3 });
        static_assert(arr2[0] == 1 && arr2[1] == 2 && arr2[2] == 3);

        constexpr auto helper = []() consteval
            {
                auto arr1 = stdm::array<int, 3>({ 3, 2, 1 });
                auto arr2 = stdm::array<int, 3>();
                arr2 = arr1;
                return arr2;
            };
        constexpr auto arr3 = helper();
        static_assert(arr3[0] == 3 && arr3[1] == 2 && arr3[2] == 1);
    }

    consteval void ElementAccess() noexcept
    {
        constexpr auto arr = stdm::array<int, 3>({ 1, 2, 3 });

        static_assert(arr.at(0) == 1 && arr.at(1) == 2 && arr.at(2) == 3);
        static_assert(arr.front() == 1);
        static_assert(arr.back() == 3);
        static_assert(arr.data() == &arr.at(0) && *(arr.data() + 1) == 2);

        static_assert(stdm::data(arr) == arr.data());
    }

    consteval void Iterators() noexcept
    {
        constexpr auto arr = stdm::array<int, 3>({ 1, 2, 3 });

        static_assert(*arr.begin() == *arr.cbegin());
        static_assert(*(arr.end() - 1) == *(arr.cend() - 1));
        static_assert(*arr.rbegin() == *arr.crbegin());
        static_assert(*(arr.rend() - 1) == *(arr.crend() - 1));

        static_assert(*arr.rbegin() == *(arr.end() - 1));
        static_assert(*arr.begin() == *(arr.rend() - 1));
        static_assert(*arr.crbegin() == *(arr.cend() - 1));
        static_assert(*arr.cbegin() == *(arr.crend() - 1));

        static_assert(stdm::begin(arr) == arr.begin());
        static_assert(stdm::cbegin(arr) == arr.cbegin());
        static_assert(stdm::end(arr) == arr.end());
        static_assert(stdm::cend(arr) == arr.cend());
        static_assert(stdm::rbegin(arr) == arr.rbegin());
        static_assert(stdm::crbegin(arr) == arr.crbegin());
        static_assert(stdm::rend(arr) == arr.rend());
        static_assert(stdm::crend(arr) == arr.crend());
    }

    consteval void Capacity() noexcept
    {
        constexpr auto arr = stdm::array<int, 3>({ 1, 2, 3 });
        constexpr auto arrE = stdm::array<int, 0>();

        static_assert(!arr.empty());
        static_assert(arrE.empty());

        static_assert(arr.size() == 3);

        static_assert(arr.max_size() == arr.size());
        static_assert(arrE.max_size() == arrE.size());

        static_assert(stdm::empty(arr) == arr.empty());
        static_assert(stdm::size(arr) == arr.size());
        static_assert(stdm::ssize(arr) == arr.size());
    }

    consteval void Operations() noexcept
    {
        constexpr auto helper = []() consteval
            {
                auto arr1 = stdm::array<int, 3>();
                auto arr2 = stdm::array<int, 3>();
                arr1.fill(1);
                arr2.fill(2);
                arr1.swap(arr2);
                return arr1;
            };
        static_assert(helper() == stdm::array<int, 3>({ 2, 2, 2 }));
    }

    consteval void NonMembers() noexcept
    {
        constexpr auto arr1 = stdm::array<int, 3>({ 1, 2, 3 });
        constexpr auto arr2 = stdm::array<int, 3>({ 3, 2, 1 });
        constexpr auto arr3 = arr1;

        static_assert(arr1 == arr3);
        static_assert(arr1 != arr2);

        static_assert(arr1 < arr2);
        static_assert(arr1 <= arr3);
        static_assert(arr2 > arr1);
        static_assert(arr1 >= arr3);

        static_assert(stdm::get<0>(arr1) == 1 && stdm::get<1>(arr1) == 2 &&
            stdm::get<2>(arr1) == 3);

        constexpr auto helper = []() consteval
            {
                auto arr1 = stdm::array<int, 3>({ 1, 2, 3 });
                auto arr2 = stdm::array<int, 3>({ 5, 6, 7 });
                stdm::swap(arr1, arr2);
                return arr1;
            };
        constexpr auto arr4 = helper();
        static_assert(arr4 == stdm::array<int, 3>({ 5, 6, 7 }));

        constexpr int arr5[] = { 4, 5, 6 };
        static_assert(stdm::to_array(arr5) == stdm::array<int, 3>({ 4, 5, 6 }));
    }

    consteval void Helpers() noexcept
    {
        constexpr auto arr = stdm::array<int, 3>({ 1, 2, 3 });
        static_assert(stdm::tuple_size<stdm::array<int, 3>>() == 3);
        using type = stdm::tuple_element<0, stdm::array<int, 3>>::type;
    }

    consteval void Run() noexcept
    {
        ImplicitMembers();
        ElementAccess();
        Iterators();
        Capacity();
        Operations();
        NonMembers();
        Helpers();
    }
}
