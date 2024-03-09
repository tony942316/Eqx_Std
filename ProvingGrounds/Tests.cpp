export module Tests;

import TestArray;

export namespace Test
{
    void All() noexcept
    {
        Test::Array::Run();
    }
}
