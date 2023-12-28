#pragma once
#include "type.hpp"
/**
 * @brief std::numeric_limits::min のラッパー
 */
template<typename T> constexpr T LIMMIN = std::numeric_limits<T>::min();
/**
 * @brief std::numeric_limits::max のラッパー
 */
template<typename T> constexpr T LIMMAX = std::numeric_limits<T>::max();
/**
 * @brief ∞として扱う定数
 * @attention INF+INF がオーバーフローしないような設定
 */
template<typename T> constexpr T INF = (LIMMAX<T> - 1) / 2;
/**
 * @brief 10^N
 * 
 * @param N 指数
 * @return T 10^N
 */
template<typename T = i64> constexpr auto TEN(int N) -> T { return N == 0 ? T{1} : TEN<T>(N - 1) * T{10}; }
