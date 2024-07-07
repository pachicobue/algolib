// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/rng.hpp"
constexpr u64 MOD = 998244353;
using mint = modint<MOD>;
void emptyTest() {
    mint v;
    assert(v.val() == 0);
}
void i64Test() {
    LOOP (100) {
        const i64 x = rng.val(-INF<i64>, INF<i64>);
        mint v{x};
        assert(0 <= v.val() and v.val() < MOD);
        assert((x - (i64)v.val()) % (i64)MOD == 0);
    }
}
int main() {
    emptyTest();
    i64Test();
    return 0;
}
