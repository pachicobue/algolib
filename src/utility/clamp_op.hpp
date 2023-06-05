#pragma once
#include "../common.hpp"

template<typename T>
constexpr T clampAdd(T x, T y, T min, T max)
{
    return std::clamp(x + y, min, max);
}
template<typename T>
constexpr T clampSub(T x, T y, T min, T max)
{
    return std::clamp(x - y, min, max);
}
template<typename T>
constexpr T clampMul(T x, T y, T min, T max)
{
    if (y < 0) { x = -x, y = -y; }
    const T xmin = ceilDiv(min, y);
    const T xmax = floorDiv(max, y);
    if (x < xmin) {
        return min;
    } else if (x > xmax) {
        return max;
    } else {
        return x * y;
    }
}
template<typename T>
constexpr T clampDiv(T x, T y, T min, T max)
{
    return std::clamp(floorDiv(x, y), min, max);
}
