// verification-helper: UNITTEST
#include "internal/md_seq_op.hpp"

void PrimitiveArr1DTest()
{
    int vs[5] = {1, 3, 5, 2, 4};
    mdSeqFill(vs, 1);
    for (int i = 0; i < 5; i++) { assert(vs[i] == 1); }
}
void PrimitiveArr2DTest()
{
    int vs[2][5] = {
        {1, 3, 5, 2, 4},
        {3, 1, 4, 1, 5}
    };
    mdSeqFill(vs, 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) { assert(vs[i][j] == 1); }
    }
}
void Vec1DTest()
{
    Vec<int> vs{1, 3, 5, 2, 4};
    mdSeqFill(vs, 1);
    for (int i = 0; i < 5; i++) { assert(vs[i] == 1); }
}
void Vec2DTest()
{
    Vec<Vec<int>> vss{
        {1, 3, 5, 2, 4},
        {3, 1, 4, 1, 5}
    };
    mdSeqFill(vss, 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) { assert(vss[i][j] == 1); }
    }
}
void Arr1DTest()
{
    Arr<int, 5> vs{1, 3, 5, 2, 4};
    mdSeqFill(vs, 1);
    for (int i = 0; i < 5; i++) { assert(vs[i] == 1); }
}
void Arr2DTest()
{
    Arr<Arr<int, 5>, 2> vss{
        {{1, 3, 5, 2, 4}, {3, 1, 4, 1, 5}}
    };
    mdSeqFill(vss, 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) { assert(vss[i][j] == 1); }
    }
}
void Deq1DTest()
{
    Deq<int> vs{1, 3, 5, 2, 4};
    mdSeqFill(vs, 1);
    for (int i = 0; i < 5; i++) { assert(vs[i] == 1); }
}
void Deq2DTest()
{
    Deq<Deq<int>> vss{
        {1, 3, 5, 2, 4},
        {3, 1, 4, 1, 5}
    };
    mdSeqFill(vss, 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) { assert(vss[i][j] == 1); }
    }
}
void CastTest()
{
    Vec<i64> vs{1, 3, 5, 2, 4};
    mdSeqFill(vs, (short)1);
    for (int i = 0; i < 5; i++) { assert(vs[i] == 1); }
}

int main()
{
    PrimitiveArr1DTest();
    PrimitiveArr2DTest();
    Vec1DTest();
    Vec2DTest();
    Arr1DTest();
    Arr2DTest();
    Deq1DTest();
    Deq2DTest();
    CastTest();
    return 0;
}
