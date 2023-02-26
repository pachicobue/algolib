#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../src/set_power_series/or_convolution.hpp"
#include "../../src/utility/modint.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
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
    for (int i : rep(N)) { ans[i] = Cs[N - i - 1].val(); }
    out.ln(ans);
    return 0;
}
