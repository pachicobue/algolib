#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../src/math/fps.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    using mint = modint_998244353;
    const auto [N, M] = in.tup<int, int>();
    FPS<mint> as = in.vec<mint>(N);
    FPS<mint> bs = in.vec<mint>(M);
    auto cs = as * bs;
    Vec<mint> ans(N + M - 1);
    for (int i : rep(N + M - 1)) {
        ans[i] = cs.at(i);
    }
    out.ln(ans);
    return 0;
}
