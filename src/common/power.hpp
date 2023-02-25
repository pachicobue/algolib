#pragma once
#include "type.hpp"
template<typename T, typename I>
constexpr T powerMonoid(T v, I n, const T& e)
{
    assert(n >= 0);
    if (n == 0) { return e; }
    return (n % 2 == 1 ? v * powerMonoid(v, n - 1, e) : powerMonoid(v * v, n / 2, e));
}
template<typename T, typename I>
constexpr T powerInt(T v, I n)
{
    return powerMonoid(v, n, T{1});
}
