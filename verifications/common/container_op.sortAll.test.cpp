// verification-helper: UNITTEST
#include "internal/seq_op.hpp"

void PrimitiveArrTest()
{
    int vs[5] = {1, 3, 5, 2, 4};
    seqSort(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}
void VecTest()
{
    Vec<int> vs{1, 3, 5, 2, 4};
    seqSort(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}
void ArrTest()
{
    Arr<int, 5> vs{1, 3, 5, 2, 4};
    seqSort(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}
void DeqTest()
{
    Deq<int> vs{1, 3, 5, 2, 4};
    seqSort(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}

int main()
{
    PrimitiveArrTest();
    VecTest();
    ArrTest();
    DeqTest();
    return 0;
}
