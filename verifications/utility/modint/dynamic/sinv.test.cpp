// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/rng.hpp"
using mint = modint_dynamic<0>;
constexpr u64 MOD = 1000000007;
void test() {
    LOOP (100) {
        const auto N = rng.val(1, 100);
        const auto v = mint::sinv(N);
        assert(v * N == 1);
    }
}
int main() {
    mint::setMod(MOD);
    test();
    return 0;
}
