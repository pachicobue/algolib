// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/rng.hpp"
using mint = modint_dynamic<0>;
constexpr u64 MOD = 1000000007;
void test() {
    LOOP (100) {
        const mint v{(i64)rng.val(1_u64, MOD - 1)};
        const auto iv = v.inv();
        assert(v * iv == 1);
    }
}
int main() {
    mint::setMod(MOD);
    test();
    return 0;
}
