#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "../../src/formal_power_series/formal_power_series.hpp"
#include "../../src/utility/modint.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"

int main()
{
    using mint = modint_998244353;
    const auto [N, M] = in.tup<int, i64>();
    FormalPowerSeries<mint> as = in.vec<mint>(N);
    const auto bs = as.pow(M, N);
    Vec<mint> ans(N);
    for (int i : rep(N)) { ans[i] = bs.at(i); }
    out.ln(ans);
    return 0;
}
