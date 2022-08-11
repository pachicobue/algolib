#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "../../src/math/fps.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [N, c] = in.tup<int, int>();
    FPS<mint> as = in.vec<mint>(N);
    const auto bs = as.tshift(mint{c});
    Vec<mint> ans(N);
    for (int i : rep(N)) { ans[i] = bs.at(i); }
    out.ln(ans);
    return 0;
}
