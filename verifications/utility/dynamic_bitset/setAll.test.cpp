// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void test() {
    const auto N = 1000;
    DynamicBitset bs{N};
    for (int i : rep(N)) { bs.set(i, rng.val(0, 1)); }
    bs.setAll();
    for (int i : rep(N)) { assert(bs.test(i)); }
}
int main() {
    test();
    return 0;
}
