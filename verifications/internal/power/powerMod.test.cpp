// verification-helper: UNITTEST
#include "internal/power.hpp"
#include "internal/irange.hpp"

void smallTest()
{
    const u64 MOD = 998244353;
    const u64 x   = 1000234;
    const int N   = 100;
    u64 ans       = 1;
    LOOP (N) { (ans *= x) %= MOD; }
    assert(powerMod(x, N, MOD) == ans);
}
void largeTest()
{
    const u64 MOD = 998244353_u64 * 1000000007;
    const u64 x   = 1000423231243234;
    const int N   = 100;
    u128 ans      = 1;
    LOOP (N) { (ans *= x) %= MOD; }
    assert(powerMod(x, N, MOD) == (u64)ans);
}

int main()
{
    smallTest();
    largeTest();
    return 0;
}
