#pragma once
#include <algorithm>
/**
 * @brief 定数関数
 * @note マクロなしだとステートレスにできなくて非型テンプレート引数に渡せない
 */
#define FConst(...) []() { return (__VA_ARGS__); }

/**
 * @brief 最小値関数
 */
template <typename T> struct FMin {
    constexpr FMin() = default;
    constexpr auto operator()(const T &x, const T &y) const -> const T & { return std::ranges::min(x, y); }
};

/**
 * @brief 最大値関数
 */
template <typename T> struct FMax {
    constexpr FMax() = default;
    constexpr auto operator()(const T &x, const T &y) const -> const T & { return std::ranges::max(x, y); }
};

/**
 * @brief 加算関数
 */
template <typename T> struct FSum {
    constexpr FSum() = default;
    constexpr auto operator()(const T &x, const T &y) const -> const T & { return x + y; }
};
