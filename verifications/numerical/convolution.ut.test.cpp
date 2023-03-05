// verification-helper: UNITTEST
#include "numerical/convolution.hpp"
#include "utility/rng.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    const auto AN = rng.val<int>(1, 1000);
    const auto BN = rng.val<int>(1, 1000);
    const auto as = rng.vec<i64>(AN, -100000000, 100000000);
    const auto bs = rng.vec<i64>(BN, -100000000, 100000000);

    const auto cs = convolute_i64(as, bs);
    Vec<i64> ds(AN + BN - 1, 0);
    for (int i : rep(AN)) {
        for (int j : rep(BN)) { ds[i + j] += (i64)as[i] * bs[j]; }
    }
    assert(cs == ds);
    return 0;
}
