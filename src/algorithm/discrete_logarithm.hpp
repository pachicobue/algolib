#pragma once
#include "../common.hpp"
#include "../utility/int_nthroot.hpp"
#include "../internal/power.hpp"
/**
 * @brief f^n(x)=y となる最小の n
 * @see https://maspypy.com/モノイド作用に関する離散対数問題
 *
 * @param N 答えの上限 (0 <= n < N)
 * @param x スタート
 * @param y ゴール
 * @param f 作用素
 * @param compose 作用素の合成(半群)
 * @param act 作用
 * @return i64 最小解(解なしの場合は N)
 */
template<typename T, typename F> i64 discreteLogarithm(i64 N, T x, T y, F f, auto compose, auto act)
{
    assert(N >= 0);
    if (N == 0) { return (x == y ? 0 : -1); }
    const i64 W = (i64)intSqrt(N);
    const i64 M = ceilDiv(N, W);

    UMap<T, u64> Ys;
    for (T Y = y; i64 i : rep(M + 1)) { Ys[Y] = i, Y = act(f, Y); }

    const F fW = powerSemiGroup(f, W, compose);
    for (auto [X, failed] = makePair(x, 0); i64 k : irange(1, M + 1)) {
        T pX = X;
        X    = act(fW, X);
        if (not Ys.contains(X)) { continue; }
        for (i64 n : irange((k - 1) * W, k * W)) {
            if (pX == y) { return n; }
            pX = act(f, pX);
        }
        failed++;
        if (failed == 2) { return -1; }
    }
    return -1;
}
