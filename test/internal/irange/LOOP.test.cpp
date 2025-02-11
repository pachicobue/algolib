// verification-helper: UNITTEST
#include <cassert>
#include <cmath>
#include "internal/irange.hpp"
void test() {
    int cnt = 0;
    LOOP (100) {
        cnt++;
    }
    assert(cnt == 100);
}
int main() {
    test();
    return 0;
}
