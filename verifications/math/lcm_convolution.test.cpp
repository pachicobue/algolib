#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "../../src/math/lcm_convolution.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    const auto as = Vec<mint>{0} + in.vec<mint>(N);
    const auto bs = Vec<mint>{0} + in.vec<mint>(N);
    const auto cs = lcmConvolute(as, bs);
    Vec<int> Cs(N);
    for (int i : rep(N)) {
        Cs[i] = cs[i + 1].val();
    }
    out.ln(Cs);
    return 0;
}
