// verification-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
#include "header.hpp"
#include "algorithm/discrete_logarithm.hpp"
int main()
{
    const auto T = in.val<int>();
    LOOP (T) {
        using mint           = modint_dynamic<0>;
        const auto [X, Y, M] = in.tup<i64, i64, i64>();
        mint::setMod(M);
        auto mul       = [](i64 x, i64 y) { return (i64)(mint(x) * y).val(); };
        const auto Ans = discreteLogarithm(M + 1, 1_i64 % M, Y, X, mul, mul);
        if (Ans < M) {
            out.ln(Ans);
        } else {
            out.ln(-1);
        }
    }
    return 0;
}
