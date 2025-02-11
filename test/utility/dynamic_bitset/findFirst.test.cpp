// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void test() {
    const auto N = 1000;
    DynamicBitset bs{N};
    int first = N;
    for (int i : rep(N)) {
        const bool b = rng.val(0, 1);
        if (b) {
            chmin(first, i);
        }
        bs.set(i, b);
    }
    assert(bs.findFirst() == first);
    bs.resetAll();
    assert(bs.findFirst() == N);
}
int main() {
    test();
    return 0;
}
