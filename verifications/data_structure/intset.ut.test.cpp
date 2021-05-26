#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/data_structure/intset.hpp"

void Test()
{
    IntSet<int> set;
    set.insert(-2);
    set.insert(0);
    set.insert(2);
    assert(set.contains(-2));
    assert(set.contains(0));
    assert(set.contains(2));
    assert(not set.contains(-3));
    assert(not set.contains(3));

    set.erase(0);
    assert(set.contains(-2));
    assert(not set.contains(0));
    assert(set.contains(2));
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
