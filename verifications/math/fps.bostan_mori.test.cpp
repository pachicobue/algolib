#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "../../src/math/bostan_mori.hpp"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [D, K] = in.tup<int, i64>();
    const auto as = in.vec<mint>(D);
    const auto cs = Vec<mint>{1} + in.vec<mint>(D);
    FPS<mint> f(as);
    FPS<mint> g(cs);
    for (int i : irange(1, D + 1)) { g[i] *= (-1); }
    f = f.mult(g, D);
    const auto ans = bostanMori(f, g, K);
    out.ln(ans.val());
    return 0;
}
