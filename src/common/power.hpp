#pragma once
#include "type.hpp"
template<typename T, typename I>
constexpr T powerMonoid(T v, I n, const T& e)
{
    assert(n >= 0);
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T powerInt(T v, I n)
{
    return powerMonoid(v, n, 1);
}
