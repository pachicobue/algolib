#pragma once
#include "type.hpp"
template<typename T>
constexpr T LIMMIN = std::numeric_limits<T>::min();
template<typename T>
constexpr T LIMMAX = std::numeric_limits<T>::max();
template<typename T>
constexpr T INF = (LIMMAX<T> - 1) / 2;
template<typename T>
constexpr T PI = T{3.141592653589793238462643383279502884};
template<typename T = u64>
constexpr T TEN(int n)
{
    return n == 0 ? T{1} : TEN<T>(n - 1) * T{10};
}
