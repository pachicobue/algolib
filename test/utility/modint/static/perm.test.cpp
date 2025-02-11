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
        const auto M = rng.val(0, N + 1);
        mint ans = 1;
        for (int i : rep(M)) {
            ans *= (N - i);
        }
        assert(mint::perm(N, M) == ans);
    }
}
int main() {
    test();
    return 0;
}
