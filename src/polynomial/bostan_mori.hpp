#pragma once
#include "polynomial.hpp"
#include "../algorithm/berlekamp_massey.hpp"
/**
 * @brief Bostan-Mori algorithm
 *        G(x)*H(x)=F(x) (mod x^(N+1)) を満たすH(x)の x^N係数
 * 
 * @tparam mint 
 * @param F 
 * @param G 
 * @param N 指数
 * @return mint G(x)*H(x)=F(x) (mod x^(N+1)) を満たすH(x)の x^N係数
 */
template<typename mint> constexpr mint bostanMori(Polynomial<mint> F, Polynomial<mint> G, i64 N)
{
    assert(not G.isZero());
    const int ford = F.order(), gord = G.order();
    assert(gord <= ford);
    if (N < (i64)(ford - gord)) { return 0; }
    F <<= ford, G <<= gord, N -= (ford - gord);
    while (N > 0) {
        F.shrink(N + 1), G.shrink(N + 1);
        Polynomial<mint> mG;
        for (int i : rep(G.size())) { mG[i] = G[i] * (i % 2 == 0 ? 1 : -1); }
        const auto nG = G * mG;
        const auto nF = F * mG;
        for (int i : rep(ceilDiv(F.size(), 2))) { F[i] = nF.at(2 * i + (N % 2)); }
        for (int i : rep(ceilDiv(G.size(), 2))) { G[i] = nG.at(2 * i); }
        N /= 2;
    }
    return F[0] / G[0];
}

/**
 * @brief 線形回帰数列AsのN項目
 * 
 * @param As 線形回帰数列
 * @param N 
 * @return mint AsのN項目
 */
template<typename mint> constexpr mint guessNthTerm(const Vec<mint>& As, i64 N)
{
    const Polynomial<mint> G{berlekampMassey(As)};
    const int L = G.size();
    if (L == 1) { return As[0]; }
    const auto F = (Polynomial<mint>{As} * G).low(L - 1);
    return bostanMori(F, G, N);
}
