// verification-helper: PROBLEM https://judge.yosupo.jp/problem/subset_convolution
#include "set_series/subset_convolution.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint    = modint_998244353;
    const auto N  = in.val<int>();
    const auto as = in.vec<mint>(1 << N);
    const auto bs = in.vec<mint>(1 << N);
    const auto cs = subsetConvolute(as, bs);
    Vec<int> ans(cs.size());
    for (int i : rep(1 << N)) { ans[i] = cs[i].val(); }
    out.ln(ans);
    return 0;
}
