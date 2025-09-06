// Module.cpp

export module Eqx.Std.Tests.Module;

import <Eqx/std.hpp>;

using namespace std::literals;

export namespace eqx::std::tests::module
{
    inline void print() noexcept
    {
        ::std::format_to(::std::ostreambuf_iterator<char>(::std::cout),
            "Hello Module!\n"sv);
    }

    [[nodiscard]] constexpr int end() noexcept
    {
        return EXIT_SUCCESS;
    }
}
