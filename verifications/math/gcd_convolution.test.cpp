#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "../../src/math/gcd_convolution.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    const auto as = Vec<mint>{0} + in.vec<mint>(N);
    const auto bs = Vec<mint>{0} + in.vec<mint>(N);
    const auto cs = gcdConvolute(as, bs);
    Vec<int> Cs(N);
    for (int i : rep(N)) { Cs[i] = cs[i + 1].val(); }
    out.ln(Cs);
    return 0;
}
