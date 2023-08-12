#pragma once
#include "type.hpp"
/**
 * @brief std::abs相当のconstexpr関数
 * @note C++20では整数の std::abs がconstexprで使えないので自作
 *       C++23から不要になるらしい
 * 
 * @param x 
 * @return auto |x|
 */
constexpr auto ABS(auto x) { return (x >= 0 ? x : -x); }
