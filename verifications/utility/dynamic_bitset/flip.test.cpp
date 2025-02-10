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
    LOOP (100) {
        const int i = rng.val(0, N - 1);
        const bool pb = bs.test(i);
        bs.flip(i);
        assert(bs.test(i) == (not pb));
    }
}
int main() {
    test();
    return 0;
}
