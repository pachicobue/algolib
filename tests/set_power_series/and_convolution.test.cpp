#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../src/set_power_series/and_convolution.hpp"
#include "../../src/util/modint.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto n = in.val<int>();
    const int N = 1 << n;
    const auto as = in.vec<mint>(N);
    const auto bs = in.vec<mint>(N);
    const auto cs = andConvolute(as, bs);
    Vec<int> ans(cs.size());
    for (int i : rep(N)) { ans[i] = cs[i].val(); }
    out.ln(ans);
    return 0;
}
