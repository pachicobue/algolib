#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/data_structure/dsu.hpp"

void Test()
{
    DSU dsu(7);
    dsu.merge(0, 1);
    dsu.merge(2, 3);
    dsu.merge(4, 5);
    dsu.merge(5, 6);
    assert(dsu.size(0) == 2);
    assert(dsu.size(1) == 2);
    assert(dsu.size(2) == 2);
    assert(dsu.size(3) == 2);
    assert(dsu.size(4) == 3);
    assert(dsu.size(5) == 3);
    assert(dsu.size(6) == 3);
    assert(dsu.groups()
           == Vec<Vec<int>>({{}, {0, 1}, {}, {2, 3}, {}, {4, 5, 6}, {}}));
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
