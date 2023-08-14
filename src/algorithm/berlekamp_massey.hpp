#pragma once
#include "../common.hpp"
/**
 * @brief Berlekamp-Massey algorithm
 *        \sum_{0<=i<=K}A[x-i]C[i] = 0 (K<=x<|A|) を満たす最短の数列Cを求める (C[0] = 1)
 * @see https://mzhang2021.github.io/cp-blog/berlekamp-massey
 * 
 * @tparam T 体(integerから変換可能)
 * @param As 数列
 * @return Vec<T> 係数列
 */
template<typename T> constexpr Vec<T> berlekampMassey(const Vec<T>& As)
{
    const int N = (int)As.size();
    Vec<T> C{1};                                    // 係数列
    Tup<Vec<T>, int, T> lastFailure = {{}, -1, 0};  // {前バージョンの係数列, 失敗したindex, 残差}
    auto eval                       = [&](const Vec<T>& C, int i) {
        assert(not C.empty());
        const int D = (int)C.size() - 1;
        if (i < D) { return T{}; }
        T s = 0;
        for (int j : rep(D + 1)) { s += As[i - j] * C[j]; }
        return s;
    };
    for (int i : rep(N)) {
        const T d = eval(C, i);
        if (d == 0) { continue; }
        const Tup<Vec<T>, int, T> nlastFailure = {C, i, d};
        const auto& [pC, pi, pd]               = lastFailure;
        const int nl = i - (int)C.size(), pl = pi - (int)pC.size();
        if (pi != -1) {  // Cを調整
            const bool updateFailure = (pl < nl);
            const auto [c, s]        = makePair(d / pd, i - pi);
            if (C.size() < pC.size() + s) { C.resize(pC.size() + s); }
            for (int j : rep(pC.size())) { C[j + s] -= pC[j] * c; }
            if (updateFailure) { lastFailure = nlastFailure; }
        } else {
            C = Vec<T>(i + 2), C[0] = 1;
            lastFailure = nlastFailure;
        }
    }
    return C;
}
