// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint = modint_2p61m1;
constexpr u64 MOD = (1_u64 << 61) - 1;
void test() {
    LOOP (100) {
        const mint v{(i64)rng.val(0_u64, MOD - 1)};
        const auto N = rng.val(0, 100);
        mint ans = 1;
        LOOP (N) {
            ans *= v;
        }
        assert(v.pow(N) == ans);
    }
}
int main() {
    test();
    return 0;
}
