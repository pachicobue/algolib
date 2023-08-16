#pragma once
#include "../common.hpp"
#include "divisors_moebius.hpp"
#include "divisors_zeta.hpp"
/**
 * @brief gcd畳み込み
 * 
 * @param F F[0]==0
 * @param G G[0]==0
 * @param primes N未満の素数リスト
 * @return Vec<T> H[i]=\sum_{gcd(j,k)=i}F[j]G[k]
 */
template<typename T> Vec<T> gcdConvolute(Vec<T> F, Vec<T> G, const Vec<int>& primes)
{
    const int L = (int)std::ranges::min(F.size(), G.size());
    F.resize(L), G.resize(L);
    auto nF = divisorsZeta(F, false, primes), nG = divisorsZeta(G, false, primes);
    for (int i : rep(L)) { nF[i] *= nG[i]; }
    return divisorsMoebius(nF, false, primes);
}
/**
 * @brief gcd畳み込み
 * 
 * @param F F[0]==0
 * @param G G[0]==0
 * @return Vec<T> H[i]=\sum_{gcd(j,k)=i}F[j]G[k]
 */
template<typename T> Vec<T> gcdConvolute(const Vec<T>& F, const Vec<T>& G)
{
    const int L = (int)std::ranges::min(F.size(), G.size());
    return gcdConvolute(F, G, EratosthenesSieve{L}.primes());
}
