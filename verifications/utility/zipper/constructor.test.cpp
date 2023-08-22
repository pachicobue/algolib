// verification-helper: UNITTEST
#include "utility/zipper.hpp"
void emptyTest()
{
    Zipper<int> zipper;
    assert(zipper.size() == 0);
}
void vecTest()
{
    Zipper<int> zipper({2, 4, 2, 6, 6, 2});
    assert(zipper.size() == 3);
}
int main()
{
    emptyTest();
    vecTest();
}
