#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "../../src/math/fps.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [N, c] = in.tup<int, int>();
    FPS<mint> as(N);
    for (auto& a : as) {
        a.setRaw(in.val<int>());
    }
    const auto bs = as.tshift(mint{c});
    std::vector<int> ans(N);
    for (int i : rep(N)) {
        ans[i] = bs.at(i).val();
    }
    out.ln(ans);
    return 0;
}
