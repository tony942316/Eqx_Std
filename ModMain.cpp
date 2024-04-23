import Eqx.Stdm;

void basicTest()
{
    auto vec = stdm::vector<int>{ 1, 2, 3 };
    stdm::cout << "Vec: ";
    stdm::ranges::for_each(vec, [](int ele)
        { stdm::cout << ele << ' '; });
    stdm::cout << stdm::endl;
}

void precisionTest()
{
    constexpr auto pi = stdm::numbers::pi_v<long double>; // NOLINT
    stdm::cout << pi << stdm::endl;
    stdm::cout << stdm::setprecision(20); // NOLINT
    stdm::cout << pi << stdm::endl;
}

void allTests()
{
    basicTest();
    precisionTest();

    stdm::cout << "End: ";
    stdm::cin.get();
}

int main()
{
    allTests();
    return 0;
}
