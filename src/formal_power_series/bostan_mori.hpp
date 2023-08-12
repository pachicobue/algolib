#pragma once
#include "formal_power_series.hpp"
#include "../algorithm/berlekamp_massey.hpp"
/**
 * @brief Bostan-Mori algorithm
 * 
 * @param f 
 * @param g 
 * @param N 
 * @return mint (f(x)/g(x)) [x^N]
 */
template<typename mint> mint bostanMori(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g, i64 N)
{
    assert(not g.isZero());
    const int f_zero = f.lsb(), g_zero = g.lsb();
    assert(g_zero <= f_zero);
    if (N < (i64)(f_zero - g_zero)) { return 0; }
    f <<= f_zero, g <<= g_zero;
    N -= (f_zero - g_zero);
    while (N > 0) {
        f.shrink(N + 1), g.shrink(N + 1);
        FormalPowerSeries<mint> mg;
        for (int i : rep(g.size())) { mg[i] = g[i] * (i % 2 == 0 ? 1 : -1); }
        const auto G = g * mg;
        const auto F = f * mg;
        for (int i : rep((F.size() + 1) / 2)) { f[i] = F.at(2 * i + (N % 2)); }
        for (int i : rep((G.size() + 1) / 2)) { g[i] = G.at(2 * i); }
        N /= 2;
    }
    return f[0] / g[0];
}

/**
 * @brief 線形回帰数列AのN項目
 * 
 * @param A 線形回帰数列
 * @param N 
 * @return mint AのN項目
 */
template<typename mint> mint guessNthTerm(const Vec<mint>& As, i64 N)
{
    const FormalPowerSeries<mint> g{berlekampMassey(As)};
    const int L  = g.size();
    const auto f = FormalPowerSeries<mint>{As}.mult(g, L - 1);
    return bostanMori(f, g, N);
}
