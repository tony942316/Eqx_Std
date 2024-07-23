import Eqx.Stdm;

using namespace std::literals;

constexpr auto c_Seperator = "***********************"sv;

void basicTest()
{
    std::cout << "Basic Test ->"sv << std::endl;
    auto vec = std::vector<int>{ 1, 2, 3 };
    std::cout << "Vec: "sv;
    std::ranges::for_each(vec, [](int ele)
        { std::cout << ele << ' '; });
    std::cout << std::endl;
}

void iterTest()
{
    std::cout << "Iter Test ->"sv << std::endl;
    auto vec = std::vector<int>{ 1, 2, 3 };
    auto val = vec.begin();
    [[maybe_unused]] auto val2 = vec.end();
    [[maybe_unused]] auto vvv1 = std::begin(vec) == std::end(vec);
    [[maybe_unused]] auto vvv2 = val == (val + 1);
    [[maybe_unused]] auto vvv3 = vec.begin() == vec.end();
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {

    }
    std::cout << "Vector: { "sv;
    for (int ele : vec)
    {
        std::cout << ele << " "sv;
    }
    std::cout << "}"sv << std::endl;
    auto acc = std::accumulate(std::ranges::begin(vec),
        std::ranges::end(vec), int{});
    auto red = std::reduce(vec.begin(), vec.end());
    auto str = std::transform_reduce(vec.cbegin() + 1, vec.cend(),
        "{ "s + std::to_string(vec.front()),
        [](const std::string& left, const std::string& right)
        {
            return left + ", "s + right;
        },
        [](int val)
        {
            return std::to_string(val);
        }) + " }"s;

    std::cout << "std::accumulate: "sv << acc << std::endl;
    std::cout << "std::reduce: "sv << red << std::endl;
    std::cout << "std::transform_reduce: "sv << str << std::endl;
}

void precisionTest()
{
    std::cout << "Precision Test ->"sv << std::endl;
    constexpr auto pi = std::numbers::pi_v<long double>; // NOLINT
    std::cout << pi << std::endl;
    std::cout << std::setprecision(20); // NOLINT
    std::cout << pi << std::endl;
}

void pipeTest()
{
    std::cout << "Pipe Test ->"sv << std::endl;
    const auto str = "HeLlO"sv;
    auto result = str
        | std::views::transform([](const char ele)
            {
                return std::tolower(ele, std::locale{});
            });
    auto lcs = std::string{ std::ranges::cbegin(result),
        std::ranges::cend(result) };
    std::cout << str << std::endl;
    std::cout << lcs << std::endl;
}

void strCmpTest()
{
    std::cout << "String Compare Test ->\n"sv;
    const auto str1 = "Hello"s;
    const auto str2 = "Hello"s;
    std::cout << (str1 == str2) << '\n';
}

void vecCmpTest()
{
    std::cout << "Vector Compare Test ->\n"sv;
    const auto vec1 = std::vector<int>{ 1, 2, 3 };
    const auto vec2 = std::vector<int>{ 1, 2, 3 };
    std::cout << (vec1 == vec2) << '\n';
    auto vec3 = std::vector<std::string>{ "Hello"s };
    auto vec4 = std::vector<std::string>{ "There"s };
    [[maybe_unused]] const auto val = *vec3.begin() == *vec4.begin();
    [[maybe_unused]] const auto val2 =
        (*(*vec3.begin()).begin()) == (*(*vec4.begin()).begin());
    [[maybe_unused]] const auto val3 = std::ranges::equal(vec3, vec4);
    [[maybe_unused]] const auto val4 = vec3 == vec4;
    auto vec5 = std::vector<std::vector<int>>{};
    auto vec6 = std::vector<std::vector<int>>{};
    [[maybe_unused]] const auto val5 = vec5 == vec6;
    auto vec7 = std::vector<std::string>{};
    auto vec8 = std::vector<std::string>{};
    [[maybe_unused]] const auto val6 = std::ranges::equal(vec7, vec8);
    auto vec9 = std::vector<std::pair<int, int>>{};
    auto vec10 = std::vector<std::pair<int, int>>{};
    [[maybe_unused]] const auto val7 = vec9 == vec10;
    std::cout << (vec3 == vec4) << '\n';
}

void durationPrintTest()
{
    constexpr auto nano = 1'000ns;
    constexpr auto micro = 1'000us;
    constexpr auto milli = 1'000ms;
    constexpr auto seconds = 1'000s;
    constexpr auto minutes = 1'000min;
    std::cout << nano << std::endl;
    std::cout << micro << std::endl;
    std::cout << milli << std::endl;
    std::cout << seconds << std::endl;
    std::cout << minutes << std::endl;
    auto xxx = std::stringstream{};
    std::cout << (xxx << micro).rdbuf() << std::endl;
    std::cout << (xxx << micro << milli).rdbuf() << std::endl;
    std::cout << (std::stringstream{} << micro).str() << std::endl;
    std::cout << (std::stringstream{} << milli).str() << std::endl;
    std::cout << (std::stringstream{} << 1'000us).str() << std::endl;
}

void filePrintTest()
{
    auto file = std::fstream{"Test.txt"};
    std::cout << file.rdbuf() << std::endl;
    //foo::filePrint();
}

void sleepTest()
{
    std::cout << "Sleeping..." << std::endl;
    std::this_thread::sleep_for(1'000ms);
    std::cout << "Awake!" << std::endl;
    //foo::sleep();
}

void equalTest()
{
    std::cout << "Hello Server == Hello Server: "sv
        << std::ranges::equal_to{}("Hello Server"s, "Hello Server"s)
        << std::endl;
    //foo::equal();
}

void fileSystemIterTest()
{
    auto path = std::filesystem::path{"./"};
    auto dir = std::filesystem::directory_iterator{path};
    auto rDir = std::filesystem::recursive_directory_iterator{path};
    auto beg = std::ranges::begin(dir);
    auto rBeg = std::ranges::begin(rDir);

    auto ss = std::stringstream{};

    std::cout << "Directory Iterator...\n";
    for (const auto& entry : dir)
    {
        ss << entry.path() << std::endl;
    }

    std::ranges::for_each(dir, [&ss](const auto& entry)
        {
            ss << entry.path() << std::endl;
        });

    std::cout << "Recursive Directory Iterator...\n";
    for (const auto& entry : rDir)
    {
        ss << entry.path() << std::endl;
    }

    rDir = std::filesystem::recursive_directory_iterator{path};
    std::ranges::for_each(rDir, [&ss](const auto& entry)
        {
            ss << entry.path() << std::endl;
        });
}

static_assert(std::vector<std::string>{ "Hello"s }
    == std::vector<std::string>{ "Hello"s });
static_assert(std::same_as<std::make_signed_t<unsigned int>, int>);

void runTest(void (*func)()) noexcept
{
    std::cout << c_Seperator << std::endl;
    func();
    std::cout << c_Seperator << std::endl;
}

void allTests()
{
    runTest(basicTest);
    runTest(iterTest);
    runTest(precisionTest);
    runTest(pipeTest);
    runTest(strCmpTest);
    runTest(vecCmpTest);
    runTest(durationPrintTest);
    runTest(filePrintTest);
    runTest(sleepTest);
    runTest(equalTest);
    runTest(fileSystemIterTest);

    std::cout << "End: ";
    std::cin.get();
}

int main()
{
    allTests();
    return 0;
}
