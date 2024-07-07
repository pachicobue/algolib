// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/clamp_op.hpp"
#include "utility/rng.hpp"
void test() {
    const i64 L = -TEN<i64>(15), U = TEN<i64>(15);
    for (int i : rep(300)) {
        const auto x = (i % 3 == 0 ? rng.val(L, U) : i % 3 == 1 ? rng.val(U / 2, U)
                                                                : rng.val(L, L / 2));
        const auto y = (i % 3 == 0 ? rng.val(L, U) : i % 3 == 1 ? rng.val(U / 2, U)
                                                                : rng.val(L, L / 2));
        const auto z = clampMul(x, y, L, U);
        if ((i128)x * y > U) {
            assert(z == U);
        } else if ((i128)x * y < L) {
            assert(z == L);
        } else {
            assert(z == x * y);
        }
    }
}
int main() { test(); }
