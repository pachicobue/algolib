#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../src/math/nth_term.hpp"
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
    as.resize(2 * K, 0);
    for (int i = K; i < 2 * K; i++) {
        for (int j = 1; j <= K; j++) {
            as[i] += as[i - j];
        }
    }
    mat css(K, vec(K, 0));
    for (int i = 0; i < K - 1; i++) {
        css[i][i + 1] = 1;
    }
    for (int j = 0; j < K; j++) {
        css[K - 1][j] = 1;
    }
    auto mul = [&](const mat& m1, const mat& m2) {
        mat ans(K, vec(K, 0));
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                for (int k = 0; k < K; k++) {
                    ans[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return ans;
    };
    auto pow = [&](auto self, const mat& m, const i64 n) -> mat {
        if (n == 1) { return m; }
        if (n % 2 == 0) {
            return self(self, mul(m, m), n / 2);
        } else {
            return mul(m, self(self, m, n - 1));
        }
    };
    const auto Mat = pow(pow, css, N);
    mint actual = 0;
    for (int j = 0; j < K; j++) {
        actual += Mat[0][j] * as[j];
    }
    const mint ans = nthTerm(as, N);
    assert(actual == ans);
    out.ln(A + B);
    return 0;
}
