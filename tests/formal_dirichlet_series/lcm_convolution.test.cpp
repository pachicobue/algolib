// verification-helper: PROBLEM https://judge.yosupo.jp/problem/lcm_convolution
#include "formal_dirichlet_series/lcm_convolution.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    auto as = Vec<mint>{0};
    concat(as, in.vec<mint>(N));
    auto bs = Vec<mint>{0};
    concat(bs, in.vec<mint>(N));
    const auto cs = lcmConvolute(as, bs);
    Vec<int> Cs(N);
    for (int i : rep(N)) { Cs[i] = cs[i + 1].val(); }
    out.ln(Cs);
    return 0;
}
