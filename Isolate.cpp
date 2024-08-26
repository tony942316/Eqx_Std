#include <Eqx/std.hpp>

int main()
{
    auto data = std::vector<int>{1, 2, 3};

    auto v = data | std::views::reverse;

    std::cout << *std::ranges::begin(v) << '\n';

    return 0;
}
