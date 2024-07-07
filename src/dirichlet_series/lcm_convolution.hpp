#pragma once
#include "../internal.hpp"
#include "../number/eratosthenes_sieve.hpp"
#include "divisors_moebius.hpp"
#include "divisors_zeta.hpp"
/**
 * @brief lcm畳み込み
 *
 * @param F F[0]==0
 * @param G G[0]==0
 * @param L 何項目まで計算するか
 * @param primes L未満の素数リスト
 * @return Vec<T> H[i]=\sum_{lcm(j,k)=i}F[j]G[k]
 */
template <typename T> auto lcmConvolute(Vec<T> F, Vec<T> G, int L, Vec<int> primes) -> Vec<T> {
    F.resize(L), G.resize(L);
    auto nF = divisorsZeta(F, true, primes), nG = divisorsZeta(G, true, primes);
    for (int i : rep(L)) { nF[i] *= nG[i]; }
    return divisorsMoebius(nF, true, primes);
}
/**
 * @brief lcm畳み込み
 *
 * @param F F[0]==0
 * @param G G[0]==0
 * @param L 何項目まで計算するか
 * @return Vec<T> H[i]=\sum_{lcm(j,k)=i}F[j]G[k]
 */
template <typename T> auto lcmConvolute(Vec<T> F, Vec<T> G, int L) { return lcmConvolute(F, G, L, EratosthenesSieve{L}.primes()); }
