// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint = modint_2p61m1;
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
