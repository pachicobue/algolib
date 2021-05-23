#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "math/fps.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    FPS<mint> as(N);
    for (auto& a : as) {
        a.setRaw(in.val<int>());
    }
    const auto bs = as.inv(N);
    Vec<int> ans(N);
    for (int i : rep(N)) {
        ans[i] = bs.at(i).val();
    }
    out.ln(ans);
    return 0;
}
