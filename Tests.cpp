export module Eqx.Stdm.Tests;

#include <Eqx/std.hpp>

using namespace std::literals;

namespace tests
{
    static_assert(std::vector<std::string>{ "Hello"s }
        == std::vector<std::string>{ "Hello"s });
    static_assert(std::same_as<std::make_signed_t<unsigned int>, int>);

    constexpr auto c_Delim = "-------------------------------------------\n"sv;
    constexpr auto port = 42'069;
    constexpr auto bufsize = 127;

    export inline void all() noexcept;
    inline void basicTest() noexcept;
    inline void iterTest() noexcept;
    inline void precisionTest() noexcept;
    inline void pipeTest() noexcept;
    inline void strCmpTest() noexcept;
    inline void vecCmpTest() noexcept;
    inline void durationPrintTest() noexcept;
    inline void fileWrite() noexcept;
    inline void sleep() noexcept;
    inline void fileRead() noexcept;
    inline void equal() noexcept;
    inline void fileSystemIterTest() noexcept;
    //inline void socket() noexcept;
}

namespace tests
{
    export inline void all() noexcept
    {
        std::cout << c_Delim;
        basicTest();
        std::cout << c_Delim;
        iterTest();
        std::cout << c_Delim;
        precisionTest();
        std::cout << c_Delim;
        pipeTest();
        std::cout << c_Delim;
        strCmpTest();
        std::cout << c_Delim;
        durationPrintTest();
        std::cout << c_Delim;
        fileWrite();
        std::cout << c_Delim;
        sleep();
        std::cout << c_Delim;
        fileRead();
        std::cout << c_Delim;
        equal();
        std::cout << c_Delim;
        fileSystemIterTest();
        std::cout << c_Delim;
        //socket();
        std::cout << c_Delim;
    }

    inline void basicTest() noexcept
    {
        std::cout << "Basic Test: "sv;
        auto vec = std::vector<int>{ 1, 2, 3 };
        std::cout << "{ 1 2 3 } == { "sv;
        std::ranges::for_each(vec, [](const int ele)
            { std::cout << ele << ' '; });
        std::cout << "}\n"sv;
    }

    inline void iterTest() noexcept
    {
        std::cout << "Iter Test:\n"sv;
        auto vec = std::vector<int>{ 1, 2, 3 };
        auto val = vec.begin();
        [[maybe_unused]] auto val2 = vec.end();
        [[maybe_unused]] auto vvv1 = std::begin(vec) == std::end(vec);
        [[maybe_unused]] auto vvv2 = val == (val + 1);
        [[maybe_unused]] auto vvv3 = vec.begin() == vec.end();
        [[maybe_unused]] auto vvv4 =
            std::ranges::begin(vec) == std::ranges::end(vec);
        for (auto iter = vec.begin(); iter != vec.end(); ++iter)
        {

        }
        std::cout << "{ 1 2 3 } == { "sv;
        for (int ele : vec)
        {
            std::cout << ele << ' ';
        }
        std::cout << "}\n"sv;
        auto acc = std::accumulate(std::ranges::begin(vec),
            std::ranges::end(vec), int{});
        auto red = std::reduce(vec.begin(), vec.end());
        auto str = std::transform_reduce(vec.cbegin() + 1, vec.cend(),
            "{ "s + std::to_string(vec.front()),
            [](const std::string& left, const std::string& right)
            {
                return left + ", "s + right;
            },
            [](const int val)
            {
                return std::to_string(val);
            }) + " }"s;

        std::cout << "std::accumulate: 6 == "sv << acc << '\n';
        std::cout << "std::reduce: 6 == "sv << red << '\n';
        std::cout << "std::transform_reduce: { 1, 2, 3 } == "sv << str << '\n';
    }

