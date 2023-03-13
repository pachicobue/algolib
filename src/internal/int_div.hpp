#pragma once
#include "type.hpp"
template<typename T>
constexpr T floorDiv(T x, T y)
{
    assert(y != 0);
    if (y < 0) { x = -x, y = -y; }
    return x >= 0 ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T ceilDiv(T x, T y)
{
    assert(y != 0);
    if (y < 0) { x = -x, y = -y; }
    return x >= 0 ? (x + y - 1) / y : x / y;
}
