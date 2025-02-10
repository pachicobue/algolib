// verification-helper: UNITTEST
#include <cassert>
#include "utility/zipper.hpp"
void test() {
    Zipper<int> zipper({2, 4, 2, 6, 6, 2});
    assert(zipper.unzip(0) == 2);
    assert(zipper.unzip(1) == 4);
    assert(zipper.unzip(2) == 6);
    assert(zipper.zip(2) == 0);
    assert(zipper.zip(4) == 1);
    assert(zipper.zip(6) == 2);
}
int main() {
    test();
}
