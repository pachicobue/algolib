#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../src/math/or_convolution.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto n = in.val<int>();
    const int N = 1 << n;
    const auto as = in.vec<mint>(N);
    const auto bs = in.vec<mint>(N);
    Vec<mint> As(N, 0), Bs(N, 0);
    for (int i : rep(N)) {
        As[i] = as[N - i - 1];
        Bs[i] = bs[N - i - 1];
    }
    const auto Cs = orConvolute(As, Bs);
    Vec<int> ans(Cs.size());
    for (int i : rep(N)) {
        ans[i] = Cs[N - i - 1].val();
    }
    out.ln(ans);
    return 0;
}
