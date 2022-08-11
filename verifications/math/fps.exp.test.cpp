#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../../src/math/fps.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto N = in.val<int>();
    FPS<mint> as = in.vec<mint>(N);
    const auto bs = as.exp(N);
    std::vector<mint> ans(N);
    for (int i : rep(N)) { ans[i] = bs.at(i); }
    out.ln(ans);
    return 0;
}
