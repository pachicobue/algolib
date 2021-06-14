#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/string/mp.hpp"

void Test()
{
    Str s = "aabaabaaa";
    const auto rs = mp(s.begin(), s.end());
    assert(rs == (Vec<int>{-1, 0, 1, 0, 1, 2, 3, 4, 5, 2}));
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
