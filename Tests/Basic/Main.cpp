// Main.cpp

import <Eqx/std.hpp>;

using namespace std::literals;

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    std::format_to(std::ostreambuf_iterator<char>(std::cout), "Start\n\n"sv);



    std::format_to(std::ostreambuf_iterator<char>(std::cout), "\nEnd\n"sv);
    return EXIT_SUCCESS;
}
