#pragma once
#include "../common.hpp"
/**
 * @brief N次元Vector
 * @note ndVec<T>({2,3,4},100) = Vec<Vec<Vec<T>>>(2, Vec<Vec<T>>(3, Vec<T>(4, 100)))
 * 
 * @param sizes 各次元のサイズ
 * @param x 初期値
 * @return auto N次元Vector
 */
template<typename T, int n, int i = 0> auto ndVec(int const (&sizes)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(sizes[i], ndVec<T, n, i + 1>(sizes, x));
    }
}
