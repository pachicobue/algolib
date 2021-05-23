#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../src/math/fps_div_nth.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto [A, B] = in.tup<int, int>();
    using mint = modint_1000000007;
    const auto K = rng.val<int>(2, 10);
    const auto N = rng.val<i64>(1, 1000000000);
    using vec = std::vector<mint>;
    using mat = std::vector<vec>;
    Vec<mint> as(K);
    for (auto& a : as) {
        a = rng.val<int>(0, mint::mod() - 1);
    }
    mat css(K, vec(K, 0));
    for (int i : rep(K - 1)) {
        css[i][i + 1] = 1;
    }
    for (int j : rep(K)) {
        css[K - 1][j] = 1;
    }
    auto mul = [&](const mat& m1, const mat& m2) {
        mat ans(K, vec(K, 0));
        for (int i : rep(K)) {
            for (int j : rep(K)) {
                for (int k : rep(K)) {
                    ans[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return ans;
    };
    auto pow = Fixpoint([&](auto dfs, const mat& m, i64 n) -> mat {
        if (n == 1) { return m; }
        if (n % 2 == 0) {
            return dfs(mul(m, m), n / 2);
        } else {
            return mul(m, dfs(m, n - 1));
        }
    });
    const auto Mat = pow(css, N);
    mint actual = 0;
    for (int j = 0; j < K; j++) {
        actual += Mat[0][j] * as[j];
    }
    FPS<mint> f(as);
    FPS<mint> g(K + 1, -1);
    g[0] = 1;
    f = f.mult(g, K);
    const mint ans = divNth(f, g, N);
    assert(actual == ans);
    out.ln(A + B);
    return 0;
}
