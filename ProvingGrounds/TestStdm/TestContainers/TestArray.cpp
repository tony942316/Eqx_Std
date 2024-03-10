export module TestArray;

import Stdm.Containers.Array;

namespace Test::Array::CTT
{
    namespace Helpers
    {
        constexpr auto CopyAssigned = []() consteval
            {
                auto arr1 = stdm::array<int, 3>({ 3, 2, 1 });
                auto arr2 = stdm::array<int, 3>();
                arr2 = arr1;
                return arr2;
            };
        constexpr auto FillSwap = []() consteval
            {
                auto arr1 = stdm::array<int, 3>();
                auto arr2 = stdm::array<int, 3>();
                arr1.fill(1);
                arr2.fill(2);
                arr1.swap(arr2);
                return arr1;
            };
        constexpr auto NMSwap = []() consteval
            {
                auto arr1 = stdm::array<int, 3>({ 1, 2, 3 });
                auto arr2 = stdm::array<int, 3>({ 5, 6, 7 });
                stdm::swap(arr1, arr2);
                return arr1;
            };
    }

    namespace Arr
    {
        constexpr auto NoElements = stdm::array<int, 0>();
        constexpr auto Empty = stdm::array<int, 3>();
        constexpr auto Basic = stdm::array<int, 3>({ 1, 2, 3 });
        constexpr auto Reverse = stdm::array<int, 3>({ 3, 2, 1 });
        constexpr auto CA = Helpers::CopyAssigned();
        constexpr auto FS = Helpers::FillSwap();
        constexpr auto NMS = Helpers::NMSwap();
        constexpr int CStyle[] = { 5, 6, 7 };
    }


    // Implicit Members
    static_assert(Arr::Empty[0] == 0 && Arr::Empty[1] == 0 &&
        Arr::Empty[2] == 0);
    static_assert(Arr::Basic[0] == 1 && Arr::Basic[1] == 2 &&
        Arr::Basic[2] == 3);
    static_assert(Arr::CA[0] == 3 && Arr::CA[1] == 2 && Arr::CA[2] == 1);

    // Element Access
    static_assert(Arr::Basic.at(0) == 1 && Arr::Basic.at(1) == 2 &&
        Arr::Basic.at(2) == 3);
    static_assert(Arr::Basic.front() == 1);
    static_assert(Arr::Basic.back() == 3);
    static_assert(Arr::Basic.data() == &Arr::Basic.at(0) &&
        *(Arr::Basic.data() + 1) == 2);

    static_assert(stdm::data(Arr::Basic) == Arr::Basic.data());

    // Iterators
    static_assert(*Arr::Basic.begin() == *Arr::Basic.cbegin());
    static_assert(*(Arr::Basic.end() - 1) == *(Arr::Basic.cend() - 1));
    static_assert(*Arr::Basic.rbegin() == *Arr::Basic.crbegin());
    static_assert(*(Arr::Basic.rend() - 1) == *(Arr::Basic.crend() - 1));

    static_assert(*Arr::Basic.rbegin() == *(Arr::Basic.end() - 1));
    static_assert(*Arr::Basic.begin() == *(Arr::Basic.rend() - 1));
    static_assert(*Arr::Basic.crbegin() == *(Arr::Basic.cend() - 1));
    static_assert(*Arr::Basic.cbegin() == *(Arr::Basic.crend() - 1));

    static_assert(stdm::begin(Arr::Basic) == Arr::Basic.begin());
    static_assert(stdm::cbegin(Arr::Basic) == Arr::Basic.cbegin());
    static_assert(stdm::end(Arr::Basic) == Arr::Basic.end());
    static_assert(stdm::cend(Arr::Basic) == Arr::Basic.cend());
    static_assert(stdm::rbegin(Arr::Basic) == Arr::Basic.rbegin());
    static_assert(stdm::crbegin(Arr::Basic) == Arr::Basic.crbegin());
    static_assert(stdm::rend(Arr::Basic) == Arr::Basic.rend());
    static_assert(stdm::crend(Arr::Basic) == Arr::Basic.crend());

    // Capacity
    static_assert(!Arr::Basic.empty());
    static_assert(Arr::NoElements.empty());

    static_assert(Arr::Basic.size() == 3);

    static_assert(Arr::Basic.max_size() == Arr::Basic.size());
    static_assert(Arr::NoElements.max_size() == Arr::NoElements.size());

    static_assert(stdm::empty(Arr::Basic) == Arr::Basic.empty());
    static_assert(stdm::size(Arr::Basic) == Arr::Basic.size());
    static_assert(stdm::ssize(Arr::Basic) == Arr::Basic.size());

    // Operations
    static_assert(Arr::FS == stdm::array<int, 3>({ 2, 2, 2 }));

    // Non Members
    static_assert(Arr::Basic == Arr::Basic);
    static_assert(Arr::Basic != Arr::Reverse);

    static_assert(Arr::Basic < Arr::Reverse);
    static_assert(Arr::Basic <= Arr::Basic);
    static_assert(Arr::Reverse > Arr::Basic);
    static_assert(Arr::Basic >= Arr::Basic);

    static_assert(stdm::get<0>(Arr::Basic) == 1 &&
        stdm::get<1>(Arr::Basic) == 2 && stdm::get<2>(Arr::Basic) == 3);

    static_assert(Arr::NMS == stdm::array<int, 3>({ 5, 6, 7 }));
    static_assert(stdm::to_array(Arr::CStyle) == Arr::NMS);

    // Helpers
    static_assert(stdm::tuple_size<stdm::array<int, 3>>() == 3);
    using type = stdm::tuple_element<0, stdm::array<int, 3>>::type;
}

namespace Test::Array
{
    using sizetype = decltype(stdm::array<int, 0>().size());

    template <sizetype sizea, sizetype sizeb>
    [[nodiscard]] constexpr stdm::array<int, sizea + sizeb> merge(
        const stdm::array<int, sizea>& a,
        const stdm::array<int, sizeb>& b) noexcept
    {
        if constexpr (sizeb == 0)
        {
            return a;
        }
        else if constexpr (sizea == 0)
        {
            return b;
        }
        else
        {
            auto result = stdm::array<int, sizea + sizeb>();
            auto aIter = a.cbegin();
            auto bIter = b.cbegin();
            auto rIter = result.begin();

            while(aIter != a.cend() && bIter != b.cend())
            {
                if (*aIter < *bIter)
                {
                    *rIter = *aIter;
                    aIter++;
                }
                else
                {
                    *rIter = *bIter;
                    bIter++;
                }
                rIter++;
            }

            for (auto i = aIter; i != a.cend(); i++, rIter++)
            {
                *rIter = *i;
            }

            for (auto i = bIter; i != b.cend(); i++, rIter++)
            {
                *rIter = *i;
            }

            return result;
        }

    }

    static_assert(merge(CTT::Arr::Basic, CTT::Arr::Basic) ==
        stdm::array<int, 6>({ 1, 1, 2, 2, 3, 3 }));
    static_assert(merge(CTT::Arr::Basic, CTT::Arr::NoElements) ==
        CTT::Arr::Basic);
    static_assert(merge(CTT::Arr::NoElements, CTT::Arr::Basic) ==
        CTT::Arr::Basic);
    static_assert(merge(CTT::Arr::Basic, CTT::Arr::FS) ==
        stdm::array<int, 6>({ 1, 2, 2, 2, 2, 3 }));

    export void Run() noexcept
    {
    }
}
