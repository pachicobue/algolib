#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include "../../src/math/subset_convolution.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    const auto as = in.vec<mint>(1 << N);
    const auto bs = in.vec<mint>(1 << N);
    const auto cs = subsetConvolute(as, bs);
    Vec<int> ans(cs.size());
    for (int i : rep(1 << N)) { ans[i] = cs[i].val(); }
    out.ln(ans);
    return 0;
}
