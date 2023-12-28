#pragma once
#include "type.hpp"
#include "constant.hpp"
/**
 * @brief モノイドの累乗(乗算演算指定)
 * @note 半群の場合も使える(N>=1)
 *       その場合は単位元はテキトーでいい
 *
 * @tparam T モノイド
 * @param x 
 * @param N 指数(N>=0)
 * @param e 単位元
 * @param mul 乗算
 * @return T x^N
 */
template<typename T> constexpr auto powerMonoid(const T& x, i64 N, const T& e, auto mul) -> T
{
    assert(N >= 0);
    if (N == 0) { return e; }
    if (N == 1) { return x; }
    return (N % 2 == 1 ? mul(x, powerMonoid(x, N - 1, e, mul)) : powerMonoid(mul(x, x), N / 2, e, mul));
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
template<typename T> constexpr auto powerMonoid(const T& x, i64 N, const T& e) -> T { return powerMonoid(x, N, e, std::multiplies<T>{}); }
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
template<typename T> constexpr auto powerInt(const T& x, i64 N) -> T { return powerMonoid(x, N, T{1}); }
/**
 * @brief 整数の累乗(Mod)
 * 
 * @param x 
 * @param N 
 * @param M
 * @return u64 x^N (mod M)
 */
constexpr auto powerMod(u64 x, i64 N, u64 mod) -> u64
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
