#pragma once
#include "type.hpp"
/**
 * @brief std::make_pair のラッパー
 * 
 * @param x1 
 * @param x2 
 * @return auto {v1,v2}
 */
auto makePair(const auto& x1, const auto& x2) { return std::make_pair(x1, x2); }
/**
 * @brief std::make_tuple のラッパー
 * 
 * @param xs 
 * @return auto {xs...}
 */
auto makeTup(const auto&... xs) { return std::make_tuple(xs...); }
