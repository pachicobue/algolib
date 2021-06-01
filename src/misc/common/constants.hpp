#pragma once
#include "type_alias.hpp"
template<typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template<typename T>
constexpr T PI = T{3.141592653589793238462643383279502884};
template<typename T = u64>
constexpr T TEN(const int n)
{
    return n == 0 ? T{1} : TEN<T>(n - 1) * T{10};
}
