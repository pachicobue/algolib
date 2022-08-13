#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../../src/formal_power_series/fps.hpp"
#include "../../src/util/modint.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    FormalPowerSeries<mint> as = in.vec<mint>(N);
    const auto bs = as.log(N);
    Vec<mint> ans(N);
    for (int i : rep(N)) { ans[i] = bs.at(i); }
    out.ln(ans);
    return 0;
}
