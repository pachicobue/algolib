#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
#include "../../src/util/rng.hpp"
#include "../../src/math/convolution.hpp"
int main()
{
    const auto [A, B] = in.tup<int, int>();
    out.ln(A + B);

    const auto AN = rng.val<int>(1, 1000);
    const auto BN = rng.val<int>(1, 1000);
    const auto as = rng.vec<int>(AN, -100000000, 100000000);
    const auto bs = rng.vec<int>(BN, -100000000, 100000000);

    const auto cs = convolute_i64(as, bs);
    Vec<i64> ds(AN + BN - 1, 0);
    for (int i : rep(AN)) {
        for (int j : rep(BN)) { ds[i + j] += (i64)as[i] * bs[j]; }
    }
    assert(cs == ds);
    return 0;
}
