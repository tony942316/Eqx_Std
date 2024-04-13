import Stdm;

int main()
{
    stdm::locale::global(stdm::locale{ "C.UTF-8" });
    auto xxx = stdm::locale{ "" };
    stdm::cout << xxx.name() << stdm::endl;
    return 0;
}
