// verification-helper: UNITTEST
#include "data_structure/fenwick_tree/fenwick_tree.hpp"

void Test()
{
    FenwickTree<int> fenwick({1, 2, 3, 4, 5, 6, 7});
    assert(fenwick.maxRight([](int s) { return s <= 0; }) == 0);
    assert(fenwick.maxRight([](int s) { return s <= 1; }) == 1);
    assert(fenwick.maxRight([](int s) { return s <= 3; }) == 2);
    assert(fenwick.maxRight([](int s) { return s <= 21; }) == 6);
    assert(fenwick.maxRight([](int s) { return s <= 30; }) == 7);
    std::cerr << fenwick << std::endl;
}

int main()
{
    Test();
    return 0;
}
