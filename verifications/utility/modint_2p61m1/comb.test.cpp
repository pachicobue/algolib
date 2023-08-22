// verification-helper: UNITTEST
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint        = modint_2p61m1;
constexpr u64 MOD = (1_u64 << 61) - 1;
void test()
{
    LOOP (100) {
        const auto N = rng.val(1, 100);
        const auto M = rng.val(0, N + 1);
        mint ans     = 1;
        for (int i : rep(M)) {
            ans *= (N - i);
            ans /= (i + 1);
        }
        assert(mint::comb(N, M) == ans);
    }
}
int main()
{
    test();
    return 0;
}
