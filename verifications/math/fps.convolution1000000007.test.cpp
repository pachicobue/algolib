#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../src/math/fps.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_1000000007;
    const auto [N, M] = in.tup<int, int>();
    FPS<mint> as(N), bs(M);
    for (auto& a : as) {
        a.setRaw(in.val<int>());
    }
    for (auto& b : bs) {
        b.setRaw(in.val<int>());
    }
    const auto cs = as * bs;
    Vec<int> ans(N + M - 1);
    for (int i : rep(N + M - 1)) {
        ans[i] = cs.at(i).val();
    }
    out.ln(ans);
    return 0;
}
