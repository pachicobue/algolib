#pragma once
#include "type.hpp"
#include "constant.hpp"
/**
 * @brief 半群の累乗
 * 
 * @tparam T 半群
 * @param x 
 * @param N 指数(N>=1)
 * @param mul 乗算
 * @return T x^N
 */
template<typename T> constexpr T powerSemiGroup(const T& x, i64 N, auto mul)
{
    assert(N > 0);
    if (N == 1) { return x; }
    return (N % 2 == 1 ? mul(x, powerSemiGroup(x, N - 1, mul)) : powerSemiGroup(mul(x, x), N / 2, mul));
}
/**
 * @brief 半群の累乗
 * 
 * @tparam T 半群
 * @param x 
 * @param N 指数(N>=1)
 * @return T x^N
 */
template<typename T> constexpr T powerSemiGroup(const T& x, i64 N) { return powerSemiGroup(x, N, std::multiplies<T>{}); }
/**
 * @brief モノイドの累乗
 * 
 * @tparam T モノイド
 * @param x 
 * @param N 指数(N>=0)
 * @param e 単位元
 * @param mul 乗算
 * @return T x^N
 */
template<typename T> constexpr T powerMonoid(const T& x, i64 N, const T& e, auto mul)
{
    assert(N >= 0);
    return (N == 0 ? e : powerSemiGroup(x, N, mul));
}
/**
 * @brief モノイドの累乗
 * 
 * @tparam T モノイド
 * @param x 
 * @param N 指数(N>=0)
 * @param e 単位元
 * @return T x^N
 */
template<typename T> constexpr T powerMonoid(const T& x, i64 N, const T& e) { return powerMonoid(x, N, e, std::multiplies<T>{}); }
/**
 * @brief 整数の累乗
 * @attention オーバーフローのケアはしていないので注意
 * 
 * @tparam T 整数型 (modintとかも可)
 * @param x 
 * @param N 指数(N>=0)
 * @param e 単位元
 * @return T x^N
 */
template<typename T> constexpr T powerInt(const T& x, i64 N) { return powerMonoid(x, N, T{1}); }
/**
 * @brief 整数の累乗(Mod)
 * 
 * @param x 
 * @param N 
 * @param M
 * @return T x^N (mod M)
 */
constexpr u64 powerMod(u64 x, i64 N, u64 mod)
{
    assert(0 < mod);
    return powerMonoid(x, N, u64{1}, [&](u64 x, u64 y) {
        if (mod <= (u64)LIMMAX<u32>) {
            return x * y % mod;
        } else {
            return (u64)((u128)x * y % mod);
        }
    });
}
