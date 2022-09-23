#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "../../src/formal_dirichlet_series/lcm_convolution.hpp"
#include "../../src/util/modint.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    const auto as = Vec<mint>{0} + in.vec<mint>(N);
    const auto bs = Vec<mint>{0} + in.vec<mint>(N);
    const auto cs = lcmConvolute(as, bs);
    Vec<int> Cs(N);
    for (int i : rep(N)) { Cs[i] = cs[i + 1].val(); }
    out.ln(Cs);
    return 0;
}