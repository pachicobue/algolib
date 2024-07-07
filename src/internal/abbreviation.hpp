#pragma once
#include <tuple>
#include <utility>
/**
 * @brief std::make_pair のラッパー
 *
 * @param x1
 * @param x2
 * @return auto {v1,v2}
 */
constexpr auto makePair(const auto &x1, const auto &x2) { return std::make_pair(x1, x2); }
/**
 * @brief std::make_tuple のラッパー
 *
 * @param xs
 * @return auto {xs...}
 */
constexpr auto makeTup(const auto &...xs) { return std::make_tuple(xs...); }
