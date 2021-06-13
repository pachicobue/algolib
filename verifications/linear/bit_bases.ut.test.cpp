#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/linear/bit_bases.hpp"

void Test()
{
    constexpr int D = 3;
    Vec<BSet<D>> vs{3, 1, 2, 5};
    BitBases<D> bases(vs);
    assert(bases.rank() == 3);  //011,101,001
    assert(bases[0] == 3);
    assert(bases[1] == 1);
    assert(bases[2] == 5);
    assert(bases.decomp(2).first);
    assert(bases.decomp(2).second == 3);
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
