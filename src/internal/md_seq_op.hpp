#pragma once
#include "type.hpp"
/**
 * @brief 多次元数列への作用
 * 
 * @param xs 多次元数列
 * @param f 作用関数
 */
void mdSeqAct(auto& xs, auto f)
{
    if constexpr (requires(const decltype(xs) xs) { std::begin(xs); }) {
        for (auto& x : xs) { mdSeqAct(x, f); }
    } else {
        f(xs);
    }
}
/**
 * @brief 多次元数列の二項演算での総積
 * 
 * @param xs 多次元数列
 * @param op 二項演算
 * @return auto 総積
 */
[[nodiscard]] auto mdSeqFold(const auto& xs, auto op)
{
    if constexpr (requires(const decltype(xs) xs) { std::begin(xs); }) {
        assert(std::size(xs) > 0);
        auto ans = mdSeqFold(xs[0], op);
        for (int i = 1; i < std::ssize(xs); i++) { ans = op(ans, mdSeqFold(xs[i], op)); }
        return ans;
    } else {
        return xs;
    }
}
/**
 * @brief 多次元数列のFill
 * 
 * @param xs 多次元数列
 * @param x Fillする値
 */
void mdSeqFill(auto& xs, auto x)
{
    mdSeqAct(xs, [&x](auto& v) { v = x; });
}
/**
 * @brief 多次元数列に一様加算
 * 
 * @param xs 多次元数列
 * @param x 加算する値
 */
void mdSeqPlus(auto& xs, auto x)
{
    mdSeqAct(xs, [&x](auto& v) { v += x; });
}
/**
 * @brief 多次元数列のSum
 * 
 * @param xs 多次元数列
 * @return 総和
 */
auto mdSeqSum(const auto& xs)
{
    return mdSeqFold(xs, [](auto x, auto y) { return x + y; });
}
/**
 * @brief 多次元数列のMin
 * 
 * @param xs 多次元数列
 * @return 総和
 */
auto mdSeqMin(const auto& xs, auto... args)
{
    return mdSeqFold(xs, [&args...](auto x, auto y) { return std::ranges::min(x, y, args...); });
}
/**
 * @brief 多次元数列のMin
 * 
 * @param xs 多次元数列
 * @return 総和
 */
auto mdSeqMax(const auto& xs, auto... args)
{
    return mdSeqFold(xs, [&args...](auto x, auto y) { return std::ranges::max(x, y, args...); });
}
