import Stdm;

int main()
{
    stdm::locale::global(stdm::locale{ "C.UTF-8" });
    auto x = stdm::locale{ "" };
    stdm::cout << x.name() << stdm::endl;
    return 0;
}
