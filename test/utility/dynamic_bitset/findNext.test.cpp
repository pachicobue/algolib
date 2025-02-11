// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void test() {
    const auto N = 1000;
    DynamicBitset bs{N};
    for (int i : rep(N)) {
        bs.set(i, rng.val(0, 1));
    }
    int p = -1;
    while (p + 1 < N) {
        int np = p + 1;
        while (np < N and not bs.test(np)) {
            np++;
        }
        assert(bs.findNext(p) == np);
        p = np;
    }
}
int main() {
    test();
    return 0;
}
