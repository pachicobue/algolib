// verification-helper: UNITTEST
#include "utility/modint_2p61m1.hpp"
#include "utility/rng.hpp"
using mint        = modint_2p61m1;
constexpr u64 MOD = (1_u64 << 61) - 1;
void test()
{
    LOOP (100) {
        const mint v{(i64)rng.val(1_u64, MOD - 1)};
        const auto iv = v.inv();
        assert(v * iv == 1);
    }
}
int main()
{
    test();
    return 0;
}
