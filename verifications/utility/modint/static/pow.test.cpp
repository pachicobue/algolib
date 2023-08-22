// verification-helper: UNITTEST
#include "utility/modint.hpp"
#include "utility/rng.hpp"
constexpr u64 MOD = 998244353;
using mint        = modint<MOD>;
void test()
{
    LOOP (100) {
        const mint v{(i64)rng.val(0_u64, MOD - 1)};
        const auto N = rng.val(0, 100);
        mint ans     = 1;
        LOOP (N) { ans *= v; }
        assert(v.pow(N) == ans);
    }
}
int main()
{
    test();
    return 0;
}
