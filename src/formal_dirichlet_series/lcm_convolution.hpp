#pragma once
#include "../common.hpp"
#include "divisors_moebius.hpp"
#include "divisors_zeta.hpp"
/**
 * @brief lcm畳み込み
 * 
 * @param f F[0] == 0
 * @param g G[0] == 0
 * @param L 何項目まで計算するか
 * @param primes L未満の素数リスト
 * @return Vec<T> Ans[i] = \sum_{gcd(j,k)=i}F[j]G[k]
 */
template<typename T> constexpr Vec<T> lcmConvolute(Vec<T> f, Vec<T> g, int L, Vec<int> primes)
{
    f.resize(L), g.resize(L);
    auto F = divisorsZeta(f, true, primes), G = divisorsZeta(g, true, primes);
    for (int i : rep(L)) { F[i] *= G[i]; }
    return divisorsMoebius(F, true, primes);
}
/**
 * @brief lcm畳み込み
 * 
 * @param f F[0] == 0
 * @param g G[0] == 0
 * @param L 何項目まで計算するか
 * @return Vec<T> Ans[i] = \sum_{gcd(j,k)=i}F[j]G[k]
 */
template<typename T> constexpr Vec<T> lcmConvolute(Vec<T> f, Vec<T> g, int L)
{
    return lcmConvolute(f, g, L, EratosthenesSieve{L}.primes());
}
