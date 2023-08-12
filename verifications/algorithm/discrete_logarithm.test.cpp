// verification-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
#include "header.hpp"
#include "algorithm/discrete_logarithm.hpp"
int main()
{
    const auto T = in.val<int>();
    LOOP (T) {
        const auto [X, Y, M] = in.tup<i64, i64, i64>();
        auto mul = [M](i64 x, i64 y) { return x * y % M; };
        const auto K = discreteLogarithm(
            M, 1_i64, Y, [&](i64 x) { return mul(x, X); }, mul, mul);
        out.ln(K);
    }
    return 0;
}
