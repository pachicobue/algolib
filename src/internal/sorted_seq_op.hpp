#pragma once
#include "type.hpp"
/**
 * @brief ソート済み数列のlower_bound
 * @attention x以上の要素が存在しない場合は size(xs)
 * 
 * @param xs ソート済み数列
 * @param x 値
 * @return int x以上となる最小のindex
 */
int sortedLbInd(const auto& xs, const auto& x, auto... args) { return std::ranges::lower_bound(xs, x, args...) - std::begin(xs); }
/**
 * @brief ソート済み数列のupper_bound
 * @attention xを超える要素が存在しない場合は size(xs)
 * 
 * @param xs ソート済み数列 (ソート済み)
 * @param x 値
 * @return int xを超える最小のindex
 */
int sortedUbInd(const auto& xs, const auto& x, auto... args) { return std::ranges::upper_bound(xs, x, args...) - std::begin(xs); }
/**
 * @brief ソート済み数列の検索
 * @attention 一致する要素が存在しない場合は size(xs)
 * 
 * @param xs 数列 (ソート済み)
 * @param x 値
 * @return int xと一致する最小のindex
 */
int sortedFind(const auto& xs, const auto& x, auto... args)
{
    const int i = sortedLbInd(xs, x, args...);
    if (i < std::ssize(xs) and xs[i] == x) { return i; }
    return std::ssize(xs);
}
