// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint = modint_2p61m1;
void test() {
    LOOP (100) {
        const auto N = rng.val(1, 100);
        mint ans = 1;
        for (int i : rep(N)) {
            ans *= (i + 1);
        }
        assert(mint::fact(N) == ans);
    }
}
int main() {
    test();
    return 0;
}
