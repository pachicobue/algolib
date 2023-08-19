// verification-helper: UNITTEST
#include "internal/seq_op.hpp"
#include "internal/md_seq_op.hpp"
#include "internal/sorted_seq_op.hpp"

void seqMinIndTest()
{
    std::vector<int> vs{2, 1, 1, 3, 3, 2};
    assert(seqMinInd(vs) == 1);
}

void seqMaxIndTest()
{
    std::vector<int> vs{2, 1, 1, 3, 3, 2};
    assert(seqMaxInd(vs) == 3);
}

void sortedLbIndTest()
{
    std::vector<int> vs{1, 1, 3, 3, 3, 5, 5};
    assert(sortedLbInd(vs, 0) == 0);
    assert(sortedLbInd(vs, 1) == 0);
    assert(sortedLbInd(vs, 5) == 5);
    assert(sortedLbInd(vs, 6) == 7);
}

void sortedUbIndTest()
{
    std::vector<int> vs{1, 1, 3, 3, 3, 5, 5};
    assert(sortedUbInd(vs, 0) == 0);
    assert(sortedUbInd(vs, 1) == 2);
    assert(sortedUbInd(vs, 5) == 7);
    assert(sortedUbInd(vs, 6) == 7);
}

void genVecTest()
{
    int x    = 1;
    auto gen = [&]() {
        const int y = x;
        x *= 2;
        return y;
    };
    auto vs = genVec<int>(5, gen);
    assert(vs == std::vector<int>({1, 2, 4, 8, 16}));
}

void iotaVecTest()
{
    auto vs = iotaVec(5, 2);
    assert(vs == std::vector<int>({2, 3, 4, 5, 6}));
}

int main()
{
    seqMinIndTest();
    seqMaxIndTest();
    sortedLbIndTest();
    sortedUbIndTest();
    genVecTest();
    iotaVecTest();
    return 0;
}
