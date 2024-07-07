// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/clamp_op.hpp"
#include "utility/rng.hpp"
void test() {
    const i64 L = -TEN<i64>(15), U = TEN<i64>(15);
    for (int i : rep(300)) {
        const auto x = (i % 3 == 0 ? rng.val(L, U) : i % 3 == 1 ? rng.val(U / 2, U * 2)
                                                                : rng.val(L * 2, L / 2));
        const auto y = (i % 3 == 0 ? rng.val(-1, 1) : i % 3 == 1 ? rng.val(-4, 4)
                                                                 : rng.val(-4, 4));
        if (y == 0) { continue; }
        const auto z = clampDiv(x, y, L, U);
        if (floorDiv(x, y) > U) {
            assert(z == U);
        } else if (floorDiv(x, y) < L) {
            assert(z == L);
        } else {
            assert(z == floorDiv(x, y));
        }
    }
}
int main() { test(); }
