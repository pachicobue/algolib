#pragma once
#include "type.hpp"
/**
 * @brief 数列の総和
 * 
 * @param xs 数列
 * @return auto 総和
 */
constexpr auto sumAll(const auto& xs) { return std::accumulate(std::begin(xs), std::end(xs), decltype(xs[0]){}); }
/**
 * @brief ソート済み数列のlower_bound
 * @attention x以上の要素が存在しない場合は size(xs)
 * 
 * @param xs 数列 (ソート済み)
 * @param x 値
 * @return int x以上となる最小のindex
 */
constexpr int lbInd(const auto& xs, const auto& x) { return std::ranges::lower_bound(xs, x) - std::begin(xs); }
/**
 * @brief ソート済み数列のupper_bound
 * @attention xを超える要素が存在しない場合は size(xs)
 * 
 * @param xs 数列 (ソート済み)
 * @param x 値
 * @return int xを超える最小のindex
 */
constexpr int ubInd(const auto& xs, const auto& x) { return std::ranges::upper_bound(xs, x) - std::begin(xs); }
/**
 * @brief ソート済み数列の検索
 * @attention 一致する要素が存在しない場合は size(xs)
 * 
 * @param xs 数列 (ソート済み)
 * @param x 値
 * @return int xと一致する最小のindex
 */
constexpr int find(const auto& xs, const auto& x)
{
    const int i = lbInd(xs, x);
    if (i < std::ssize(xs) and xs[i] == x) { return i; }
    return std::ssize(xs);
}
/**
 * @brief 数列の結合 (xs1+=xs2)
 * 
 * @param xs1
 * @param xs2 
 */
void concat(auto& xs1, const auto& xs2) { std::ranges::copy(xs2, std::back_inserter(xs1)); }
/**
 * @brief 結合した数列
 * 
 * @param xs1
 * @param xs2
 * @return auto xs1+xs2
 */
auto concatCopy(const auto& xs1, const auto& xs2)
{
    auto Ans = xs1;
    return concat(Ans, xs2), Ans;
}
/**
 * @brief 多次元fill
 * @note 多次元配列でも全部fillする
 * 
 * @param arr fillしたい数列
 * @param x 値
 */
template<typename Ts, typename T> constexpr void fillAll(Ts& arr, const T& x)
{
    if constexpr (std::is_convertible<T, Ts>::value) {
        arr = x;
    } else {
        for (auto& subarr : arr) { fillAll(subarr, x); }
    }
}
/**
 * @brief 関数の結果列
 * 
 * @param N 結果列長
 * @param gen 値生成関数
 * @return Vec<T> genの結果を順に詰めた数列
 */
template<typename T> Vec<T> genVec(int N, auto gen)
{
    Vec<T> ans;
    std::ranges::generate_n(std::back_inserter(ans), N, gen);
    return ans;
}
/**
 * @brief 数列の最小値
 * 
 * @param xs 数列
 * @param args
 * @return auto 最小値
 */
constexpr auto minAll(const auto& xs, auto... args) { return std::ranges::min(xs, args...); }
/**
 * @brief 数列の最大値
 * 
 * @param xs 数列
 * @param args
 * @return auto 最大値
 */
constexpr auto maxAll(const auto& xs, auto... args) { return std::ranges::max(xs, args...); }
/**
 * @brief 数列の最小値のindex
 * 
 * @param xs 数列
 * @param args
 * @return int 最小値のindex
 */
constexpr int minInd(const auto& xs, auto... args) { return std::ranges::min_element(xs, args...) - std::begin(xs); }
/**
 * @brief 数列の最大値のindex
 * 
 * @param xs 数列
 * @param args
 * @return int 最大値のindex
 */
constexpr int maxInd(const auto& xs, auto... args) { return std::ranges::max_element(xs, args...) - std::begin(xs); }
/**
 * @brief 公差1の等差数列
 * 
 * @param N 数列長
 * @param offset 初項
 * @return Vec<T> {offset, offset+1, ..., offset+N-1}
 */
template<typename T = int> Vec<T> iotaVec(int N, T offset = 0)
{
    Vec<T> ans(N);
    std::iota(std::begin(ans), std::end(ans), offset);
    return ans;
}
/**
 * @brief 数列全体に一様加算
 * 
 * @param xs 数列
 * @param x 加算する値
 */
constexpr void plusAll(auto& xs, const auto& x)
{
    std::ranges::for_each(xs, [&](auto& e) { e += x; });
}
/**
 * @brief 数列をreverseする
 * 
 * @param xs 数列
 */
constexpr void reverseAll(auto& xs) { std::ranges::reverse(xs); }
/**
 * @brief 数列をソートする
 * 
 * @param xs 数列
 */
constexpr void sortAll(auto& xs, auto... args) { std::ranges::sort(xs, args...); }
/**
 * @brief 連長圧縮
 * 
 * @param xs 数列
 * @return auto {値,長さ}への圧縮結果
 */
auto runLengthEncode(const auto& xs)
{
    using T = typename std::decay<decltype(xs[0])>::type;
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
