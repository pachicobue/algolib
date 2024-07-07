// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/rng.hpp"
constexpr u64 MOD = 998244353;
using mint = modint<MOD>;
void test() {
    LOOP (100) {
        const auto N = rng.val(1, 100);
        mint ans = 1;
        for (int i : rep(N)) { ans *= (i + 1); }
        assert(mint::ifact(N) * ans == 1);
    }
}
int main() {
    test();
    return 0;
}
