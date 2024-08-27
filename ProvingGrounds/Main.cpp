import <Eqx/std.hpp>;
import <Eqx/os.hpp>;

import Eqx.Std.Tests;

int main()
{
    std::cout << "Start:\n\n"sv;
    tests::all();
    std::cout << "\nEnd: "sv;
    std::cin.get();
    return EXIT_SUCCESS;
}
