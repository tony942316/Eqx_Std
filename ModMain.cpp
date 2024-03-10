import Stdm;

int main()
{
    auto str = stdm::string{"Hello"sv};
    stdm::cout << str << stdm::endl;
    auto strv = stdm::string_view{str};
    stdm::cout << strv << stdm::endl;
    return 0;
}
