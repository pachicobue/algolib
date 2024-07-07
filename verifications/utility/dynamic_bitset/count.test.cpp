// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void test() {
    const auto N = 1000;
    DynamicBitset bs{N};
    int C = 0;
    for (int i : rep(N)) {
        const auto b = rng.val(0, 1);
        bs.set(i, b), C += b;
    }
    assert(bs.count() == C);
}
int main() {
    test();
    return 0;
}
