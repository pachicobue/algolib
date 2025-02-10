#pragma once
#include <algorithm>
#include <ranges>
/**
 * @brief ソート済み数列のlower_bound
 * @attention x以上の要素が存在しない場合は size(xs)
 *
 * @param xs ソート済み数列
 * @param x 値
 * @return int x以上となる最小のindex
 */
auto sortedLbInd(const auto& xs, const auto& x, auto... args) -> int {
    return std::ranges::lower_bound(xs, x, args...) - std::ranges::begin(xs);
}
/**
 * @brief ソート済み数列のupper_bound
 * @attention xを超える要素が存在しない場合は size(xs)
 *
 * @param xs ソート済み数列 (ソート済み)
 * @param x 値
 * @return int xを超える最小のindex
 */
auto sortedUbInd(const auto& xs, const auto& x, auto... args) -> int {
    return std::ranges::upper_bound(xs, x, args...) - std::ranges::begin(xs);
}
/**
 * @brief ソート済み数列の検索
 * @attention 一致する要素が存在しない場合は size(xs)
 *
 * @param xs 数列 (ソート済み)
 * @param x 値
 * @return int xと一致する最小のindex
 */
auto sortedFind(const auto& xs, const auto& x, auto... args) -> int {
    const int i = sortedLbInd(xs, x, args...);
    if (i < std::ranges::ssize(xs) and xs[i] == x) {
        return i;
    }
    return std::ranges::ssize(xs);
}
