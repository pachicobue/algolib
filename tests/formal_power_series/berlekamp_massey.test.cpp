#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "../../src/formal_power_series/berlekamp_massey.hpp"
#include "../../src/utility/modint.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    Vec<mint> as(N);
    for (auto& a : as) { a = in.val<int>(); }
    const auto cs = berlekampMassey(as);
    const int d = cs.size();
    Vec<int> ans(d - 1);
    for (int i : irange(1, d)) { ans[i - 1] = (-cs[i]).val(); }
    out.ln(d - 1);
    out.ln(ans);
    return 0;
}
