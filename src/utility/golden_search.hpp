#pragma once
#include <cassert>
#include <numbers>
#include "../internal.hpp"
/**
 * @brief 黄金探索 (離散)
 * @attention f(xsup)は評価されない
 *
 * @param xmin
 * @param xsup
 * @param f 関数
 * @return i64 f の極小値となる x (xmin <= x < xsup)
 */
constexpr auto goldenSearch(i64 xmin, i64 xsup, auto f) -> i64 {
    assert(xmin < xsup);
    auto comp = [&](i64 i, i64 j) {
        if (j >= xsup) { return true; }
        if (i < xmin) { return false; }
        return f(i) < f(j);
    };
    Vec<i64> Fs{1, 2}; // フィボナッチ数列
    while (Fs[Fs.size() - 1] + Fs[Fs.size() - 2] <= xsup - xmin + 1) { Fs.push_back(Fs[Fs.size() - 1] + Fs[Fs.size() - 2]); }

    i64 xl = xmin - 1, xr = xl + Fs.back();
    while (xr - xl > 2) {
        assert((xr - xl) == Fs.back());
        Fs.pop_back();
        const i64 yl = xr - Fs.back(), yr = xl + Fs.back();
        const i64 nxs[] = {xl, yl, yr, xr};
        const bool c = not comp(yl, yr);
        xl = nxs[(int)c], xr = nxs[(int)c + 2];
    }
    return xl + 1;
}
/**
 * @brief 黄金探索 (連続)
 *
 * @param xmin
 * @param xmax
 * @param f 関数
 * @param times 反復回数
 * @return f80 f の極小値となる x (xmin <= x <= xsup)  (近似値)
 */
constexpr auto goldenSearch(f80 xmin, f80 xmax, auto f, int times) -> f80 {
    assert(xmin <= xmax);
    f80 xl = xmin, xr = xmax;
    LOOP (times) {
        const f80 nW = (xr - xl) / std::numbers::phi_v<f80>;
        const f80 yl = xr - nW, yr = xl + nW;
        const f80 nxs[] = {xl, yl, yr, xr};
        const bool c = f(yl) > f(yr);
        xl = nxs[(int)c], xr = nxs[(int)c + 2];
    }
    return xl;
}
