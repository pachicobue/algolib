// verification-helper: UNITTEST
#include "utility/modint.hpp"
#include "utility/rng.hpp"
using mint        = modint_dynamic<0>;
constexpr u64 MOD = 1000000007;
void test()
{
    LOOP (100) {
        const auto N = rng.val(1, 100);
        const auto M = rng.val(0, N + 1);
        mint ans     = 1;
        for (int i : rep(M)) { ans *= (N - i); }
        assert(mint::perm(N, M) == ans);
    }
}
int main()
{
    mint::setMod(MOD);
    test();
    return 0;
}
