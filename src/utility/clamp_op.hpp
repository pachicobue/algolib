#pragma once
#include "../common.hpp"
/**
 * @brief 丸めこみ付き加算
 * 
 * @param x 
 * @param y 
 * @param min 
 * @param max 
 * @return i64 clamp(x+y,min,max)
 */
constexpr i64 clampAdd(i64 x, i64 y, i64 min, i64 max) { return std::ranges::clamp(x + y, min, max); }
/**
 * @brief 丸めこみ付き減算
 * 
 * @param x 
 * @param y 
 * @param min 
 * @param max 
 * @return i64 clamp(x-y,min,max)
 */
constexpr i64 clampSub(i64 x, i64 y, i64 min, i64 max) { return std::ranges::clamp(x - y, min, max); }
/**
 * @brief 丸めこみ付き乗算
 * 
 * @param x 
 * @param y 
 * @param min 
 * @param max 
 * @return i64 clamp(x*y,min,max)
 */
constexpr i64 clampMul(i64 x, i64 y, i64 min, i64 max)
{
    if (y < 0) { x = -x, y = -y; }
    const i64 xmin = ceilDiv(min, y), xmax = floorDiv(max, y);
    return (x < xmin) ? min : (x > xmax) ? max : x * y;
}
/**
 * @brief 丸めこみ付き
 * 
 * @param x 
 * @param y 
 * @param min 
 * @param max 
 * @return i64 clamp(x*y,min,max)
 */
constexpr i64 clampDiv(i64 x, i64 y, i64 min, i64 max) { return std::ranges::clamp(floorDiv(x, y), min, max); }
