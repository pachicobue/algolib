#pragma once
#include <utility>
/**
 * @brief 不動点コンビネータ
 * @see https://yohhoy.hatenadiary.jp/entry/20211025/p1
 *      C++23 だと要らないらしい
 */
template <typename F> struct Fix : F {
    constexpr Fix(F &&f) : F{std::forward<F>(f)} {}
    template <typename... Args> constexpr auto operator()(Args &&...args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
