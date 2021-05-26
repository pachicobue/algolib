#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/misc/common/irange.hpp"

void repTest()
{
    std::vector<int> is;
    for (int i : rep(5)) {
        is.push_back(i);
    }
    assert(is == std::vector<int>({0, 1, 2, 3, 4}));
}

void perTest()
{
    std::vector<int> is;
    for (int i : per(5)) {
        is.push_back(i);
    }
    assert(is == std::vector<int>({4, 3, 2, 1, 0}));
}

void irangeTest1()
{
    std::vector<int> is1;
    for (int i : irange(2, 5)) {
        is1.push_back(i);
    }
    assert(is1 == std::vector<int>({2, 3, 4}));

    std::vector<int> is2;
    for (int i : irange(2, 10, 3)) {
        is2.push_back(i);
    }
    assert(is2 == std::vector<int>({2, 5, 8}));

    std::vector<int> is3;
    for (int i : irange(2, 11, 3)) {
        is3.push_back(i);
    }
    assert(is3 == std::vector<int>({2, 5, 8}));

    std::vector<int> is4;
    for (int i : irange(2, 1, 3)) {
        is4.push_back(i);
    }
    assert(is4.empty());
}

void irangeTest2()
{
    std::vector<int> is2;
    for (int i : irange(10, 2, -3)) {
        is2.push_back(i);
    }
    assert(is2 == std::vector<int>({10, 7, 4}));

    std::vector<int> is3;
    for (int i : irange(11, 2, -3)) {
        is3.push_back(i);
    }
    assert(is3 == std::vector<int>({11, 8, 5}));

    std::vector<int> is4;
    for (int i : irange(1, 2, -3)) {
        is4.push_back(i);
    }
    assert(is4.empty());
}

int main()
{
    repTest();
    perTest();
    irangeTest1();
    irangeTest2();
    std::cout << "Hello World\n";
    return 0;
}
