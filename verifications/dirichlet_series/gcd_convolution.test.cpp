// verification-helper: PROBLEM https://judge.yosupo.jp/problem/gcd_convolution
#include "dirichlet_series/gcd_convolution.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint    = modint_998244353;
    const auto N  = in.val<int>();
    const auto as = seqConcatCopy(Vec<mint>{0}, in.vec<mint>(N));
    const auto bs = seqConcatCopy(Vec<mint>{0}, in.vec<mint>(N));
    const auto cs = gcdConvolute(as, bs);
    Vec<int> Cs(N);
    for (int i : rep(N)) { Cs[i] = cs[i + 1].val(); }
    out.ln(Cs);
    return 0;
}
