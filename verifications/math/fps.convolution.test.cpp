#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../src/math/fps.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [N, M] = in.tup<int, int>();
    FPS<mint> as(N), bs(M);
    for (int i : rep(N)) {
        as[i].setRaw(in.val<int>());
    }
    for (int j : rep(M)) {
        bs[j].setRaw(in.val<int>());
    }
    auto cs = as * bs;
    Vec<int> ans(cs.size());
    for (int i : rep(cs.size())) {
        ans[i] = cs[i].val();
    }
    out.ln(ans);
    return 0;
}
