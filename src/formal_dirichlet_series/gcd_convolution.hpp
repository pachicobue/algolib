#pragma once
#include "../common.hpp"
#include "divisors_moebius.hpp"
#include "divisors_zeta.hpp"
/**
 * @brief gcd畳み込み
 * 
 * @param f F[0] == 0
 * @param g G[0] == 0
 * @param primes N未満の素数リスト
 * @return Vec<T> Ans[i] = \sum_{gcd(j,k)=i}F[j]G[k]
 */
template<typename T> constexpr Vec<T> gcdConvolute(Vec<T> f, Vec<T> g, const Vec<int>& primes)
{
    const int L = (int)std::ranges::min(f.size(), g.size());
    f.resize(L), g.resize(L);
    auto F = divisorsZeta(f, false, primes), G = divisorsZeta(g, false, primes);
    for (int i : rep(L)) { F[i] *= G[i]; }
    return divisorsMoebius(F, false, primes);
}
/**
 * @brief gcd畳み込み
 * 
 * @param f F[0] == 0
 * @param g G[0] == 0
 * @return Vec<T> Ans[i] = \sum_{gcd(j,k)=i}F[j]G[k]
 */
template<typename T> constexpr Vec<T> gcdConvolute(const Vec<T>& f, const Vec<T>& g)
{
    const int L = (int)std::ranges::min(f.size(), g.size());
    return gcdConvolute(f, g, EratosthenesSieve{L}.primes());
}
