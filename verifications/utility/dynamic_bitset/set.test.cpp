// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void set1Test() {
    const auto N = 1000;
    DynamicBitset bs{N};
    LOOP (100) {
        const int i = rng.val(0, N - 1);
        bs.set(i);
        assert(bs.test(i));
    }
}
void set2Test() {
    const auto N = 1000;
    DynamicBitset bs{N};
    LOOP (100) {
        const int i = rng.val(0, N - 1);
        const bool b = rng.val(0, 1);
        bs.set(i, b);
        assert(bs.test(i) == b);
    }
}
int main() {
    set1Test();
    set2Test();
    return 0;
}
