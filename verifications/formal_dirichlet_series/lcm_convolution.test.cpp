// verification-helper: PROBLEM https://judge.yosupo.jp/problem/lcm_convolution
#include "formal_dirichlet_series/lcm_convolution.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint    = modint_998244353;
    const auto N  = in.val<int>();
    const auto as = concatCopy(Vec<mint>{0}, in.vec<mint>(N));
    const auto bs = concatCopy(Vec<mint>{0}, in.vec<mint>(N));
    const auto cs = lcmConvolute(as, bs, N + 1);
    Vec<int> Cs(N);
    for (int i : rep(N)) { Cs[i] = cs[i + 1].val(); }
    out.ln(Cs);
    return 0;
}
