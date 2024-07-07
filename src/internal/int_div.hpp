#pragma once
#include <cassert>
#include "type.hpp"
/**
 * @brief floor(x/y)
 *
 * @param x
 * @param y
 * @return i64 floor(x/y)
 */
constexpr auto floorDiv(i64 x, i64 y) -> i64 {
    assert(y != 0);
    if (y < 0) { x = -x, y = -y; }
    return x >= 0 ? x / y : (x - y + 1) / y;
}
/**
 * @brief ceil(x/y)
 *
 * @param x
 * @param y
 * @return i64 ceil(x/y)
 */
constexpr auto ceilDiv(i64 x, i64 y) -> i64 {
    assert(y != 0);
    if (y < 0) { x = -x, y = -y; }
    return x >= 0 ? (x + y - 1) / y : x / y;
}
