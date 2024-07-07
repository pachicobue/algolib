// verification-helper: UNITTEST
#include <cassert>
#include "internal/irange.hpp"
void test() {
    int cnt = 0;
    for (int i : rep(100)) {
        assert(i == cnt);
        cnt++;
    }
}
int main() {
    test();
    return 0;
}
