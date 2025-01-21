export module Eqx.Std.Tester;

import <Eqx/std.hpp>;

export namespace tester
{
    template < class T, class U>
        requires requires(T&& value1, U&& value2) {value1 != std::invoke(value2);}
    class Test
    {
    public:
        Test() = delete;

        Test(const Test&) = default;
        Test(Test&&) = default;
        Test& operator= (const Test&) = default;
        Test& operator= (Test&&) = default;
        ~Test() = default;

        explicit constexpr Test(T&& answer, U&& test) noexcept
            : 
            m_answer(std::forward<T>(answer)),
            m_test(std::forward<U>(test))
        {}

        constexpr bool run() const noexcept 
        {
            if (m_answer != std::invoke(m_test))
            {
                return false;
            }
            else
            {
                return true;
            }
        }


    private:
        T m_answer;
        U m_test;
    };

    template <typename... T>
    bool test_results(T&&... args) noexcept
    {
        auto result = true;

        ((result = result && args.run()), ...);

        return result;
    }
}