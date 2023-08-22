// verification-helper: UNITTEST
#include "utility/zipper.hpp"
void valTest()
{

    Zipper<int> zipper({2, 4, 2, 6, 6, 2});
    assert(zipper.zip(2) == 0);
    assert(zipper.zip(4) == 1);
    assert(zipper.zip(6) == 2);
    zipper.add(-10);
    zipper.add(3);
    assert(zipper.zip(-10) == 0);
    assert(zipper.zip(2) == 1);
    assert(zipper.zip(3) == 2);
    assert(zipper.zip(4) == 3);
    assert(zipper.zip(6) == 4);
}
void vecTest()
{
    Zipper<int> zipper({2, 4, 2, 6, 6, 2});
    assert(zipper.zip(2) == 0);
    assert(zipper.zip(4) == 1);
    assert(zipper.zip(6) == 2);
    zipper.add({-10, 3});
    assert(zipper.zip(-10) == 0);
    assert(zipper.zip(2) == 1);
    assert(zipper.zip(3) == 2);
    assert(zipper.zip(4) == 3);
    assert(zipper.zip(6) == 4);
}
int main()
{
    valTest();
    vecTest();
}
