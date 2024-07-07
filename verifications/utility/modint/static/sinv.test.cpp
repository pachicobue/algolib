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
        const auto v = mint::sinv(N);
        assert(v * N == 1);
    }
}
int main() {
    test();
    return 0;
}
