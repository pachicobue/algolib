#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/data_structure/intdict.hpp"

void Test()
{
    IntDict<int, Str> dict;
    dict[-2] = "-2";
    dict[0] = "0";
    dict[2] = "2";
    assert(dict.contains(-2));
    assert(dict.contains(0));
    assert(dict.contains(2));
    assert(not dict.contains(-3));
    assert(not dict.contains(3));

    dict.erase(0);
    assert(dict.contains(-2));
    assert(not dict.contains(0));
    assert(dict.contains(2));

    assert(dict[2] == "2");
    dict[2] = "Two";
    assert(dict[2] == "Two");
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
