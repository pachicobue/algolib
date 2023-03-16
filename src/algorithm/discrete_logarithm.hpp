#pragma once
#include "../common.hpp"
#include "../utility/int_nthroot.hpp"
#include "../number/prime_factors.hpp"

template<typename F, typename FPOW>
i64 discreteLogarithm(i64 N, F f, FPOW f_pow, i64 x, i64 y)
{
    const i64 W = intNthRoot(N, 2);
    const i64 M = ceilDiv(N, W);

    UMap<i64, i64> gs;
    i64 X = x;
    gs[X] = 0;
    for (i64 i : irange(1, M + 1)) {
        X = f_pow(W, X);
        gs[X] = i * W;
    }

    i64 IW = -1, J = -1;
    i64 Y = y;
    for (i64 j : rep(W)) {
        if (gs.count(Y)) {
            const i64 iw = gs.at(Y);
            IW = iw, J = j;
            break;
        }
        Y = f(Y);
    }
    if (IW == -1 and J == -1) { return -1; }

    i64 C = -1;
    {
        i64 Z = X;
        for (i64 j : irange(1, W + 1)) {
            Z = f(Z);
            if (gs.count(Z)) {
                const i64 iw = gs.at(Z);
                C = (W * M + j) - iw;
                break;
            }
        }
        assert(C > 0);
        const auto fs = primeFactors(C);
        for (const auto& [p, e] : fs) {
            Vec<i64> ps(e + 1, 1);
            for (int i : rep(e)) { ps[i + 1] = ps[i] * p; }
            const i64 Q = C / ps[e];
            const int d = binSearch(-1, e, [&](int d) {
                const i64 nC = Q * ps[d];
                return (f_pow(nC, X) == X);
            });
            C = Q * ps[d];
        }
    }

    const i64 maxM = floorDiv(IW, C);
    const i64 m = binSearch(maxM + 1, 0_i64, [&](int m) {
        const i64 iw = IW - C * m;
        return f_pow(iw, x) == Y;
    });
    IW -= C * m;
    const i64 K = IW - J;
    i64 ans = INF<i64>;
    if (K >= 0) {
        if (f_pow(K, x) == y) { chmin(ans, K); }
    }
    if (K + C >= 0) {
        if (f_pow(K + C, x) == y) { chmin(ans, K + C); }
    }
    return (ans == INF<i64> ? -1_i64 : ans);
}
