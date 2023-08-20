// verification-helper: PROBLEM https://judge.yosupo.jp/problem/find_linear_recurrence
#include "algorithm/berlekamp_massey.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    using mint    = modint_998244353;
    const auto N  = in.val<int>();
    const auto as = in.vec<mint>(N);
    const auto cs = berlekampMassey(as);
    const int d   = cs.size();
    Vec<int> ans(d - 1);
    for (int i : irange(1, d)) { ans[i - 1] = (-cs[i]).val(); }
    out.ln(d - 1);
    out.ln(ans);
    return 0;
}
