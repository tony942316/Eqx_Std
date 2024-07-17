export module Foo.Mod;

import Eqx.Stdm;

export namespace foo
{
    inline void sleep() noexcept
    {
        stdm::cout << "Sleeping In Module..." << stdm::endl;
        stdm::this_thread::sleep_for(1'000ms);
        stdm::cout << "Module Awake!" << stdm::endl;
    }

    inline void equal() noexcept
    {
        stdm::cout << "Hello Module == Hello Module: "sv
            << stdm::ranges::equal_to{}("Hello Module"s, "Hello Module"s)
            << stdm::endl;
    }
}
