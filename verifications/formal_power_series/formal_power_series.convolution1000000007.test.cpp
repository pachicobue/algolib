// verification-helper: PROBLEM https://judge.yosupo.jp/problem/convolution_mod_1000000007
#include "formal_power_series/formal_power_series.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint = modint_1000000007;
    const auto [N, M] = in.tup<int, int>();
    FormalPowerSeries<mint> as = in.vec<mint>(N);
    FormalPowerSeries<mint> bs = in.vec<mint>(M);
    const auto cs = as * bs;
    Vec<mint> ans(N + M - 1);
    for (int i : rep(N + M - 1)) { ans[i] = cs.at(i); }
    out.ln(ans);
    return 0;
}
