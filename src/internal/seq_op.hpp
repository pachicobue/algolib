#pragma once
#include <algorithm>
#include <iterator>
#include <numeric>
#include <ranges>
#include <type_traits>
#include "abbreviation.hpp"
#include "type.hpp"
/**
 * @brief 数列の結合 (xs1+=xs2)
 *
 * @param xs1
 * @param xs2
 */
auto seqConcat(auto& xs1, const auto& xs2) -> void { std::ranges::copy(xs2, std::back_inserter(xs1)); }
/**
 * @brief 結合した数列
 *
 * @param xs1
 * @param xs2
 * @return auto xs1+xs2
 */
auto seqConcatCopy(const auto& xs1, const auto& xs2) {
    auto Ans = xs1;
    return seqConcat(Ans, xs2), Ans;
}
/**
 * @brief 数列の最小値のindex
 *
 * @param xs 数列
 * @param args
 * @return int 最小値のindex
 */
auto seqMinInd(const auto& xs, auto... args) -> int { return std::ranges::min_element(xs, args...) - std::ranges::begin(xs); }
/**
 * @brief 数列の最大値のindex
 *
 * @param xs 数列
 * @param args
 * @return int 最大値のindex
 */
auto seqMaxInd(const auto& xs, auto... args) -> int { return std::ranges::max_element(xs, args...) - std::ranges::begin(xs); }
/**
 * @brief 数列をreverseする
 *
 * @param xs 数列
 */
auto seqReverse(auto& xs) -> void { std::ranges::reverse(xs); }
/**
 * @brief 数列をソートする
 *
 * @param xs 数列
 */
auto seqSort(auto& xs, auto... args) -> void { std::ranges::sort(xs, args...); }
/**
 * @brief 関数の結果列
 *
 * @param N 結果列長
 * @param gen 値生成関数
 * @return Vec<T> genの結果を順に詰めた数列
 */
template <typename T> auto genVec(int N, auto gen) -> Vec<T> {
    Vec<T> ans;
    std::ranges::generate_n(std::back_inserter(ans), N, gen);
    return ans;
}
/**
 * @brief 公差1の等差数列
 *
 * @param N 数列長
 * @param offset 初項
 * @return Vec<T> {offset, offset+1, ..., offset+N-1}
 */
template <typename T = int> auto iotaVec(int N, T offset = 0) -> Vec<T> {
    Vec<T> ans(N);
    std::iota(std::ranges::begin(ans), std::ranges::end(ans), offset);
    return ans;
}
/**
 * @brief 連長圧縮
 *
 * @param xs 数列
 * @return auto {値,長さ}への圧縮結果
 */
auto seqRleVec(const auto& xs) {
    using T = std::remove_cvref_t<decltype(xs[0])>;
    Vec<Pair<T, int>> Ans;
    auto [l, px] = makePair(0, T{});
    for (const T& x : xs) {
        if (l == 0 or x != px) {
            if (l > 0) { Ans.push_back({px, l}); }
            l = 1, px = x;
        } else {
            l++;
        }
    }
    if (l > 0) { Ans.push_back({px, l}); }
    return Ans;
}
