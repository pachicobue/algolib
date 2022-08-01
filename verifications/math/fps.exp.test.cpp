#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../../src/math/fps.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    FPS<mint> as(N);
    for (auto& a : as) {
        a.setRaw(in.val<int>());
    }
    const auto bs = as.exp(N);
    std::vector<int> ans(N);
    for (int i : rep(N)) {
        ans[i] = bs.at(i).val();
    }
    out.ln(ans);
    return 0;
}
