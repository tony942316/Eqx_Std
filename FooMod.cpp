export module Foo.Mod;

import Eqx.Stdm;

using namespace std::literals;

export namespace foo
{
    inline void filePrint() noexcept
    {
        std::cout << "Print File In Module..." << std::endl;
        auto file = std::fstream{"Test.txt"};
        std::cout << file.rdbuf() << std::endl;
    }

    inline void sleep() noexcept
    {
        std::cout << "Sleeping In Module..." << std::endl;
        std::this_thread::sleep_for(1'000ms);
        std::cout << "Module Awake!" << std::endl;
    }

    inline void equal() noexcept
    {
        std::cout << "Hello Module == Hello Module: "sv
            << std::ranges::equal_to{}("Hello Module"s, "Hello Module"s)
            << std::endl;
    }
}
