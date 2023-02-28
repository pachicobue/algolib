// verification-helper: UNITTEST
#include "common/container_op.hpp"

void Primitive1DArrTest()
{
    int vs[6] = {1, 3, 1, 2, 3, 2};
    const int sum1 = sumAll<int>(vs);
    int sum2 = 0;
    for (int i = 0; i < 6; i++) { sum2 += vs[i]; }
    assert(sum1 == sum2);
}
void Primitive2DArrTest()
{
    int vss[2][6] = {{1, 3, 1, 2, 3, 2}, {3, 1, 4, 1, 5, 9}};
    const int sum1 = sumAll<int>(vss);
    int sum2 = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) { sum2 += vss[i][j]; }
    }
    assert(sum1 == sum2);
}
void Vec1DArrTest()
{
    Vec<int> vs{1, 3, 1, 2, 3, 2};
    const int sum1 = sumAll<int>(vs);
    int sum2 = 0;
    for (int i = 0; i < 6; i++) { sum2 += vs[i]; }
    assert(sum1 == sum2);
}
void Vec2DArrTest()
{
    Vec<Vec<int>> vss{{1, 3, 1, 2, 3, 2}, {3, 1, 4, 1, 5, 9}};
    const int sum1 = sumAll<int>(vss);
    int sum2 = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) { sum2 += vss[i][j]; }
    }
    assert(sum1 == sum2);
}
void Arr1DArrTest()
{
    Arr<int, 6> vs{1, 3, 1, 2, 3, 2};
    const int sum1 = sumAll<int>(vs);
    int sum2 = 0;
    for (int i = 0; i < 6; i++) { sum2 += vs[i]; }
    assert(sum1 == sum2);
}
void Arr2DArrTest()
{
    Arr<Arr<int, 6>, 2> vss{{{1, 3, 1, 2, 3, 2}, {3, 1, 4, 1, 5, 9}}};
    const int sum1 = sumAll<int>(vss);
    int sum2 = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) { sum2 += vss[i][j]; }
    }
    assert(sum1 == sum2);
}
void Deq1DArrTest()
{
    Deq<int> vs{1, 3, 1, 2, 3, 2};
    const int sum1 = sumAll<int>(vs);
    int sum2 = 0;
    for (int i = 0; i < 6; i++) { sum2 += vs[i]; }
    assert(sum1 == sum2);
}
void Deq2DArrTest()
{
    Deq<Deq<int>> vss{{1, 3, 1, 2, 3, 2}, {3, 1, 4, 1, 5, 9}};
    const int sum1 = sumAll<int>(vss);
    int sum2 = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) { sum2 += vss[i][j]; }
    }
    assert(sum1 == sum2);
}
void CastTest()
{
    Vec<int> vs{1 << 30, 1 << 30, 1 << 30, 1 << 30, 1 << 30, 1 << 30};
    const int sum1 = sumAll<int>(vs);
    const i64 sum2 = sumAll<i64>(vs);
    i64 sum3 = 0;
    for (int i = 0; i < 6; i++) { sum3 += vs[i]; }
    assert(sum1 != sum3);
    assert(sum2 == sum3);
}
int main()
{
    Primitive1DArrTest();
    Primitive2DArrTest();
    Vec1DArrTest();
    Vec2DArrTest();
    Arr1DArrTest();
    Arr2DArrTest();
    Deq1DArrTest();
    Deq2DArrTest();
    CastTest();
    return 0;
}
