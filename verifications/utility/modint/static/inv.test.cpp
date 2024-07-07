// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/rng.hpp"
constexpr u64 MOD = 998244353;
using mint = modint<MOD>;
void test() {
    LOOP (100) {
        const mint v{(i64)rng.val(1_u64, MOD - 1)};
        const auto iv = v.inv();
        assert(v * iv == 1);
    }
}
int main() {
    test();
    return 0;
}
