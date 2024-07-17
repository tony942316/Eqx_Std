export module Foo.Mod;

import Eqx.Stdm;

export namespace foo
{
    inline void func() noexcept
    {
        stdm::cout << "Sleeping In Module..." << stdm::endl;
        stdm::this_thread::sleep_for(1'000ms);
        stdm::cout << "Module Awake!" << stdm::endl;
    }
}
