import Eqx.Stdm;

constexpr auto c_Seperator = "***********************"sv;

void basicTest()
{
    stdm::cout << "Basic Test ->"sv << stdm::endl;
    auto vec = stdm::vector<int>{ 1, 2, 3 };
    stdm::cout << "Vec: "sv;
    stdm::ranges::for_each(vec, [](int ele)
        { stdm::cout << ele << ' '; });
    stdm::cout << stdm::endl;
}

void iterTest()
{
    stdm::cout << "Iter Test ->"sv << stdm::endl;
    auto vec = stdm::vector<int>{ 1, 2, 3 };
    auto val = vec.begin();
    [[maybe_unused]] auto val2 = vec.end();
    [[maybe_unused]] auto vvv1 = stdm::begin(vec) == stdm::end(vec);
    [[maybe_unused]] auto vvv2 = val == (val + 1);
    [[maybe_unused]] auto vvv3 = vec.begin() == vec.end();
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {

    }
    stdm::cout << "Vector: { "sv;
    for (int ele : vec)
    {
        stdm::cout << ele << " "sv;
    }
    stdm::cout << "}"sv << stdm::endl;
    auto acc = stdm::accumulate(stdm::ranges::begin(vec),
        stdm::ranges::end(vec), int{});
    auto red = stdm::reduce(vec.begin(), vec.end());
    auto str = stdm::transform_reduce(vec.cbegin() + 1, vec.cend(),
        "{ "s + stdm::to_string(vec.front()),
        [](const stdm::string& left, const stdm::string& right)
        {
            return left + ", "s + right;
        },
        [](int val)
        {
            return stdm::to_string(val);
        }) + " }"s;

    stdm::cout << "stdm::accumulate: "sv << acc << stdm::endl;
    stdm::cout << "stdm::reduce: "sv << red << stdm::endl;
    stdm::cout << "stdm::transform_reduce: "sv << str << stdm::endl;
}

void precisionTest()
{
    stdm::cout << "Precision Test ->"sv << stdm::endl;
    constexpr auto pi = stdm::numbers::pi_v<long double>; // NOLINT
    stdm::cout << pi << stdm::endl;
    stdm::cout << stdm::setprecision(20); // NOLINT
    stdm::cout << pi << stdm::endl;
}

void allTests()
{
    stdm::cout << c_Seperator << stdm::endl;
    basicTest();
    stdm::cout << c_Seperator << stdm::endl;
    iterTest();
    stdm::cout << c_Seperator << stdm::endl;
    precisionTest();
    stdm::cout << c_Seperator << stdm::endl;

    stdm::cout << "End: ";
    stdm::cin.get();
}

int main()
{
    allTests();
    return stdm::Exit_Success;
}
