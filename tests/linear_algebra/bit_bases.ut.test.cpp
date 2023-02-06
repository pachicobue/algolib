#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/linear_algebra/bit_bases.hpp"

void Test()
{
    constexpr int D = 3;
    Vec<BSet<D>> vs{3, 1, 2, 5};
    BitBases<D> bases;
    for (const auto& v : vs) { bases.add(v); }
    assert(bases.rank() == 3);  //011,101,001
    const auto origBases = bases.origBases();
    assert(origBases == (Vec<BSet<D>>{3, 1, 5}));
    assert(bases.decomp(2).first);
    assert(bases.decomp(2).second == 3);
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}