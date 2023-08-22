// verification-helper: UNITTEST
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint        = modint_2p61m1;
constexpr u64 MOD = (1_u64 << 61) - 1;
void negTest()
{
    LOOP (100) {
        const mint v{(i64)rng.val(0_u64, MOD - 1)};
        const auto nv = -v;
        assert((v.val() + nv.val()) % MOD == 0);
    }
}
void plusEqTest()
{
    LOOP (100) {
        mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(0_u64, MOD - 1)};
        const u64 m = (v1.val() + v2.val()) % MOD;
        v1 += v2;
        assert(v1.val() == m);
    }
}
void minusEqTest()
{
    LOOP (100) {
        mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(0_u64, MOD - 1)};
        const u64 m = (MOD + v1.val() - v2.val()) % MOD;
        v1 -= v2;
        assert(v1.val() == m);
    }
}
void prodEqTest()
{
    LOOP (100) {
        mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(0_u64, MOD - 1)};
        const u64 m = ((u128)v1.val() * v2.val()) % MOD;
        v1 *= v2;
        assert(v1.val() == m);
    }
}
void divEqTest()
{
    LOOP (100) {
        mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(1_u64, MOD - 1)};
        const u64 pm = v1.val();
        v1 /= v2;
        assert((v1 * v2).val() == pm);
    }
}
void plusTest()
{
    LOOP (100) {
        const mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(0_u64, MOD - 1)};
        const u64 m    = (v1.val() + v2.val()) % MOD;
        const auto ans = v1 + v2;
        assert(ans.val() == m);
    }
}
void minusTest()
{
    LOOP (100) {
        const mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(0_u64, MOD - 1)};
        const u64 m    = (MOD + v1.val() - v2.val()) % MOD;
        const auto ans = v1 - v2;
        assert(ans.val() == m);
    }
}
void prodTest()
{
    LOOP (100) {
        const mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(0_u64, MOD - 1)};
        const u64 m    = ((u128)v1.val() * v2.val()) % MOD;
        const auto ans = v1 * v2;
        assert(ans.val() == m);
    }
}
void divTest()
{
    LOOP (100) {
        const mint v1{(i64)rng.val(0_u64, MOD - 1)};
        const mint v2{(i64)rng.val(1_u64, MOD - 1)};
        const auto ans = v1 / v2;
        assert(ans * v2 == v1);
    }
}
void eqTest()
{
    LOOP (100) {
        const mint v1{(i64)rng.val(0_u64, MOD - 1)};
        mint v2{(i64)rng.val(1_u64, MOD - 1)};
        if (rng.val(0, 5) == 0) { v2 = v1; }
        assert((v1 == v2) == (v1.val() == v2.val()));
    }
}
int main()
{
    negTest();

    plusEqTest();
    minusEqTest();
    prodEqTest();
    divEqTest();

    plusTest();
    minusTest();
    prodTest();
    divTest();

    eqTest();
    return 0;
}
