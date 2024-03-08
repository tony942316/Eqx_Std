import Stdm.Containers.Vector;

int main()
{
    auto v = stdm::vector<int>({ 1, 2, 3 });
    auto v2 = stdm::vector<int>({ 3, 2, 1 });
    auto b = v == v2;
    auto b2 = v != v2;
    auto b3 = v < v2;
    stdm::swap(v, v2);
    auto vv = stdm::begin(v);
    auto vvv = stdm::end(v);
    return 0;
}
