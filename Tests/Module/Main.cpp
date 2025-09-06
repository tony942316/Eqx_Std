// Main.cpp

import Eqx.Std.Tests.Module;

import <Eqx/std.hpp>;

using namespace std::literals;

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    std::format_to(std::ostreambuf_iterator<char>(std::cout), "Start\n\n"sv);

    std::invoke(eqx::std::tests::module::print);

    std::format_to(std::ostreambuf_iterator<char>(std::cout), "\nEnd\n"sv);
    return eqx::std::tests::module::end();
}
