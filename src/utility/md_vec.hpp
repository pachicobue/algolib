#pragma once
#include "../common.hpp"
/**
 * @brief 多次元Vector
 * @note mdVec<T>({2,3,4},100) = Vec<Vec<Vec<T>>>(2, Vec<Vec<T>>(3, Vec<T>(4, 100)))
 * 
 * @param sizes 各次元のサイズ
 * @param x 初期値
 * @return auto 多次元Vector
 */
template<typename T, int n, int i = 0> auto mdVec(int const (&sizes)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(sizes[i], mdVec<T, n, i + 1>(sizes, x));
    }
}
