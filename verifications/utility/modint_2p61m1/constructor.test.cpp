// verification-helper: UNITTEST
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint        = modint_2p61m1;
constexpr u64 MOD = (1_u64 << 61) - 1;
void emptyTest()
{
    mint v;
    assert(v.val() == 0);
}
void i64Test()
{
    LOOP (100) {
        const i64 x = rng.val(-INF<i64>, INF<i64>);
        mint v{x};
        assert(0 <= v.val() and v.val() < MOD);
        assert((x - (i64)v.val()) % (i64)MOD == 0);
    }
}
int main()
{
    emptyTest();
    i64Test();
    return 0;
}
