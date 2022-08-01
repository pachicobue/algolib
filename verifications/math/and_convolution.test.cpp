#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../src/math/and_convolution.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto n = in.val<int>();
    const int N = 1 << n;
    const auto as = in.vec<mint>(N);
    const auto bs = in.vec<mint>(N);
    const auto cs = andConvolute(as, bs);
    Vec<int> ans(cs.size());
    for (int i : rep(N)) {
        ans[i] = cs[i].val();
    }
    out.ln(ans);
    return 0;
}
