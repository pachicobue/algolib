// verification-helper: PROBLEM https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
#include "formal_power_series/bostan_mori.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [D, K] = in.tup<int, i64>();
    const auto as = in.vec<mint>(D);
    auto cs = Vec<mint>{1};
    concat(cs, in.vec<mint>(D));
    FormalPowerSeries<mint> f{as};
    FormalPowerSeries<mint> g{cs};
    for (int i : irange(1, D + 1)) { g[i] *= (-1); }
    f = f.mult(g, D);
    const auto ans = bostanMori(f, g, K);
    out.ln(ans.val());
    return 0;
}
