// verification-helper: UNITTEST
#include "internal/seq_op.hpp"

void PrimitiveArrTest()
{
    int vs[5] = {1, 3, 5, 2, 4};
    seqReverse(vs);
    int rvs[5] = {4, 2, 5, 3, 1};
    for (int i = 0; i < 5; i++) { assert(vs[i] == rvs[i]); }
}
void VecTest()
{
    Vec<int> vs = {1, 3, 5, 2, 4};
    seqReverse(vs);
    Vec<int> rvs = {4, 2, 5, 3, 1};
    for (int i = 0; i < 5; i++) { assert(vs[i] == rvs[i]); }
}
void ArrTest()
{
    Arr<int, 5> vs = {1, 3, 5, 2, 4};
    seqReverse(vs);
    Arr<int, 5> rvs = {4, 2, 5, 3, 1};
    for (int i = 0; i < 5; i++) { assert(vs[i] == rvs[i]); }
}
void DeqTest()
{
    Deq<int> vs = {1, 3, 5, 2, 4};
    seqReverse(vs);
    Deq<int> rvs = {4, 2, 5, 3, 1};
    for (int i = 0; i < 5; i++) { assert(vs[i] == rvs[i]); }
}

int main()
{
    PrimitiveArrTest();
    VecTest();
    ArrTest();
    DeqTest();
    return 0;
}
