#pragma once
#include "type.hpp"
template<typename T>
constexpr T floorDiv(T x, T y)
{
    assert(y != 0);
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T ceilDiv(T x, T y)
{
    assert(y != 0);
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
