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

void pipeTest()
{
    stdm::cout << "Pipe Test ->"sv << stdm::endl;
    const auto str = "HeLlO"sv;
    auto result = str
        | stdm::views::transform([](const char ele)
            {
                return stdm::tolower(ele, stdm::locale{});
            });
    auto lcs = stdm::string{ stdm::ranges::cbegin(result),
        stdm::ranges::cend(result) };
    stdm::cout << str << stdm::endl;
    stdm::cout << lcs << stdm::endl;
}

void strCmpTest()
{
    stdm::cout << "String Compare Test ->\n"sv;
    const auto str1 = "Hello"s;
    const auto str2 = "Hello"s;
    stdm::cout << (str1 == str2) << '\n';
}

void vecCmpTest()
{
    stdm::cout << "Vector Compare Test ->\n"sv;
    const auto vec1 = stdm::vector<int>{ 1, 2, 3 };
    const auto vec2 = stdm::vector<int>{ 1, 2, 3 };
    stdm::cout << (vec1 == vec2) << '\n';
    auto vec3 = stdm::vector<stdm::string>{ "Hello"s };
    auto vec4 = stdm::vector<stdm::string>{ "There"s };
    [[maybe_unused]] const auto val = *vec3.begin() == *vec4.begin();
    [[maybe_unused]] const auto val2 = (*(*vec3.begin()).begin()) == (*(*vec4.begin()).begin());
    stdm::ranges::equal(vec3, vec4);
    [[maybe_unused]] const auto val3 = vec3 == vec4;
    auto vec5 = stdm::vector<stdm::vector<int>>{};
    auto vec6 = stdm::vector<stdm::vector<int>>{};
    [[maybe_unused]] const auto val4 = vec5 == vec6;
    auto vec7 = stdm::vector<stdm::string>{};
    auto vec8 = stdm::vector<stdm::string>{};
    [[maybe_unused]] const auto val5 = stdm::ranges::equal(vec7, vec8);
    auto vec9 = stdm::vector<stdm::pair<int, int>>{};
    auto vec10 = stdm::vector<stdm::pair<int, int>>{};
    [[maybe_unused]] const auto val6 = vec9 == vec10;
    stdm::cout << (vec3 == vec4) << '\n';
}

static_assert(stdm::vector<stdm::string>{ "Hello"s }
    == stdm::vector<stdm::string>{ "Hello"s });

void allTests()
{
    stdm::cout << c_Seperator << stdm::endl;
    basicTest();
    stdm::cout << c_Seperator << stdm::endl;
    iterTest();
    stdm::cout << c_Seperator << stdm::endl;
    precisionTest();
    stdm::cout << c_Seperator << stdm::endl;
    pipeTest();
    stdm::cout << c_Seperator << stdm::endl;
    strCmpTest();
    stdm::cout << c_Seperator << stdm::endl;
    vecCmpTest();
    stdm::cout << c_Seperator << stdm::endl;

    stdm::cout << "End: ";
    stdm::cin.get();
}

int main()
{
    allTests();
    return stdm::Exit_Success;
}
