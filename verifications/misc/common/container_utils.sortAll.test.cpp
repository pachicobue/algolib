#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/misc/common/container_utils.hpp"

void PrimitiveArrTest()
{
    int vs[5] = {1, 3, 5, 2, 4};
    sortAll(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}
void VecTest()
{
    Vec<int> vs{1, 3, 5, 2, 4};
    sortAll(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}
void ArrTest()
{
    Arr<int, 5> vs{1, 3, 5, 2, 4};
    sortAll(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}
void DeqTest()
{
    Deq<int> vs{1, 3, 5, 2, 4};
    sortAll(vs);
    assert(std::is_sorted(std::begin(vs), std::end(vs)));
}

int main()
{
    PrimitiveArrTest();
    VecTest();
    ArrTest();
    DeqTest();
    std::cout << "Hello World\n";
    return 0;
}
