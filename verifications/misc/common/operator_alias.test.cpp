#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/misc/common/operator_alias.hpp"

void Test()
{
    std::vector<int> vs1{1, 2, 3, 4};
    std::vector<int> vs2{5, 6, 7};
    assert(vs1 + vs2 == std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
    vs1 += vs2;
    assert(vs1 == std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
}

int main()
{
    Test();

    std::cout << "Hello World\n";
    return 0;
}
