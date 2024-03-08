import Stdm;

int main()
{
    stdm::vector<int> v;
    stdm::cout << 'X' << stdm::endl;
    stdm::cout << "Enter Num: ";
    auto x = 0;
    stdm::cin >> x;
    stdm::cout << "Number is: " << x << stdm::endl;
    static_assert(stdm::same_as<char, char>);
    return 0;
}