    inline void precisionTest() noexcept
    {
        std::cout << "Precision Test: "sv;
        constexpr auto pi = std::numbers::pi_v<long double>;
        std::cout << pi << " setprecision(20) "sv;
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers)
        std::cout << std::setprecision(20);
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers)
        std::cout << pi << '\n';
    }

    inline void pipeTest() noexcept
    {
        std::cout << "Pipe Test: "sv;
        const auto str = "HeLlO"sv;
        auto result = str
            | std::views::transform([](const char ele)
                {
                    return std::tolower(ele, std::locale{});
                });
        auto lcs = std::string{ std::ranges::cbegin(result),
            std::ranges::cend(result) };
        std::cout << "hello == " << lcs << '\n';
    }

    inline void strCmpTest() noexcept
    {
        std::cout << "String Compare Test: "sv;
        const auto str1 = "Hello"s;
        const auto str2 = "Hello"s;
        std::cout << "1 == "sv << (str1 == str2) << '\n';
    }

    inline void vecCmpTest() noexcept
    {
        std::cout << "Vector Compare Test:\n"sv;
        const auto vec1 = std::vector<int>{ 1, 2, 3 };
        const auto vec2 = std::vector<int>{ 1, 2, 3 };
        std::cout << "1 == "sv << (vec1 == vec2) << '\n';
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
        std::cout << "0 == "sv << (vec3 == vec4) << '\n';
    }

    inline void durationPrintTest() noexcept
    {
        std::cout << "Duration Print Test:\n"sv;
        constexpr auto nano = 1'000ns;
        constexpr auto micro = 1'000us;
        constexpr auto milli = 1'000ms;
        constexpr auto seconds = 1'000s;
        constexpr auto minutes = 1'000min;
        std::cout << "nano -> "sv << nano << '\n';
        std::cout << "micro -> "sv << micro << '\n';
        std::cout << "milli -> "sv << milli << '\n';
        std::cout << "seconds -> "sv << seconds << '\n';
        std::cout << "minutes -> "sv << minutes << '\n';
        auto xxx = std::stringstream{};
        std::cout << "micro -> "sv << (xxx << micro).rdbuf() << '\n';
        std::cout << "??? -> "sv << (xxx << micro << milli).rdbuf() << '\n';
        std::cout << "micro -> "sv
            << (std::stringstream{} << micro).str() << '\n';
        std::cout << "milli -> "sv
            << (std::stringstream{} << milli).str() << '\n';
        std::cout << "micro -> "sv
            << (std::stringstream{} << 1'000us).str() << '\n';
    }

    inline void fileWrite() noexcept
    {
        std::cout << "Write File:\n"sv;

        auto file = std::ofstream{"Text.txt", std::ios::out | std::ios::trunc};
        file << "Hello File!"sv << std::flush;

        file.close();
    }

    inline void sleep() noexcept
    {
        std::cout << "Sleep:\n"sv;
        std::this_thread::sleep_for(1'000ms);
    }

    inline void fileRead() noexcept
    {
        std::cout << "Read File: "sv;

        auto file = std::ifstream{"Text.txt", std::ios::in};
        std::cout << "Hello File! == " << file.rdbuf() << '\n';

        file.close();
    }

    inline void equal() noexcept
    {
        std::cout << "Equal: "sv;
        std::cout << "1 == "sv
            << std::ranges::equal_to{}("Hello Module"s, "Hello Module"s)
            << '\n';
    }

    inline void fileSystemIterTest() noexcept
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

    /*
    inline std::string server() noexcept
    {
        auto sock = osm::socket::open(osm::socket::domain::inet,
            osm::socket::type::stream);
        if (sock == osm::socket::error::invalid)
        {
            std::cerr << "sock";
        }
        auto sockopt = osm::socket::setsockopt(sock, osm::socket::level::socket,
            osm::socket::option::reuseaddr);
        if (sockopt != 0)
        {
            std::cerr << "sockopt";
        }
        auto b = osm::socket::bind(sock, port);
        if (b == -1)
        {
            std::cerr << "bind";
        }
        auto l = osm::socket::listen(sock);
        if (l == -1)
        {
            std::cerr << "listen";
        }
        auto acc = osm::socket::accept(sock, osm::socket::flag::cloexec);
        if (acc == -1)
        {
            std::cerr << "accept";
        }

        auto buf = std::array<char, bufsize>{};
        auto bytes = osm::socket::recv(acc, buf.data(), buf.size());
        buf.at(static_cast<std::size_t>(bytes)) = '\0';
        const char* msg = "Hello Client!";
        const auto len = 14;
        [[maybe_unused]] auto data = osm::socket::send(acc, msg, len);

        return std::string{buf.data()};
    }

    inline std::string client() noexcept
    {
        auto sock = osm::socket::open(osm::socket::domain::inet,
            osm::socket::type::stream);
        if (sock == osm::socket::error::invalid)
        {
            std::cerr << "sock";
        }
        auto con = osm::socket::connect(sock, "127.0.0.1", port);
        if (con == osm::socket::error::socket)
        {
            std::cerr << "connect";
        }

        const char* msg = "Hello Server!";
        const auto len = 14;
        [[maybe_unused]] auto data = osm::socket::send(sock, msg, len);
        auto buf = std::array<char, bufsize>{};
        auto bytes = osm::socket::recv(sock, buf.data(), buf.size());
        buf.at(static_cast<std::size_t>(bytes)) = '\0';
        return std::string{buf.data()};
    }

    inline void socket() noexcept
    {
        std::cout << "Socket Test:\n"sv;

        osm::socket::wsaInit();

        auto serv = std::async(std::launch::async, server);
        std::this_thread::sleep_for(1'000ms);
        auto cli = std::async(std::launch::async, client);

        std::cout << "Hello Server! == "sv << serv.get() << '\n';
        std::cout << "Hello Client! == "sv << cli.get() << '\n';
    }
*/
}
