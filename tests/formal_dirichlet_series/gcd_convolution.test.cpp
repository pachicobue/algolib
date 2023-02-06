#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "../../src/formal_dirichlet_series/gcd_convolution.hpp"
#include "../../src/util/modint.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    auto as = Vec<mint>{0};
    concat(as, in.vec<mint>(N));
    auto bs = Vec<mint>{0};
    concat(bs, in.vec<mint>(N));
    const auto cs = gcdConvolute(as, bs);
    Vec<int> Cs(N);
    for (int i : rep(N)) { Cs[i] = cs[i + 1].val(); }
    out.ln(Cs);
    return 0;
}
