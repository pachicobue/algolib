// verification-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
#include "header.hpp"
#include "algorithm/discrete_logarithm.hpp"
int main()
{
    const auto T = in.val<int>();
    using mint = modint_dynamic<0>;
    LOOP (T) {
        const auto [X, Y, M] = in.tup<i64, i64, i64>();
        mint::setMod(M);
        auto f = [X = X, M = M](i64 x) { return x * X % M; };
        UMap<i64, i64> ps;
        auto fp = [&, X = X, M = M](i64 K, i64 x) {
            if (ps.count(K) == 0) { ps[K] = mint(X).pow(K).val(); }
            return x * ps[K] % M;
        };
        const auto K = discreteLogarithm(M, f, fp, 1_i64 % M, Y);
        out.ln(K);
    }
    return 0;
}
