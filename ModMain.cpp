import Stdm;

int main()
{
    auto vec = stdm::vector<int>{ 1, 2, 3 };
    stdm::cout << "Vec: ";
    stdm::ranges::for_each(vec, [](int ele)
        { stdm::cout << ele << ' '; });
    stdm::cout << stdm::endl;
    stdm::cout << "End: ";
    stdm::cin.get();
    return 0;
}
