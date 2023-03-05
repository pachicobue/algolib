// verification-helper: UNITTEST
#include "utility/zipper.hpp"

void ConstructorTest()
{
    Zipper<int> zipper({2, 4, 2, 6, 6, 2});  // {2,4,6}
    assert(zipper.unzip(0) == 2);
    assert(zipper.unzip(1) == 4);
    assert(zipper.unzip(2) == 6);
    assert(zipper.zip(2) == 0);
    assert(zipper.zip(4) == 1);
    assert(zipper.zip(6) == 2);
    assert(zipper.size() == 3);
}

void AddTest1()
{
    Zipper<int> zipper({2, 4, 2, 6, 6, 2});  // {2,4,6}
    zipper.add(3);                           // {2,3,4,6}
    assert(zipper.unzip(0) == 2);
    assert(zipper.unzip(1) == 3);
    assert(zipper.unzip(2) == 4);
    assert(zipper.unzip(3) == 6);
    assert(zipper.zip(2) == 0);
    assert(zipper.zip(3) == 1);
    assert(zipper.zip(4) == 2);
    assert(zipper.zip(6) == 3);
    assert(zipper.size() == 4);
}

void AddTest2()
{
    Zipper<int> zipper;
    zipper.add({2, 4, 2, 6, 6, 2});  // {2,4,6}
    assert(zipper.unzip(0) == 2);
    assert(zipper.unzip(1) == 4);
    assert(zipper.unzip(2) == 6);
    assert(zipper.zip(2) == 0);
    assert(zipper.zip(4) == 1);
    assert(zipper.zip(6) == 2);
    assert(zipper.size() == 3);
}

int main()
{
    ConstructorTest();
    AddTest1();
    AddTest2();
    return 0;
}
