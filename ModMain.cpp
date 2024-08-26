#include <Eqx/std.hpp>
#include <Eqx/os.hpp>

import Eqx.Stdm.Tests;

int main()
{
    std::cout << "Start:\n\n";
    tests::all();
    std::cout << "\nEnd: ";
    std::cin.get();
    return EXIT_SUCCESS;
}
