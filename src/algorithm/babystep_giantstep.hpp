#pragma once
#include "../common.hpp"
#include "../utility/int_nthroot.hpp"

// f^n(x) = y となる最小のn
template<typename T, typename FW, typename FINV>
i64 babyStepGiantStep(FW f_wtimes, FINV f_inv, const T& x, const T& y, i64 N, i64 W = 0)
{
    if (W == 0) { W = intNthRoot(N, 2); }
    const i64 M = ceilDiv(N, W);
    Map<T, i64> memo;
    memo[x] = 0;
    T gx = x;
    for (i64 i : irange(1, M + 1)) {
        gx = f_wtimes(gx);
        if (memo.count(gx) == 0) { memo[gx] = i * W; }
    }

    i64 ans = INF<i64>;
    T sy = y;
    for (i64 w : rep(W)) {
        if (memo.count(sy)) { chmin(ans, memo[sy] + w); }
        sy = f_inv(sy);
    }
    return (ans == INF<i64> ? -1_i64 : ans);
}
