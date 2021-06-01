#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/data_structure/rsq.hpp"

void PrefixTest()
{
    Vec<int> vs{1, 2, 3, 4};
    auto rsq = RSQ(vs);
    assert(rsq.prefixSum(0, 4) == 10);
    assert(rsq.prefixSum(1, 3) == 5);
    rsq.unsafeSet(0, 101);
    rsq.unsafeSet(1, 102);
    rsq.unsafeSet(2, 103);
    assert(rsq.prefixSum(1, 3) == 205);
    rsq.unsafeSet(3, 104);
    assert(rsq.prefixSum(0, 4) == 410);
    assert(rsq[0] == 101);
    assert(rsq[1] == 102);
    assert(rsq[2] == 103);
    assert(rsq[3] == 104);

    rsq.unsafeSet(1, 202);
    assert(rsq.prefixSum(0, 4) != 510);
    rsq.recalc();
    assert(rsq.prefixSum(0, 4) == 510);
}

void SuffixTest()
{
    Vec<int> vs{1, 2, 3, 4};
    auto rsq = RSQ(vs);
    assert(rsq.prefixSum(0, 4) == 10);
    assert(rsq.prefixSum(1, 3) == 5);
    rsq.unsafeSet(3, 104);
    rsq.unsafeSet(2, 103);
    rsq.unsafeSet(1, 102);
    assert(rsq.suffixSum(1, 3) == 205);
    rsq.unsafeSet(0, 101);
    assert(rsq.suffixSum(0, 4) == 410);
    assert(rsq[0] == 101);
    assert(rsq[1] == 102);
    assert(rsq[2] == 103);
    assert(rsq[3] == 104);

    rsq.unsafeSet(1, 202);
    assert(rsq.suffixSum(0, 4) != 510);
    rsq.recalc();
    assert(rsq.suffixSum(0, 4) == 510);
}

int main()
{
    PrefixTest();
    SuffixTest();
    std::cout << "Hello World\n";
    return 0;
}
